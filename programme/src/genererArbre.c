#include <stdlib.h>
#include "Statistiques.h"
#include "ArbreDeHuffman.h"
#include "fileDePriorite.h"



ArbreDeHuffman statEnArbre(Statistiques stats, Octet octet){
    ArbreDeHuffman arbre;
    ArbreDeHuffman fg, fd;
    fg = ADH_creerArbreDeHuffman();
    fd = ADH_creerArbreDeHuffman();
    arbre = ADH_insererFeuille(octet,S_obtenirOccurence(stats, octet), fg, fd);
    return arbre;
}

void arbreDansFile(ArbreDeHuffman arbre, FileDePriorite *file){
    FDP_enfiler(file, arbre);
}

FileDePriorite statsEnFileDArbres(Statistiques stats){
    Octet *pOctet;
    Octet octet;
    int i;
    unsigned int nbClefs;
    ArbreDeHuffman arbre;
    FileDePriorite file;
    file = FDP_creerFile();
    pOctet = malloc(256*sizeof(Octet));
    S_obtenirClefs(stats, pOctet, &nbClefs);
    for(i=0; i<nbClefs; i++){
        octet = pOctet[i];
        arbre = statEnArbre(stats, octet);
        arbreDansFile(arbre, &file);
    }
    free(pOctet);
    return file;
}

ArbreDeHuffman fusionner2Arbres(ArbreDeHuffman arbre1, ArbreDeHuffman arbre2){
    ArbreDeHuffman arbre;
    arbre = ADH_insererRacine((ADH_obtenirPoids(arbre1) + ADH_obtenirPoids(arbre2)), arbre2, arbre1);
    return arbre;
}

void majFileDePriorite(FileDePriorite *file){
    ArbreDeHuffman arbreFusion, arbre1, arbre2;
    arbre1 = FDP_obtenirArbre(*file);
    FDP_defiler(file);
    arbre2 = FDP_obtenirArbre(*file);
    FDP_defiler(file);
    arbreFusion = fusionner2Arbres(arbre1, arbre2);
    FDP_enfiler(file, arbreFusion);
}

bool arbreComplet(FileDePriorite file){
    return file.debut == file.fin;
}

ArbreDeHuffman genererArbre(Statistiques stats){
    FileDePriorite file;
    ArbreDeHuffman arbreFinal;
    file = statsEnFileDArbres(stats);
    while(!arbreComplet(file)){
        majFileDePriorite(&file);
    }
    arbreFinal = FDP_obtenirArbre(file);
    FDP_defiler(&file);
    return arbreFinal;
}
