#include <stdbool.h>
#include "fileDePriorite.h"
#include <assert.h>
#include <stdlib.h>


/*FONCTIONS PRIVEES*/

FDP_listeChaineeArbre FDP_obtenirDebut(FileDePriorite file){
    return file.debut;
}

FDP_listeChaineeArbre FDP_obtenirFin(FileDePriorite file){
    return file.fin;
}

void FDP_fixerDebut(FileDePriorite *file, FDP_listeChaineeArbre debut){
    file->debut=debut;
}

void FDP_fixerFin(FileDePriorite *file, FDP_listeChaineeArbre fin){
    file->fin=fin;
}

ArbreDeHuffman FDP_obtenirElementListe(FDP_listeChaineeArbre liste){
    return liste->element;
}

void FDP_fixerElementListe(FDP_listeChaineeArbre liste, ArbreDeHuffman arbre){
    liste->element=arbre;
}

FDP_listeChaineeArbre FDP_obtenirListeSuivante(FDP_listeChaineeArbre liste){
    return liste->listeSuivante;
}

void FDP_fixerListeSuivante(FDP_listeChaineeArbre liste, FDP_listeChaineeArbre listeSuivante){
    liste->listeSuivante=listeSuivante;
}

bool FDP_listeEstVide(FDP_listeChaineeArbre liste){
    return liste==NULL;
}

/*FIN FONCTIONS PRIVEES*/

FileDePriorite FDP_creerFile(){
    FileDePriorite file;
    FDP_fixerDebut(&file,NULL);
    FDP_fixerFin(&file,NULL);
    return file;
}


bool FDP_estVide(FileDePriorite file){
    return file.debut==NULL;
}


ArbreDeHuffman FDP_obtenirArbre(FileDePriorite file){
    assert(!FDP_estVide(file));
    return FDP_obtenirElementListe(FDP_obtenirDebut(file));
}


void FDP_enfiler(FileDePriorite *file, ArbreDeHuffman arbre){
    FDP_listeChaineeArbre elem,noeud;
    bool fin;
    elem=malloc(sizeof(FDP_Noeud));
    FDP_fixerElementListe(elem,arbre);
    FDP_fixerListeSuivante(elem, NULL);
    if(FDP_estVide(*file)){
        FDP_fixerDebut(file,elem);
        FDP_fixerFin(file,elem);
    } else {
      if(ADH_comparer(FDP_obtenirElementListe(elem),FDP_obtenirArbre(*file))<0){
	FDP_fixerListeSuivante(elem,FDP_obtenirDebut(*file));
        FDP_fixerDebut(file,elem);
      } else {
	fin=false;
        noeud=FDP_obtenirDebut(*file);
        while(!fin){
            if(FDP_listeEstVide(FDP_obtenirListeSuivante(noeud))){
	        FDP_fixerListeSuivante(noeud,elem);
	        FDP_fixerFin(file,elem);
	        fin=true;
            }
            if(ADH_comparer(FDP_obtenirElementListe(elem),FDP_obtenirElementListe(FDP_obtenirListeSuivante(noeud)))<0){
	        FDP_fixerListeSuivante(elem,FDP_obtenirListeSuivante(noeud));
	        FDP_fixerListeSuivante(noeud,elem);
	        fin=true;
            } else {
	        noeud=FDP_obtenirListeSuivante(noeud);
            }
         }
      }
   }
}



void FDP_defiler(FileDePriorite *file){
    assert(!FDP_estVide(*file));
    FDP_listeChaineeArbre tmp;
    tmp=FDP_obtenirDebut(*file);
    if(!FDP_listeEstVide(FDP_obtenirListeSuivante(FDP_obtenirDebut(*file)))){
        FDP_fixerDebut(file,FDP_obtenirListeSuivante(FDP_obtenirDebut(*file)));
    }
    else{
        FDP_fixerDebut(file,NULL);
        FDP_fixerFin(file,NULL);
    }
    free(tmp);
}
