#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592

typedef struct Cilindro cilindro;

cilindro* criarCilindro();
void setAltura(int altura, cilindro *x);
void setRaio(int raio, cilindro *x);
float getAltura(cilindro *x);
float getRaio(cilindro *x);
float calcularAreaBase(cilindro *x);
float calcularAreaLateral(cilindro *x);
float calcularVolume(cilindro *x);