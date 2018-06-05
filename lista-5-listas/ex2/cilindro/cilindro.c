#include "cilindro.h"

struct Cilindro {
	float altura;
	float raio;
};

cilindro* criarCilindro(){
	cilindro *x = NULL;
	x = (cilindro*) malloc(sizeof(cilindro));
	if(x!=NULL){
		x->altura = 0;
		x->raio = 0;
	}
	return x;
}
void setAltura(int altura, cilindro *x){
	if(x!=NULL){
		x->altura = altura;
	}

}
void setRaio(int raio, cilindro *x){
	if(x!=NULL){
		x->raio = raio;
	}	

}
float getAltura(cilindro *x){
	if(x!=NULL){
		return x->altura;
	}
	return 0; 
}

float getRaio(cilindro *x){
	if(x!=NULL){
		return x->raio;
	}
	return 0; 
}

float calcularAreaBase(cilindro *x){
	if(x!=NULL){
		return PI*((x->raio)*(x->raio));
	} else {
		return 0;
	}
	
}
float calcularAreaLateral(cilindro *x){
	if(x!=NULL){
		return 2*PI*x->raio*x->altura;	
	} else {
		return 0;
	}
	
}

float calcularVolume(cilindro *x){
	if(x != NULL){
		return calcularAreaBase(x)*x->altura;
	} else {
		return 0;
	}
	
}