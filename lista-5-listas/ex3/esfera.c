#include "esfera.h"

struct Esfera {
	float raio;	
};

esfera* criarEsfera(){
	esfera *x;
	x = (esfera*) malloc(sizeof(esfera));
	if(x != NULL){
		x->raio = 0;
	}
	return x;
}

void setRaio(int raio, esfera *x){
	if(x != NULL){
		x->raio = raio;
	}
}

float getRaio(esfera *x){
	if(x != NULL){
		return x->raio;
	} else {
		return -1;
	}
}

float calcularAreaEsfera(esfera *x){
	float raio;
	if(x != NULL){
		raio = x->raio;
		return 4*PI*(raio*raio);
	} else {
		return -1;
	}
}

float calcularVolumeEsfera(esfera *x){
	float raio;
	if(x != NULL){
		raio = x->raio;
		return (4/3)*PI*(raio*raio*raio);
	} else {
		return -1;
	}
}
