#include "cubo.h"

struct Cubo {
	int arestas;
};

cubo* criarCubo(){
	cubo *x;
	x = (cubo*) malloc(sizeof(cubo));
	if(x != NULL){
		x->arestas = 0;
	}
	return x;
}
void inserirValorAresta(int a, cubo *x){
	if(x == NULL){
		return;
	}
	x->arestas = a;
}

int calcularArea(cubo *x){
	int area;
	if(x == NULL){
		return 0;
	}
	return area = 6*((x->arestas)*(x->arestas));
}

int tamanhoAresta(cubo *x){
	if(x == NULL){
		return 0;
	}
	return x->arestas;
}
int perimetro(cubo *x){
	if(x == NULL){
		return 0;
	}
	return 12*x->arestas;
}
int volume(cubo *x){
	if(x == NULL){
		return 0;
	}
	return (x->arestas)*(x->arestas)*(x->arestas);
}
