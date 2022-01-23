#ifndef __TABLE_DE_CODAGE__
#define __TABLE_DE_CODAGE__
#include <stdbool.h>
#include "CodeBinaire.h"
#include "octet.h"

/*!
 *\struct TableDeCodage TableDeCodage.h "TableDeCodage"
 */
typedef CodeBinaire TableDeCodage[256];

/**
 * \fn unsigned int TDC_hash(Octet o)
 * \brief Fonction de hashage
 *
 * \param o L'Octet pour lequel on doit associer un nombre 
 * \return Le nombre associé a l'octet.
 */  
unsigned int TDC_hash(Octet o);

/**
 * \fn TableDeCodage *TDC_creerTableDeCodage()
 * \brief Fonction pour créer la table de codage
 *
 * 
 * \return La table de codage.
 */ 
TableDeCodage *TDC_creerTableDeCodage();

/**
 * 
 * \brief Procédure qui permet d'ajouter un octet
 * \Attention L'octet ne doit pas déja être présent dans la table
 * 
 *
 */ 
void TDC_ajouterOctet(TableDeCodage *tdc, Octet octet, CodeBinaire code);

/**
 * 
 * \brief Procédure qui permet de supprimer un octet
 * \Attention L'octet doit déja être présent dans la table
 * 
 *
 */
void TDC_supprimerOctet(TableDeCodage *tdc, Octet octet);

/**
 * \fn CodeBinaire TDC_recupererCodeBinaire(TableDeCodage tdc,Octet octet)
 * \brief Fonction qui récupère le code binaire associé à un octet
 * \param[in] tdc La table de codage
 * \param[in] octet L'octet dont on veut le code binaire
 * \Attention L'octet doit être présent dans la table
 * 
 * \return Le code binaire correspondant.
 */ 
CodeBinaire TDC_recupererCodeBinaire(TableDeCodage tdc, Octet octet);

/**
 * \fn bool TDC_estVide(TableDeCodage tdc)
 * \brief Fonction qui vérifie si une table est de codage est vide ou non
 * \param tdc La table de codage à tester
 * 
 * \return VRAI si la table est vide, FAUX sinon.
 */ 
bool TDC_estVide(TableDeCodage tdc);

/**
 * \fn bool TDC_octetPresent(TableDeCodage tdc, Octet octet)
 * \brief Fonction qui vérifie si un octet est présent dans la table de codage
 * \param tdc La table de codage à tester
 * \param octet L'octet à chercher
 * \return VRAI si l'octet est présent, FAUX sinon.
 */ 
bool TDC_octetPresent(TableDeCodage tdc, Octet octet);

/**
 * \fn unsigned int TDC_nbOctets(TableDeCodage tdc)
 * \brief Fonction qui calcule le nombre d'octets de la table de codage
 * \param tdc La table de codage à tester
 * 
 * \return Le nombre d'octets.
 */ 
unsigned int TDC_nbOctets(TableDeCodage tdc);

/**
 * \fn void TDC_supprimer(TableDeCodage *tdc)
 * \brief procédure qui permet de libérer l'espace allouer à la table de codage
 * \param tdc La table de codage
 * 
 * 
 */ 
void TDC_supprimer(TableDeCodage *tdc);

#endif

