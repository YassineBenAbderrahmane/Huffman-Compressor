#ifndef __CODE_BINAIRE__
#define __CODE_BINAIRE__
#include <stdbool.h>
#include "octet.h"

typedef struct CodeBinaire{
    Bit code[256];
    unsigned int longueur;
} CodeBinaire;

/*!
 * Fonction qui nous permet de initialiser le CodeBinaire
 *\return CodeBinaire , avec la longueur de CodeBinaire=0 
 */

CodeBinaire CB_creerCodeBinaire();

/*!
 * Fonction qui permet de retourner la longueur de CodeBinaire
 *\param[in] CodeBinaire le CBinaire dont on veut recuperer la longueur
 *\return CodeBinaire, unsigned int qui est la longueur de CodeBinaire
 */


unsigned int CB_longueur(CodeBinaire cBinaire);

/*!
 * Fonction qui nous permet d'obtenir le iemeBit
 *\pre La place du bit que l'on veut recuperer doit etre comprise entre 0 et la longueur de CodeBinaire
 *\param[in] CodeBinaire le cBinaire dont on veut recuperer le iemeBit
 *\param[in] iemePlace  la place dont on veut recuperer le bit
 *\return bit, retourne le bit a la iemePlace
 */


Bit CB_iemeBit(CodeBinaire cBinaire, unsigned int iemePlace);

/*!
 * Fonction qui nous permet de ajouter un Bit dans le CodeBinaire
 *\pre la longueur de CodeBinaire doit etre <256
 *\param[in] CodeBinaire le cBinaire dont on veut ajouter le bit
 *\param[in] bit  le bit que l'on veut ajouter
 */


void CB_ajouterBit(CodeBinaire *cBinaire, Bit bit);
/*!
 * Fonction qui nous permet de modifier un bit a la iemePLace dans le COdebinaire
 *\pre La place du bit que l'on veut modifier doit etre comprise entre 0 et la longueur de CodeBinaire
 *\param[in] CodeBinaire le cBinaire dont on veut modifier le Bit a la iemePlace
 *\param[in] iemePlace  la place dont on veut modifier le bit
 *\param[in] bit  le bit remplacant l'ancienne bit
 */


void CB_modifierIemeBit(CodeBinaire *cBinaire, unsigned int iemePlace, Bit bit);

/*!
 * Fonction qui nous permet de supprimer un bit a la iemePLace dans le COdebinaire
 *\pre La place du bit que l'on veut supprimer doit etre comprise entre 0 et la longueur de CodeBinaire
 *\param[in] CodeBinaire le cBinaire dont on veut supprimer le Bit a la iemePlace
 *\param[in] iemePlace  la place dont on veut supprimer le bit
 */



void CB_supprimerIemeBit(CodeBinaire *cBinaire, unsigned int iemePlace);

/*!
 * Fonction qui nous permet de comparer les deux CodeBinaires
 *\param[in] CodeBinaire1 le premier cBinaire qui l'on veut comparer
 *\param[in] CodeBinaire2 le deuxieme cBinaire qui l'on veut comparer
 *\return bool , Vrai si ils sont egaux , faux sinon
 */


bool CB_sontEgaux(CodeBinaire cBinaire1, CodeBinaire cBinaire2);

/*!
 * Fonction qui nous permet de obtenir l'octet de CodeBinaires
 *\pre La longueur de CodeBinaire doit etre <=8
 *\param[in] CodeBinaire  cBinaire qui l'on veut en octet
 *\return Octet , la valeur de codeBinaire en Octet
 */


Octet CB_codeBinaireEnOctet(CodeBinaire cBinaire);

#endif
