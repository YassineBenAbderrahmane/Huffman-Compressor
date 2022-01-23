#ifndef _ERREUR_
#define _ERREUR_

#define VALIDE 0

//Main
#define ERREUR_MAIN 1
#define ERREUR_MAIN_PAS_ASSEZ_ARGUMENTS 2
#define ERREUR_MAIN_CHEMIN_INVALIDE 3
#define ERREUR_MAIN_MODE_EXISTE_PAS 4

//Compresser
#define ERREUR_COMPRESSER 100
#define ERREUR_COMPRESSER_FICHIER_EXISTE_PAS 101

//Decompresser
#define ERREUR_DECOMPRESSER 200
#define ERREUR_DECOMPRESSER_FICHIER_NON_VALIDE 201

//CalculerStats
#define ERREUR_CALCULERSTATS 300
#define ERREUR_CALCULERSTATS_OVERFLOW 301

//GenererArbre
#define ERREUR_GENERERARBRE 400

//GenererTable
#define ERREUR_GENERERTABLE 500

//GenererFichier
#define ERREUR_GENERERFICHIER 600

//Fichiers
#define ERREUR_FICHIER 700
#define ERREUR_FICHIER_EOF 701 //Erreur présente pour remonter la fin de fichier. N'est jamais retournée

//Erreur via errno
#define ERREUR_ERRNO 999

void E_traitementErreur(int erreur);
#endif
