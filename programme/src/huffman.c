#include <stdlib.h>
#include <string.h>

#include "ArbreDeHuffman.h"
#include "Statistiques.h"
#include "TableDeCodage.h"
#include "constantes.h"
#include "erreur.h"
#include "fichier.h"
#include "metier.h"

int compresser(Fichier fichier) {
    Statistiques *statistiques;
    ArbreDeHuffman arbre;
    TableDeCodage *table;
    int status;
    status = VALIDE;
    statistiques = S_statistiques();

    calculerStatistiques(&fichier, statistiques, &status);
    if (status == VALIDE) {
        arbre = genererArbre(*statistiques);

        table = genererTable(arbre);

        genererFichier(*statistiques, *table, &fichier, &status);
    }

    TDC_supprimer(table);
    S_supprimer(statistiques);
    ADH_supprimer(arbre);

    return status;
}

bool verifierID(Fichier fichier) {
    char identifiant[17];
    unsigned blocLu;

    blocLu = fread(identifiant, 16, 1, fichier.fb);

    if(blocLu < 1){
        return false;
    }

    identifiant[16] = '\0';

    return (strcmp(CST_ID, identifiant) == 0);
}

unsigned int lireLongueur(Fichier fichier) {
    unsigned int longueur;

    fread(&longueur, sizeof(unsigned int), 1, fichier.fb);

    return longueur;
}

void lireStats(Fichier fichier, Statistiques *stats, int *status) {
    unsigned int nbStats, nbOccurence, i;
    Octet octet;

    fread(&nbStats, sizeof(unsigned int), 1, fichier.fb);

    i = 0;
    while ((i < nbStats) && (*status == VALIDE)) {
        octet = F_LireOctet(fichier, status);

        fread(&nbOccurence, sizeof(unsigned int), 1, fichier.fb);

        S_ajouterOctet(stats, octet, nbOccurence);

        i++;
    }
}

int decompresser(Fichier fichier) {
    Statistiques *statistiques;
    ArbreDeHuffman arbre;
    int status;
    status = VALIDE;
    if (verifierID(fichier)) {
        fichier.longueur = lireLongueur(fichier);

        statistiques = S_statistiques();
        lireStats(fichier, statistiques, &status);

        arbre = genererArbre(*statistiques);

        FichierOriginal(&fichier, arbre, &status);

        S_supprimer(statistiques);
        ADH_supprimer(arbre);
        
    } else {
        status = ERREUR_DECOMPRESSER_FICHIER_NON_VALIDE;
    }

    return status;
}
