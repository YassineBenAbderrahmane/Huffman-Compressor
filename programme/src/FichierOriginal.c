#include <stdio.h>
#include <string.h>
#include "octet.h"
#include "ArbreDeHuffman.h"
#include "fichier.h"
#include "constantes.h"
#include "erreur.h"

ArbreDeHuffman parcourirArbre(Bit bit,ArbreDeHuffman a);
void traitementNom(Fichier *f);

void FichierOriginal(Fichier *f,ArbreDeHuffman a,int *Status){
    ArbreDeHuffman aTemp=a;

    int nbDecpr=0;

    int IemeBit=8;//On lit les octets lineairement(de 8 a 1)

    Fichier fDecpr;

    Octet o;

    traitementNom(f);

    fDecpr=F_InitFichier(f->nom, ecriture, Status);

    if (*Status!=VALIDE)
	    return;

    o=F_LireOctet(*f,Status);

    if (*Status!=VALIDE)
	    return;

    while (nbDecpr<(f->longueur)){
        if (IemeBit < 1){
            o=F_LireOctet(*f,Status);

            if (*Status!=VALIDE)
                return;

            IemeBit=8;
	    }

        aTemp=parcourirArbre(O_lireIemeBit(o,IemeBit),aTemp);

        if (ADH_estFeuille(aTemp)){
            F_EcrireOctet(fDecpr,ADH_obtenirOctet(aTemp),Status);

            if (*Status!=VALIDE)
                return;

            aTemp=a;

            nbDecpr++;
        }
        IemeBit--;
    }

    fclose(fDecpr.fb);
}

ArbreDeHuffman parcourirArbre(Bit bit,ArbreDeHuffman a){
    ArbreDeHuffman resultat;

    if (bit==bitA1){
        resultat=ADH_obtenirFilsDroit(a);
    }else{
        resultat=ADH_obtenirFilsGauche(a);
    }
    return resultat;
}

void traitementNom(Fichier *f){
    //On coupe l'extention si on la trouve en fin de chaine
    char *pDernierPoint = strrchr(f->nom, '.');
    if (pDernierPoint && !strcmp(pDernierPoint, HUFFMAN_EXTENSION)){
        f->nom[strlen(f->nom) - strlen(HUFFMAN_EXTENSION)] = '\0';
    }

    //Decommenter pour eviter de remplacer le fichier original
    //f->nom[0]='0';
}