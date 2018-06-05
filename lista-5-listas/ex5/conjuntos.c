#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include “conjunto.h“
#define TAM 100 // trabalha com elementos do universo 0..TAM -1
typedef int elem;
struct conjunto {
elem* v; //vetor booleano que armazenará o conjunto sendo que
//o índice armazena o valor sendo true se o elemento está
// no conjunto, false caso contrário
};
void libera (Conjunto *A){
33
free(A->v);
free(A