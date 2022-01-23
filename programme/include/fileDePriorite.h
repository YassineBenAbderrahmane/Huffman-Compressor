#ifndef _FILE_DE_PRIORITE_
#define _FILE_DE_PRIORITE_
#include <stdbool.h>
#include "ArbreDeHuffman.h"

typedef struct FDP_Noeud *FDP_listeChaineeArbre;

typedef struct FDP_Noeud{
    ArbreDeHuffman element;
    FDP_listeChaineeArbre listeSuivante;
}   FDP_Noeud;

typedef struct {
    FDP_listeChaineeArbre debut;
    FDP_listeChaineeArbre fin;
}   FileDePriorite;

FileDePriorite FDP_creerFile();

/*!
 *\brief Fonction qui permet de savoir si une file est vide ou non
 *\param[in] FileDePriorite la file à tester
 *\return bool, vrai si la file est vide, faux sinon 
 */
bool FDP_estVide(FileDePriorite file);

/*!
 *\brief Fonction qui permet d'ajouter un arbre à une file
 *\param[in] ArbreDeHuffman l'arbre à enfiler 
 *\param[in, out] FileDePriorite la file qu'on modifie
 */
void FDP_enfiler(FileDePriorite *file, ArbreDeHuffman arbre);

/*!
 *\brief Fonction qui permet de retirer un arbre d'une file
 *\attention assertion : La file ne doit pas etre vide
 *\param[in] ArbreDeHuffman l'arbre à défiler 
 *\param[in,out],FileDePriorite la file qu'on modifie
 */
void FDP_defiler(FileDePriorite *file);

/*!
 *\brief Fonction qui permet d'obtenir l arbre à partir de la file de priorite
 *\attention assertion : La file ne doit pas etre vide
 *\param[in] FileDePriorite la file dont on veut l'arbre 
 *\return ArbreDeHuffman, l'arbre
 */
ArbreDeHuffman FDP_obtenirArbre(FileDePriorite file);

#endif
