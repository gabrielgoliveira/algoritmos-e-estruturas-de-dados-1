#include <stdlib.h>

typedef struct Cubo cubo;

cubo* criarCubo();
void inserirValorAresta(int a, cubo *x);
int calcularArea(cubo *x);
int tamanhoAresta(cubo *x);
int perimetro(cubo *x);
int volume(cubo *x);