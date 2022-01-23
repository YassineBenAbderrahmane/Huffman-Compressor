#include "CodeBinaire.h"
#include <assert.h>

CodeBinaire CB_creerCodeBinaire(){
    CodeBinaire resultat;
    resultat.longueur=0;
    return resultat;
}

unsigned int CB_longueur(CodeBinaire cBinaire){
    return cBinaire.longueur;
}

Bit CB_iemeBit(CodeBinaire cBinaire,unsigned int iemePlace){
    assert((0<iemePlace) & (iemePlace <= CB_longueur(cBinaire)));

    return cBinaire.code[iemePlace-1];

}

void CB_ajouterBit(CodeBinaire* cBinaire,Bit bit){
    assert(CB_longueur(*cBinaire)<256);

    cBinaire->code[CB_longueur(*cBinaire)]=bit;

    cBinaire->longueur=cBinaire->longueur+1;
}

void CB_modifierIemeBit(CodeBinaire *cBinaire, unsigned int iemePlace, Bit bit){
    assert((0<iemePlace) & (iemePlace <= CB_longueur(*cBinaire)));

    cBinaire->code[iemePlace-1]=bit;
}

void CB_supprimerIemeBit(CodeBinaire* cBinaire,unsigned int iemePlace){
    assert((0<iemePlace) & (iemePlace <= CB_longueur(*cBinaire)));

    int i;

    for(i=iemePlace+1;i<=CB_longueur(*cBinaire);i++){

	CB_modifierIemeBit(cBinaire,i-1,CB_iemeBit(*cBinaire,i));
    }

    cBinaire->longueur=CB_longueur(*cBinaire)-1;
}

bool CB_sontEgaux(CodeBinaire cBinaire1,CodeBinaire cBinaire2){
    bool egaux=true;
    int i=1;
    if (CB_longueur(cBinaire1)!=CB_longueur(cBinaire2)){

	egaux=false;

    }else{

	while (i<=CB_longueur(cBinaire1) && egaux){

	    if (CB_iemeBit(cBinaire1,i)!=CB_iemeBit(cBinaire2,i)){

		egaux=false;
	    }

	    i=i+1;
	}
    }

    return egaux;
}

Octet CB_codeBinaireEnOctet(CodeBinaire cBinaire){
    assert(CB_longueur(cBinaire)<=8);

    Octet octet;
    int i;

    octet=O_creerOctet();

    for(i=1;i<=CB_longueur(cBinaire);i++){

	O_ecrireIemeBit(&octet, 9-i, CB_iemeBit(cBinaire,i));
    }

    return octet;

}
