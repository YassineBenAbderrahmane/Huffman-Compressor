#ifndef __ARBRE_DE_HUFFMAN__
#define __ARBRE_DE_HUFFMAN__
#include <stdbool.h>
#include "octet.h"

/*!
 * Un arbre (pointeur vers noeud)
 */
typedef struct ADH *ArbreDeHuffman;

/*!
 * Le noeud représentant un arbre
 */
typedef struct ADH{
	ArbreDeHuffman filsD; /*!< Le fils droit. */
	ArbreDeHuffman filsG; /*!< Le fils gauche. */
	unsigned int poids; /*!< Le poids éventuel de l'arbre. */
	Octet octet; /*!< L'octet correspondant. */
} ADH;

/*!
 * Fonction qui permet d'initialiser un arbre
 *\return un arbre.
 */
ArbreDeHuffman ADH_creerArbreDeHuffman(); 

/*!
 * Fonction qui permet de savoir si un arbre est vide ou non
 *\param[in] ArbreDeHuffman l'arbre à tester
 *\return bool, vrai si l'arbre est vide, faux sinon 
 */
bool ADH_estVide(ArbreDeHuffman arbre);

/*!
 * Fonction qui permet de savoir si un arbre est une feuille
 *\pre l'arbre ne doit pas être vide
 *\param[in] ArbreDeHuffman l'arbre à tester
 *\return bool, vrai si l'arbre est une feuille, faux  sinon
 */
bool ADH_estFeuille(ArbreDeHuffman arbre);

/*!
 * Fonction qui crée un ArbreDeHuffman en tant que racine de deux autres ArbreDeHuffman
 *\pre Aucun des deux arbres fournis ne doit être vide
 *\param[in] Poids  le poids de l'arbre
 *\param[in] ArbreDeHuffman  l'arbre qui sera raccroché à droite
 *\param[in] ArbreDeHuffman  l'arbre qui sera raccroché à  gauche
 *\return ArbreDeHuffman,  le nouvel arbre
 */

ArbreDeHuffman ADH_insererRacine(unsigned int poids, ArbreDeHuffman fg, ArbreDeHuffman fd); 

/*!
 * Fonction qui crée un ArbreDeHuffman en tant que racine de deux  autres ArbreDeHuffman
 *\pre Aucun des deux arbres fournis ne doit être vide
 *\param[in] octet  l'octet de l'arbre
 *\param[in] poids  le poids de l'arbre
 *\param[in] ArbreDeHuffman  l'arbre qui sera raccroché à droite
 *\param[in] ArbreDeHuffman  l'arbre qui sera raccroché à gauche
 *\return ArbreDeHuffman,  le nouvel arbre
 */
ArbreDeHuffman ADH_insererFeuille(Octet octet, unsigned int poids, ArbreDeHuffman fg, ArbreDeHuffman fd);

/*!
 * Fonction qui permet d'obtenir le poids contenu dans la racine d'un arbre
 *\param[in] ArbreDeHuffman l'arbre dont on veux récupérer le  poids
 *\return int, le poids
 */

unsigned int ADH_obtenirPoids(ArbreDeHuffman arbre);

/*!
 * Fonction qui permet d'obtenir l'élément de la racine d'un  arbre
 *\pre l'arbre ne doit pas être vide
 *\param[in] ArbreDeHuffman l'arbre dont on veut récupérer l'octet
 *\return Octet,  l'élément (dans notre cas, un Octet)
 */
Octet ADH_obtenirOctet(ArbreDeHuffman arbre);
/*!
 * Fonction qui permet d'obtenir le sous arbre droit d'un arbre de  huffman
 *\pre l'arbre ne doit pas être vide
 *\param[in] ArbreDeHuffman l'arbre dont on veut récupérer le fils droit
 *\return ArbreDeHuffman, le fils droit
 */

ArbreDeHuffman ADH_obtenirFilsDroit(ArbreDeHuffman arbre); 
/*!
 * Fonction qui permet d'obtenir le sous arbre gauche d'un arbre de  huffman
 *\pre l'arbre ne doit pas être vide
 *\param[in] ArbreDeHuffman l'arbre dont on veut récupérer le fils gauche
 *\return ArbreDeHuffman, le fils gauche
 */
ArbreDeHuffman ADH_obtenirFilsGauche(ArbreDeHuffman arbre);

/*!
 * Fonction qui permet de vider un  ArbreDeHuffman
 * \warning La fonction supprime récursivement tous les sous-arbres
 *\param[out]  ArbreDeHuffman l'arbre à vider
 */

void ADH_supprimer(ArbreDeHuffman arbre);

//-1 a1 < a2 / 0 a1 = a2 / 1 si a1 > a2
/*!
 * Fonction qui permet de savoir si deux arbres ont le même  poids
 *\pre aucuns des deux arbres ne doivent être vides
 *\param[in]  ArbreDeHuffman le premier arbre
 *\param[in]  ArbreDeHuffman le deuxième arbre
 *\return int, 
 	 		 <br>  -1 si arbre1 < arbre2 
 			 <br> 	0 si arbre1 = arbre2 
 			 <br> 	1 si arbre1 > arbre2
 */
int ADH_comparer(ArbreDeHuffman arbre1, ArbreDeHuffman arbre2);

#endif