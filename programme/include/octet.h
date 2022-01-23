#ifndef _OCTET_
#define _OCTET_
#include <stdbool.h>

typedef enum {bitA0=0,bitA1=1} Bit;

/*!
 *\struct Octet octet.h "Octet"
 */
typedef unsigned int Octet;

/*!
 *\fn Octet O_creerOctet()
 *\brief Creation d'un octet
 * 
 *\return un octet initialisé à 0 (00000000)
 */
Octet O_creerOctet();

/*!
 *\fn void O_ecrireIemeBit(Octet *o, unsigned int i, Bit b);
 *\brief Modifier un bit
 *\param[in, out] o l'octet a modifier
 *\param[in] i le numéro du bit a modifier (ordre: 87654321)
 *\param[in] b le nouveau bit
 */
void O_ecrireIemeBit(Octet *o, unsigned int i, Bit b);

/*!
 *\fn Bit O_lireIemeBit(Octet o, unsigned int i);
 *\brief Lire un bit
 *\param[in] o l'octet a lire
 *\param[in] i le numéro du bit a lire
 *\return Le Ieme bit
 */
Bit O_lireIemeBit(Octet o, unsigned int i);

/*!
 *\fn bool O_sontEgaux(Octet o1, Octet o2);
 *\brief Test d'égalité
 *\param[in] o1 octet 1
 *\param[in] o2 octet 2
 *\return Retourne vrai si la valeur des octets est la même, faux sinon
 */
bool O_sontEgaux(Octet o1, Octet o2);

/*!
 *\fn unsigned int O_octetEnNaturel(Octet octet);
 *\brief Transformation en unsigned int
 *\param[in] octet l'octet a transformer en naturel
 *\return unsigned int correspondant a la valeur de l'octet (somme des 2^(indice-1))
 */
unsigned int O_octetEnNaturel(Octet octet);

/*!
 *\fn unsigned char O_octetEnChar(Octet octet);
 *\brief Transformation en unsigned char
 *\param[in] octet l'octet a transformer en caractère
 *\return unsigned char correspondant a la valeur de l'octet (somme des 2^(indice-1))
 */
unsigned char O_octetEnChar(Octet octet);

/*!
 *\fn Octet O_charEnOctet(unsigned char c);
 *\brief Transformation d'un char en Octet
 *\param[in] c le caractère a transformer en octet
 *\return un octet
 */
Octet O_charEnOctet(unsigned char c);

/*!
 *\fn Octet O_naturelEnOctet(unsigned int i);
 *\brief Transformation d'un naturel en Octet
 *\param[in] i le naturel a transformer en octet
 *\return un octet
 */
Octet O_naturelEnOctet(unsigned int i);

#endif