#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include "erreur.h"
#include "fichier.h"

#include "constantes.h"
#include "metier.h"

/*! \mainpage Compresseur de Huffman
 *
 * Ceci est la documentation de notre compresseur de huffman
 *
 * Après avoir utilisé la commande make, le programme est ./bin/huffman
 *
 * 
 * Pour l'utilisation :
 * 	huffman <c/d> <fichier>
 * 
 */

int validationArguments(int argc, char *argv[], int *mode);
bool validerMode(char *modeChaine, int *mode);
bool validerChemin(char *chemin);

int main(int argc, char *argv[]){
	int status, mode;
	Fichier fichier;

	mode = 0;
	status = validationArguments(argc, argv, &mode);

	if(status == VALIDE){
		fichier = F_InitFichier(argv[2], lecture, &status);

		if (status == VALIDE){
			if(mode == MODE_COMPRESSION){
				status = compresser(fichier);
			}else if (mode == MODE_DECOMPRESSION){
				status = decompresser(fichier);
			}
			
			if(status == VALIDE){
				F_FermerFichier(fichier, &status);
			}
		}else{
			status = ERREUR_COMPRESSER_FICHIER_EXISTE_PAS;
		}
	}

	if(status != VALIDE)
		E_traitementErreur(status);

	return status;
}

int validationArguments(int argc, char *argv[], int *mode){
	int status;

	if( argc == 3){
		if(validerMode(argv[1], mode)){
			if(validerChemin(argv[2])){
				status = VALIDE;
			}else{
				status = ERREUR_MAIN_CHEMIN_INVALIDE;
			}
		}else{
			status= ERREUR_MAIN_MODE_EXISTE_PAS;
		}
	}else{
		status = ERREUR_MAIN_PAS_ASSEZ_ARGUMENTS;
	}

	return status;
}

bool validerMode(char *modeChaine, int *mode){
	bool valide;

	valide = true;

	if(strcmp("c", modeChaine) == 0){
		*mode = MODE_COMPRESSION;

	}else if(strcmp("d", modeChaine) == 0){
		*mode = MODE_DECOMPRESSION;

	}else{
		valide = false;
	}

	return valide;
}

bool validerChemin(char *chemin){
	return (strchr(chemin, '/') == NULL);
}