#include "TableDeCodage.h"

#include <assert.h>
#include <stdlib.h>

unsigned int TDC_hash(Octet o) {
    return O_octetEnNaturel(o);
}
TableDeCodage *TDC_creerTableDeCodage() {
    int i;
    TableDeCodage *tdc = malloc(sizeof(TableDeCodage));
    for (i = 0; i <= 255; i++) {
        (*tdc)[i] = CB_creerCodeBinaire();
    }
    return tdc;
}

void TDC_ajouterOctet(TableDeCodage *tdc, Octet octet, CodeBinaire cb) {

    (*tdc)[TDC_hash(octet)] = cb;
}

void TDC_supprimerOctet(TableDeCodage *tdc, Octet octet) {
    assert(TDC_octetPresent(*tdc, octet));
    TDC_ajouterOctet(tdc, octet, CB_creerCodeBinaire());
}

CodeBinaire TDC_recupererCodeBinaire(TableDeCodage tdc, Octet octet) {
    return tdc[TDC_hash(octet)];
}

bool TDC_estVide(TableDeCodage tdc) {
    int i = 0;
    bool vide = true;
    while (vide && i <= 255) {
        if (!CB_sontEgaux(tdc[i], CB_creerCodeBinaire()))
            vide = false;
        i = i + 1;
    }
    return vide;
}

unsigned int TDC_nbOctets(TableDeCodage tdc) {
    int i;
    unsigned int res = 0;
    for (i = 0; i <= 255; i++)
        if (!CB_sontEgaux(tdc[i], CB_creerCodeBinaire()))
            res = res + 1;
    return res;
}

bool TDC_octetPresent(TableDeCodage tdc, Octet octet) {
    return (CB_longueur(TDC_recupererCodeBinaire(tdc, octet)) != 0);
}

void TDC_supprimer(TableDeCodage *tdc){
    free(tdc);
}
