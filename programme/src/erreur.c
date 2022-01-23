#include <stdio.h>
#include "erreur.h"
#include <errno.h>

void E_traitementErreur(int status){
	printf("Utilisation: ./huffman <c/d> <fichier> \n");
	
	switch(status){
		case ERREUR_ERRNO:
			printf("Errno: %i\n", errno);
			break;
		case ERREUR_MAIN_PAS_ASSEZ_ARGUMENTS:
			printf("Erreur: Pas assez d'arguments (code %i) \n", status);
			break;
		case ERREUR_MAIN_CHEMIN_INVALIDE:
			printf("Erreur: Chemin invalide (code %i) \n", status);
			break;
		case ERREUR_MAIN_MODE_EXISTE_PAS:
			printf("Erreur: Mode inconnu (code %i) \n", status);
			break;
		case ERREUR_COMPRESSER_FICHIER_EXISTE_PAS:
			printf("Erreur: Le fichier source n'éxiste pas (code %i) \n", status);
			break;
		case ERREUR_DECOMPRESSER_FICHIER_NON_VALIDE:
			printf("Erreur: Fichier non reconnu (code %i) \n", status);
			break;
		case ERREUR_CALCULERSTATS_OVERFLOW:
			printf("Erreur: Le fichier source est trop gros (code %i) \n", status);
			break;
		default:
			printf("Erreur générale (code %i)", status);
			break;
	}
}
