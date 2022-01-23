#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include "fichier.h"
#include "octet.h"
#include "erreur.h"

Fichier F_InitFichier(char *nom, F_Mode mode, int *status){
	Fichier fichier;

	fichier.nom = nom;

	fichier.fb = F_OuvrirFichier(fichier.nom, mode, status);

	fichier.longueur = 0;

	return fichier;
}

Octet F_LireOctet(Fichier fichier, int *status){
	assert(fichier.fb != NULL);
	assert(!feof(fichier.fb));
	
	int resultat;

	resultat = fgetc(fichier.fb);

	if (resultat==EOF){
		if(feof(fichier.fb)){
			*status = ERREUR_FICHIER_EOF;
		}else{
			*status = ERREUR_ERRNO;
		}
	}

	return O_charEnOctet( (unsigned char) resultat);
}

void F_EcrireOctet(Fichier fichier, Octet octet, int *status){
	assert(fichier.fb != NULL);

	int resultat;

	resultat = fputc(octet, fichier.fb);

	if (resultat==EOF){
		*status = ERREUR_ERRNO;
	}
}

FILE *F_OuvrirFichier(char *nom, F_Mode mode, int *status){
	FILE *fb;

	switch(mode){
		case lecture:
			fb = fopen(nom, "rb");

			break;
		case ecriture:
			fb = fopen(nom, "wb");
			break;
	}

	if(fb == NULL){
		*status = ERREUR_ERRNO;
	}else if(fseek(fb, 0, SEEK_SET) != 0){
		*status = ERREUR_ERRNO;
	}

	return fb;
}

void F_FermerFichier(Fichier fichier, int *status){
	int valeurRetour;

	valeurRetour = fclose(fichier.fb);

	if(valeurRetour == EOF){
		*status = ERREUR_ERRNO;
	}
}