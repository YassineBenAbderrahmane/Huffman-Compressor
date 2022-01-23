#include "CodeBinaire.h"
#include "ArbreDeHuffman.h"
#include "TableDeCodage.h"

void associerCodeBinaire(TableDeCodage *tdc, Octet octet, CodeBinaire code) {
    TDC_ajouterOctet(tdc,octet,code);
}

void parcourirArbreR(TableDeCodage* tdc, ArbreDeHuffman arbre, CodeBinaire code) {
    if(ADH_estFeuille(arbre)) {
        associerCodeBinaire(tdc, ADH_obtenirOctet(arbre), code);
    } else {
        CB_ajouterBit(&code, bitA0);
        parcourirArbreR(tdc, ADH_obtenirFilsGauche(arbre), code);
        CB_modifierIemeBit(&code, CB_longueur(code), bitA1);
        parcourirArbreR(tdc, ADH_obtenirFilsDroit(arbre), code);
    }
}


TableDeCodage *genererTable(ArbreDeHuffman arbreFinal) {
    TableDeCodage *tdc = TDC_creerTableDeCodage();
    parcourirArbreR(tdc, arbreFinal, CB_creerCodeBinaire());
    return tdc;
}