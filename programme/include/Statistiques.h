#ifndef __STATISTIQUES__
#define __STATISTIQUES__
#include <stdbool.h>
#include "octet.h"

/*!
 *\struct Statistiques Statistiques.h "Statistiques"
 */

typedef unsigned int Statistiques[256];

/*!
 * \fn unsigned int S_hash(Octet o)
 * \brief Fonction de hashage
 *
 * \param[in] o L'octet pour lequel on doit associer un nombre 
 * \return Le nombre associé a l'octet.
 */  

unsigned int S_hash(Octet o);

/*!
 *\fn Statistiques* S_statistiques()
 *\brief Création du tableau de statistiques
 *
 *\return Statistiques : le tableau vide
 */
	
Statistiques* S_statistiques();

/*!
 *\fn void S_ajouterOctet(Statistiques *stat, Octet octet, unsigned int nbOccur)
 *\brief Procedure qui permet d'ajouter un octet dans le tableau de statistiques
 *\pre l'octet ne se trouve pas déjà dans le tableau
 *
 *\param[out] *stat pointeur sur le tableau dans lequel on ajoute l'octet
 *\param[in] octet  l'octet qu'on veut ajouter dans le tableau
 *\param[in] nbOccur  le nombre d'occurence de l'octet
 */

void S_ajouterOctet(Statistiques *stat, Octet octet, unsigned int nbOccur);

/*!
 *\fn void S_modifierOctet(Statistiques *stat, Octet octet, unsigned int nbOccur)
 *\brief Procedure qui permet de modifier un octet dans le tableau de statistiques
 *\pre l'octet doit être dans le tableau
 *
 *\param[out] *stat pointeur sur le tableau dans lequel on modifie l'octet
 *\param[in] octet  l'octet qu'on veut modifier dans le tableau
 *\param[in] nbOccur  le nombre d'occurence de l'octet
 */

void S_modifierOctet(Statistiques *stat, Octet octet, unsigned int nbOccur);

/*!
 *\fn unsigned int S_nbElements(Statistiques stat)
 *\brief Fonction qui retourne la longueur du tableau de statistiques
 *
 *\param[in] stat le tableau dont on veut connaître la longueur
 *\return unsigned int : la taille du tableau
 */

unsigned int S_nbElements(Statistiques stat);

/*!
 *\fn bool S_estVide(Statistiques stat)
 *\brief Fonction qui permet de savoir si un tableau est vide ou non
 *
 *\param[in] stat le tableau à tester
 *\return bool, vrai si le tableau est vide, faux sinon
 */

bool S_estVide(Statistiques stat);

/*!
 *\fn bool S_estPresent(Statistiques stat, Octet octet)
 *\brief Fonction qui permet de savoir si un octet est présent dans un tableau
 *
 *\param[in] stat le tableau à tester
 *\param[in] octet  l'octet dont on veut vérifier la présence
 *\return bool, vrai si l'octet est présent, faux sinon
 */

bool S_estPresent(Statistiques stat, Octet octet);

/*!
 *\fn unsigned int S_obtenirOccurence(Statistiques stat, Octet octet)
 *\brief Fonction qui permet de connaître le nombre d'occurence d'un octet
 *
 *\param[in] stat le tableau à tester
 *\param[in] octet  l'octet dont on veut le nombre d'occurence
 *\return unsigned int, le nombre d'occurence
 */

unsigned int S_obtenirOccurence(Statistiques stat, Octet octet);

/*!
 *\fn void S_supprimerOctet(Statistiques *stat, Octet octet)
 *\brief Fonction qui permet de supprimer un octet
 *\pre l'octet doit être présent dans le tableau
 *
 *\param[out] *stat le pointeur sur le tableau à modifier
 *\param[in] octet  l'octet que l'on veut supprimer
 */

void S_supprimerOctet(Statistiques *stat, Octet octet);

/*!
 *\fn void S_obtenirClefs(Statistiques stat, Octet *premierOctet, unsigned int *nbTrouve)
 *\brief Fonction qui permet d'obtenir les clefs ayant une statistique non nulle
 *
 *\param[in] Statistiques le tableau de statistiques
 *\param[out] *premierOctet pointeur sur le premier octet du bloc mémoire dans lequel écrire les clefs (Rappel : maximum 256 clefs)
 *\param[out] unsigned int nombre de clefs écrites
 */

void S_obtenirClefs(Statistiques stat, Octet *premierOctet, unsigned int *nbTrouve);

/*!
 *\fn void S_supprimer(Statistiques *stats)
 *\brief Procedure qui permet de supprimer le tableau
 *
 *\param[out] *stats le tableau à supprimer
 */

void S_supprimer(Statistiques *stats);

#endif
