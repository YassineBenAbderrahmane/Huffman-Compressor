#ifndef _METIER_
#define _METIER_
#include "fichier.h"
#include "Statistiques.h"
#include "ArbreDeHuffman.h"
#include "TableDeCodage.h"

void calculerStatistiques(Fichier *fichier, Statistiques *stats, int *status);

void FichierOriginal(Fichier *f,ArbreDeHuffman a,int *Status);

ArbreDeHuffman genererArbre(Statistiques stats);

void genererFichier(Statistiques stats, TableDeCodage tdc, Fichier *fOriginal, int *status);

TableDeCodage* genererTable(ArbreDeHuffman arbreFinal);

int compresser(Fichier fichier);

int decompresser(Fichier fichier);
#endif
