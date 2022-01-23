#ifndef _FICHIER_
#define _FICHIER_
#include <stdio.h>
#include "octet.h"

typedef enum {lecture=0, ecriture=1} F_Mode;

typedef struct {
	FILE* fb;
	char* nom;
	unsigned int longueur;
} Fichier;

Fichier F_InitFichier(char *nom, F_Mode mode, int *status);

Octet F_LireOctet(Fichier fichier, int *status);

void F_EcrireOctet(Fichier fichier, Octet octet, int *status);

FILE *F_OuvrirFichier(char *nom, F_Mode mode, int *status);

void F_FermerFichier(Fichier fichier, int *status);

#endif
