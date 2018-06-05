/*Interface Publica
- Prototipagem de Funções
- Estrutura de Dados
*/



#include <stdio.h>
#include <stdlib.h>

struct Inimigos {
	int x;
	struct Inimigos *prox;
};
typedef struct Inimigos inimigos;

//prototipagem das funções
inimigos* criarLista();
void criarNoFinal(inimigos *Head);
void imprimirLista(inimigos *Head);
void operacao(char, inimigos *);
int insercaoAposX(int, int, inimigos *);
int removeX(int, inimigos *);
int quantidadeEntreAeB(int, int, inimigos*);
