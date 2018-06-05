#include <stdio.h> //constante NULL
#include <stdlib.h> //malloc
#define PI 3.141592

typedef struct Esfera esfera;

esfera* criarEsfera();
void setRaio(int raio, esfera *x);
float getRaio(esfera *x);
float calcularAreaEsfera(esfera *x);
float calcularVolumeEsfera(esfera *x);
