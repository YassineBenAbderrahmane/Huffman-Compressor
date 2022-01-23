#include <assert.h>
#include "octet.h"

Octet O_creerOctet(){
	return 0;
}

void O_ecrireIemeBit(Octet *o, unsigned int i, Bit b){
	assert((i > 0) & (i <= 8));

	int mask = 1 << (i-1); // un seul 1, en position i
	
	if(b){
		*o = *o | mask; // O = O AND mask
	}else{
		*o = *o & ~mask; // O = O AND (NOT mask)
	}
}

Bit O_lireIemeBit(Octet o, unsigned int i){
	assert((i > 0) & (i <= 8) );

	return (Bit) (o >> (i-1)) & 1;
}

bool O_sontEgaux(Octet o1, Octet o2){
	return o1 == o2;
}

unsigned int O_octetEnNaturel(Octet octet){
	assert((octet >=0) && (octet <= 255));

	return (unsigned int) octet;
}

unsigned char O_octetEnChar(Octet octet){
	assert((octet >=0) && (octet <= 255));

	return (unsigned char) octet;
}

Octet O_charEnOctet(unsigned char c){
	return (Octet) c;
}

Octet O_naturelEnOctet(unsigned int i){
	return (Octet) i;
}