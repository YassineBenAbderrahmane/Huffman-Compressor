#include <stdlib.h>
#include <assert.h>
#include "Statistiques.h"

unsigned int S_hash(Octet o){
    return O_octetEnNaturel(o);
}

Statistiques* S_statistiques(){
    Statistiques *stat = malloc(sizeof(Statistiques));
    for (unsigned int i=0;i<=255;i++){
        (*stat)[i]=0;
    }
    return stat; 
}

void S_ajouterOctet(Statistiques *stat, Octet octet, unsigned int nbOccur){
    assert(!S_estPresent(*stat,octet));
    (*stat)[S_hash(octet)]=nbOccur;
}

void S_modifierOctet(Statistiques *stat, Octet octet, unsigned int nbOccur){
    assert(S_estPresent(*stat,octet));
    (*stat)[S_hash(octet)]=nbOccur;
}

unsigned int S_nbElements(Statistiques stat){
    unsigned int taille = 0;
    for(unsigned int i=0;i<=255;i++){
        if (stat[i]!=0){
            taille++;
        }
    }
    return taille;
}   
bool S_estVide(Statistiques stat){
    return S_nbElements(stat) == 0;
}

bool S_estPresent(Statistiques stat, Octet octet){
    return (S_obtenirOccurence(stat,octet)!=0);
}

unsigned int S_obtenirOccurence(Statistiques stat, Octet octet){
    return stat[S_hash(octet)];
}

void S_supprimerOctet(Statistiques *stat, Octet octet){
    assert(S_estPresent(*stat,octet));
    S_modifierOctet(stat,octet,0);
}

void S_obtenirClefs(Statistiques stat, Octet *premierOctet, unsigned int *nbTrouve){
    int i;
    *nbTrouve = 0;

    for(i=0;i<=255;i++){
        if(stat[i] > 0){
            premierOctet[*nbTrouve] = O_naturelEnOctet(i);
            (*nbTrouve)++;
        }
    }
}

void S_supprimer(Statistiques *stats){
    free(stats);
}
