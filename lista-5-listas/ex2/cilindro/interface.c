#include "cilindro.h"

int main(){
	cilindro *c;
	int raio, altura;
	c = criarCilindro();
	printf("Digite o Raio e a Altura: \n");
	scanf("%d %d", &raio, &altura);
	setAltura(altura, c);
	setRaio(raio, c);
	/*Saida*/
	printf("Altura: %.2f\n", getAltura(c));
	printf("Raio: %.2f\n", getRaio(c));
	printf("Area Base: %.2f\n", calcularAreaBase(c));
	printf("Area Lateral: %.2f\n", calcularAreaLateral(c));
	printf("Volume: %.2f\n", calcularVolume(c));

	return 0;
}