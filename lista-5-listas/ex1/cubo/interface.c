#include <stdio.h>
#include "cubo.h"

int main(){
	cubo *a;
	int aresta, area, valorVolume, valorPerimetro, valorAresta;	
	a = criarCubo();

	printf("Digite a Aresta do Cubo: \n");
	scanf("%d", &aresta);

	inserirValorAresta(aresta, a);
	area = calcularArea(a);
	valorAresta = tamanhoAresta(a);
	valorVolume = volume(a);
	valorPerimetro = perimetro(a);
	
	printf("Area: %d\nAresta: %d\nVolume: %d\nPerimetro: %d\n", area, valorAresta, valorVolume, valorPerimetro);
}