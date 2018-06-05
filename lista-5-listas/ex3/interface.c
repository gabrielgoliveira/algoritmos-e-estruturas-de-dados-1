#include "esfera.h"
int main(){
	float raio;
	esfera *e;

	e = criarEsfera();
	scanf("%f", &raio);
	setRaio(raio, e);
	printf("Raio: %.2f\n", getRaio(e));
	printf("Area Esfera: %.2f\n", calcularAreaEsfera(e));
	printf("Volume Esfera: %.2f\n", calcularVolumeEsfera(e));
	return 0;
}