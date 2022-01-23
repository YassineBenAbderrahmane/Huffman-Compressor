#include <CUnit/Basic.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ArbreDeHuffman.h"
#include "Statistiques.h"
#include "fileDePriorite.h"
#include "octet.h"
#include "CodeBinaire.h"
#include "TableDeCodage.h"
#define TRUE 1
#define FALSE 0

int init_suite_success(void) {
    return 0;
}

int clean_suite_success(void) {
    return 0;
}

void test_stats_vide(void) {
    Statistiques *stats;
    stats = S_statistiques();

    CU_ASSERT_TRUE(S_nbElements(*stats) == 0);

    S_supprimer(stats);
}

void test_stats_ajout(void) {
    Statistiques *stats;
    Octet o;
    stats = S_statistiques();
    o = O_creerOctet();

    O_ecrireIemeBit(&o, 2, 1);
    S_ajouterOctet(stats, o, 1);
    CU_ASSERT_TRUE(S_obtenirOccurence(*stats, o) == 1);
    CU_ASSERT_TRUE(S_nbElements(*stats) == 1);

    S_supprimer(stats);
}

void test_stats_clefs(void) {
    //Exemple de test
    Statistiques *stats;
    Octet o1, o2;
    Octet *pO = malloc(256 * sizeof(Octet));
    unsigned int nb;
    stats = S_statistiques();

    S_obtenirClefs(*stats, pO, &nb);
    CU_ASSERT_TRUE(nb == 0);

    o1 = O_creerOctet();
    O_ecrireIemeBit(&o1, 2, bitA1);
    S_ajouterOctet(stats, o1, 1);

    S_obtenirClefs(*stats, pO, &nb);
    CU_ASSERT_TRUE(nb == 1);
    CU_ASSERT_TRUE(O_sontEgaux(pO[0], o1));

    o2 = O_creerOctet();
    O_ecrireIemeBit(&o2, 8, bitA1);
    S_ajouterOctet(stats, o2, 5);

    S_obtenirClefs(*stats, pO, &nb);
    CU_ASSERT_TRUE(nb == 2);
    CU_ASSERT_TRUE(O_sontEgaux(pO[0], o1));
    CU_ASSERT_TRUE(O_sontEgaux(pO[1], o2));
    free(pO);
    S_supprimer(stats);
}

void test_octet_vide(void) {
    Octet o1;
    o1 = O_creerOctet();

    CU_ASSERT_TRUE(O_octetEnNaturel(o1) == 0);
}

void test_octet_ecrire(void) {
    Octet o1;

    o1 = O_creerOctet();
    O_ecrireIemeBit(&o1, 1, bitA1);
    CU_ASSERT_TRUE(O_octetEnNaturel(o1) == 1);

    O_ecrireIemeBit(&o1, 1, bitA0);
    O_ecrireIemeBit(&o1, 8, bitA1);
    O_ecrireIemeBit(&o1, 6, bitA1);
    CU_ASSERT_TRUE(O_octetEnNaturel(o1) == 160);
}

void test_octet_egaux(void) {
    Octet o1, o2;

    o1 = O_creerOctet();
    o2 = O_creerOctet();

    O_ecrireIemeBit(&o1, 1, bitA1);
    O_ecrireIemeBit(&o2, 5, bitA1);
    CU_ASSERT_FALSE(O_sontEgaux(o1, o2));

    O_ecrireIemeBit(&o1, 1, bitA0);
    O_ecrireIemeBit(&o1, 5, bitA1);
    CU_ASSERT_TRUE(O_sontEgaux(o1, o2));
}

void test_fdp_vide(void) {
    FileDePriorite fdp;
    fdp = FDP_creerFile();

    CU_ASSERT_TRUE(FDP_estVide(fdp));
}

void test_fdp_enfiler(void) {
    FileDePriorite fdp;
    ArbreDeHuffman a;
    fdp = FDP_creerFile();
    a = ADH_creerArbreDeHuffman();

    FDP_enfiler(&fdp, a);

    CU_ASSERT_TRUE(FDP_obtenirArbre(fdp) == a);

    FDP_defiler(&fdp);
    ADH_supprimer(a);
}

void test_fdp_defiler(void) {
    FileDePriorite fdp;
    ArbreDeHuffman a;
    fdp = FDP_creerFile();
    a = ADH_creerArbreDeHuffman();

    FDP_enfiler(&fdp, a);
    FDP_defiler(&fdp);

    CU_ASSERT_TRUE(FDP_estVide(fdp));

    ADH_supprimer(a);
}

void test_cb_vide(void){
	CodeBinaire code;
	code = CB_creerCodeBinaire();

	CU_ASSERT_TRUE(CB_longueur(code) == 0);
}

void test_cb_ajouter(void){
	CodeBinaire code;
	code = CB_creerCodeBinaire();

	CB_ajouterBit(&code, bitA0);
	CB_ajouterBit(&code, bitA1);
    CB_ajouterBit(&code, bitA1);

	CU_ASSERT_TRUE(CB_iemeBit(code, 1) == bitA0);
	CU_ASSERT_TRUE(CB_iemeBit(code, 2) == bitA1);
    CU_ASSERT_TRUE(CB_iemeBit(code, 3) == bitA1);
	CU_ASSERT_TRUE(CB_longueur(code) == 3);
}

void test_cb_modifier(void){
	CodeBinaire code;
	code = CB_creerCodeBinaire();

	CB_ajouterBit(&code, bitA0);
	CB_ajouterBit(&code, bitA1);
    CB_ajouterBit(&code, bitA1);

    CB_modifierIemeBit(&code, 2, bitA0);
	CU_ASSERT_TRUE(CB_iemeBit(code, 1) == bitA0);
	CU_ASSERT_TRUE(CB_iemeBit(code, 2) == bitA0);
    CU_ASSERT_TRUE(CB_iemeBit(code, 3) == bitA1);
	CU_ASSERT_TRUE(CB_longueur(code) == 3);
}

void test_cb_egaux(void){
	CodeBinaire code1, code2;
	code1 = CB_creerCodeBinaire();
	code2 = CB_creerCodeBinaire();

	CB_ajouterBit(&code1, bitA0);
	CB_ajouterBit(&code1, bitA1);

	CB_ajouterBit(&code2, bitA0);
	CB_ajouterBit(&code2, bitA1);

	CU_ASSERT_TRUE(CB_sontEgaux(code1, code2));
}

void test_cb_enOctet(void){
	CodeBinaire code;
	code = CB_creerCodeBinaire();

	CB_ajouterBit(&code, bitA0);
	CB_ajouterBit(&code, bitA1);
    CB_ajouterBit(&code, bitA1);
    //Code: 011..... => On veut octet 10100000 cad 64+32=96

	CU_ASSERT_TRUE(O_octetEnNaturel(CB_codeBinaireEnOctet(code)) == 96);
}

void test_tdc_vide(void){
	TableDeCodage *tdc;
	tdc = TDC_creerTableDeCodage();

	CU_ASSERT_TRUE(TDC_estVide(*tdc));
	CU_ASSERT_TRUE(TDC_nbOctets(*tdc) == 0);

    TDC_supprimer(tdc);
}

void test_tdc_ajouter(void){
	TableDeCodage *tdc;
	Octet o ;
	CodeBinaire cb, cbRecup;
	tdc = TDC_creerTableDeCodage();

	o = O_creerOctet();
	O_ecrireIemeBit(&o, 2, bitA1);
    O_ecrireIemeBit(&o, 5, bitA1);
    O_ecrireIemeBit(&o, 7, bitA1);
    //Octet: 01010010


	cb = CB_creerCodeBinaire();
	CB_ajouterBit(&cb, bitA0);
    CB_ajouterBit(&cb, bitA1);
    CB_ajouterBit(&cb, bitA1);
    //CB: 011.....

	TDC_ajouterOctet(tdc, o, cb);

	CU_ASSERT_FALSE(TDC_estVide(*tdc));
	CU_ASSERT_TRUE(TDC_octetPresent(*tdc, o));

    cbRecup = TDC_recupererCodeBinaire(*tdc, o);

	CU_ASSERT_TRUE(CB_sontEgaux(cbRecup, cb));
    CU_ASSERT_TRUE(CB_iemeBit(cbRecup, 1) == bitA0);
    CU_ASSERT_TRUE(CB_iemeBit(cbRecup, 2) == bitA1);
    CU_ASSERT_TRUE(CB_iemeBit(cbRecup, 3) == bitA1);
	CU_ASSERT_TRUE(CB_longueur(cbRecup) == 3);

    TDC_supprimer(tdc);
}

void test_tdc_supprimer(void){
    TableDeCodage *tdc;
    Octet o ;
    CodeBinaire cb;
    tdc = TDC_creerTableDeCodage();

    o = O_creerOctet();
    O_ecrireIemeBit(&o, 2, bitA1);
    O_ecrireIemeBit(&o, 5, bitA1);
    O_ecrireIemeBit(&o, 7, bitA1);
    //Octet: 01010010


    cb = CB_creerCodeBinaire();
    CB_ajouterBit(&cb, bitA0);
    CB_ajouterBit(&cb, bitA1);
    CB_ajouterBit(&cb, bitA1);
    //CB: 011.....

    TDC_ajouterOctet(tdc, o, cb);	//On ajoute un octet pour verifier sa suppression après
    TDC_supprimerOctet(tdc,o);
    CU_ASSERT_FALSE(TDC_octetPresent(*tdc,o));

    TDC_supprimer(tdc);
}

int main(int argc, char **argv) {
    CU_pSuite pSuiteStats, pSuiteOctet, pSuiteFDP, pSuiteCB, pSuiteTDC;
	
	 /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* ajout d'une suite de test */
    pSuiteStats = CU_add_suite("Statistiques", init_suite_success, clean_suite_success);
    if (NULL == pSuiteStats) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    pSuiteOctet = CU_add_suite("Octet", init_suite_success, clean_suite_success);
    if (NULL == pSuiteOctet) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    pSuiteFDP = CU_add_suite("File de priorité", init_suite_success, clean_suite_success);
    if (NULL == pSuiteFDP) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    pSuiteCB = CU_add_suite("Code Binaire", init_suite_success, clean_suite_success);
    if (NULL == pSuiteCB) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    pSuiteTDC = CU_add_suite("Table de Codage", init_suite_success, clean_suite_success);
    if (NULL == pSuiteTDC) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Ajout des tests à la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuiteStats, "Test vide :", test_stats_vide)) || (NULL == CU_add_test(pSuiteStats, "Test ajout :", test_stats_ajout)) || (NULL == CU_add_test(pSuiteStats, "Test clefs :", test_stats_clefs))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuiteOctet, "Test vide :", test_octet_vide)) || (NULL == CU_add_test(pSuiteOctet, "Test ecrire :", test_octet_ecrire))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuiteFDP, "Test vide :", test_fdp_vide)) || (NULL == CU_add_test(pSuiteFDP, "Test enfiler :", test_fdp_enfiler)) || (NULL == CU_add_test(pSuiteFDP, "Test defiler :", test_fdp_defiler))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuiteCB, "Test vide :", test_cb_vide))
        || (NULL == CU_add_test(pSuiteCB, "Test ajouter :", test_cb_ajouter))
		|| (NULL == CU_add_test(pSuiteCB, "Test modifier :", test_cb_modifier))
        || (NULL == CU_add_test(pSuiteCB, "Test CB en Octet :", test_cb_enOctet))
		) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuiteTDC, "Test vide :", test_tdc_vide))
		|| (NULL == CU_add_test(pSuiteTDC, "Test ajouter :", test_tdc_ajouter))
		|| (NULL == CU_add_test(pSuiteTDC, "Test supprimer :", test_tdc_supprimer))
		) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Lancement des tests */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    /* Nettoyage du registre */
    CU_cleanup_registry();
    return CU_get_error();
}
