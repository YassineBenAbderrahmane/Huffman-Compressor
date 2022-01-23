#include <stdlib.h>
#include <string.h>

#include "CodeBinaire.h"
#include "Statistiques.h"
#include "TableDeCodage.h"
#include "constantes.h"
#include "erreur.h"
#include "fichier.h"
#include "octet.h"

CodeBinaire coderOctet(TableDeCodage tdc, Octet octet) {
    CodeBinaire cb;
    cb = TDC_recupererCodeBinaire(tdc, octet);
    return cb;
}

void ajouterID(Fichier *fCompr) {
    fwrite(CST_ID, 16, 1, fCompr->fb);
}

void ajouterLongueur(Fichier *fCompr, unsigned int longueur) {
    fCompr->longueur = longueur;
    fwrite(&longueur, sizeof(unsigned int), 1, fCompr->fb);
}

void ajouterStats(Fichier *fCompr, Statistiques stats, int *status) {
    Octet *pOctet;
    unsigned int nbOctet, i, tmp;

    pOctet = malloc(256 * sizeof(Octet));
    S_obtenirClefs(stats, pOctet, &nbOctet);

    fwrite(&nbOctet, sizeof(unsigned int), 1, fCompr->fb);

    i = 0;
    while ((i < nbOctet) && (*status == VALIDE)) {
        F_EcrireOctet(*fCompr, pOctet[i], status);
        tmp = S_obtenirOccurence(stats, pOctet[i]);
        fwrite(&tmp, sizeof(unsigned int), 1, fCompr->fb);
        i++;
    }

    free(pOctet);
}

void creerNouveauFichier(Fichier *fCompr, Statistiques stats, char *nomFichierCpr, unsigned int longueur, int *status) {
    *fCompr = F_InitFichier(nomFichierCpr, ecriture, status);
    if (*status == VALIDE) {
        ajouterID(fCompr);
        ajouterLongueur(fCompr, longueur);
        ajouterStats(fCompr, stats, status);
    }
}

void gererBuffer(CodeBinaire code, CodeBinaire *buffer, Fichier fichier, int *status) {
    for (int i = 1; i <= CB_longueur(code); i = i + 1) {
        CB_ajouterBit(buffer, CB_iemeBit(code, i));

        if (CB_longueur(*buffer) == 8) {
            F_EcrireOctet(fichier, CB_codeBinaireEnOctet(*buffer), status);
            *buffer = CB_creerCodeBinaire();
        }
    }
}

void genererFichier(Statistiques stats, TableDeCodage tdc, Fichier *fOriginal, int *status) {
    Fichier fCompr;
    CodeBinaire codeB, buffer;
    Octet octetLu;
    char nomFichierCpr[255];

    strcpy(nomFichierCpr, fOriginal->nom);
    strcat(nomFichierCpr, HUFFMAN_EXTENSION);

    creerNouveauFichier(&fCompr, stats, nomFichierCpr, fOriginal->longueur, status);

    fseek(fOriginal->fb, 0, SEEK_SET);
    buffer = CB_creerCodeBinaire();
    while (!feof(fOriginal->fb) && (*status == VALIDE)) {

        octetLu = F_LireOctet(*fOriginal, status);
        
        //On ne peut pas savoir si EOF avant de lire l'octet
        if(*status == ERREUR_FICHIER_EOF){
            *status = VALIDE;
            break;
        }

        codeB = coderOctet(tdc, octetLu);

        gererBuffer(codeB, &buffer, fCompr, status);

        if(*status != VALIDE){
            return;
        }

    }

    if (*status != VALIDE)
        return;

    //Buffer restant
    if (CB_longueur(buffer) != 0) {
        F_EcrireOctet(fCompr, CB_codeBinaireEnOctet(buffer), status);
    }
    fclose(fCompr.fb);
}
