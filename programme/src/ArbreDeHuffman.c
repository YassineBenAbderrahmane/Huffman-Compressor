#include <stdlib.h>
#include <assert.h>
#include "ArbreDeHuffman.h"

ArbreDeHuffman ADH_creerArbreDeHuffman() {
	ArbreDeHuffman arbre;
	arbre = malloc(sizeof(ADH));
	arbre->filsD = NULL;
	arbre->filsG = NULL;
	return arbre;
}

bool ADH_estVide(ArbreDeHuffman arbre) {
	return ((ADH_obtenirFilsDroit(arbre) == NULL) && (ADH_obtenirFilsGauche(arbre) == NULL));
}

bool ADH_estFeuille(ArbreDeHuffman arbre) {
	assert(!ADH_estVide(arbre));
	return (ADH_estVide(ADH_obtenirFilsDroit(arbre)) && ADH_estVide(ADH_obtenirFilsGauche(arbre)));
}

ArbreDeHuffman ADH_insererRacine(unsigned int poids, ArbreDeHuffman fg, ArbreDeHuffman fd) {
	assert(!ADH_estVide(fd) && !ADH_estVide(fg));
    ArbreDeHuffman arbre;
	arbre = malloc(sizeof(ADH));
	arbre->filsG = fg;
	arbre->filsD = fd;
	arbre->poids = poids;
	return arbre;
}

ArbreDeHuffman ADH_insererFeuille(Octet octet,unsigned int poids,ArbreDeHuffman fg, ArbreDeHuffman fd ) {
	ArbreDeHuffman arbre;
	arbre = malloc(sizeof(ADH));
	arbre->filsG = fg;
	arbre->filsD = fd;
	arbre->poids = poids;
	arbre->octet = octet;
	return arbre;
}

unsigned int ADH_obtenirPoids(ArbreDeHuffman arbre) {
	assert(!ADH_estVide(arbre));
	return arbre->poids;
}


Octet ADH_obtenirOctet(ArbreDeHuffman arbre) {
	assert(ADH_estFeuille(arbre));
	return arbre->octet;
}

ArbreDeHuffman ADH_obtenirFilsDroit(ArbreDeHuffman arbre) {
	return arbre->filsD;
}

ArbreDeHuffman ADH_obtenirFilsGauche(ArbreDeHuffman arbre) {
	return arbre->filsG;
}

void ADH_supprimer(ArbreDeHuffman arbre) {
	ArbreDeHuffman tmp;
	if(!ADH_estVide(arbre)) {
			tmp=ADH_obtenirFilsDroit(arbre);
			ADH_supprimer(tmp);
			tmp=ADH_obtenirFilsGauche(arbre);
			ADH_supprimer(tmp);
		}
			free(arbre);
}

int ADH_comparer(ArbreDeHuffman arbre1, ArbreDeHuffman arbre2){
	assert((!ADH_estVide(arbre1)) && (!ADH_estVide(arbre2)));

	int poids1, poids2, resultat;

	poids1 = ADH_obtenirPoids(arbre1);
	poids2 = ADH_obtenirPoids(arbre2);

	if(poids1 > poids2){
		resultat = 1;
	}else if(poids1 < poids2){
		resultat = -1;
	}else{
		resultat = 0;
	}
	
	return resultat;
}