#include <limits.h> 
#include "Statistiques.h"
#include "octet.h"
#include "fichier.h" 
#include "erreur.h"

void incrementerStats(Statistiques *stats, Octet octet){
    unsigned int nbOccurence;
    
    nbOccurence = S_obtenirOccurence(*stats, octet);

    if(nbOccurence == 0){
        S_ajouterOctet(stats, octet, 1);
    }else{
        S_modifierOctet(stats,octet, nbOccurence + 1);
    }
}

void calculerStatistiques(Fichier *fichier, Statistiques *stats, int *status){
    Octet octet;

    while((!feof(fichier->fb)) && (*status == VALIDE)){
        octet = F_LireOctet(*fichier, status);
        //On ne peut pas savoir si EOF avant de lire l'octet
        if(*status == ERREUR_FICHIER_EOF){
           *status = VALIDE;
            return;
        }

        fichier->longueur = fichier->longueur + 1;

        incrementerStats(stats, octet);

        if((fichier->longueur == UINT_MAX)) 
            *status = ERREUR_CALCULERSTATS_OVERFLOW;

    }
}