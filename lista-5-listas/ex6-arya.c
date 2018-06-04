#include <stdio.h>
#include <stdlib.h>

struct Inimigos {
	int x;
	struct Inimigos *prox;
};
typedef struct Inimigos inimigos;

inimigos* criarLista();
void criarNoFinal(inimigos *Head);
void imprimirLista(inimigos *Head);

int main(){
	inimigos *lista;
	int n, i, aux;
	lista = criarLista();
	scanf("%d", &n);
	for(i=0;i<n;i++){
		criarNoFinal(lista);
	}
	printf("chamada funcao imprimir");
	imprimirLista(lista);

	return 0;
}
inimigos* criarLista(){
	inimigos *Head = NULL;
	Head = (inimigos*) malloc(sizeof(inimigos));
	if(Head != NULL){
		Head->prox = NULL;
	}
	return Head;
}

void criarNoFinal(inimigos *Head){
	
	inimigos *no = NULL;
	inimigos *temp;
	no = (inimigos*) malloc(sizeof(inimigos));

	if(no == NULL){
		printf("Erro na alocacao de memoria\n");
		exit(1);
	} 
	//entrada de elemento via teclado
	scanf("%d", &no->x);

	//inserção
	if(Head->prox == NULL){
		//lista vazia
		no->prox = NULL;
		Head->prox = no;
	} else {
		//lista não vazia
		temp = Head->prox; //acessando o primeiro elemento
		while(temp->prox != NULL){
			//iterando até o ultimo elemento
			temp = temp->prox;
		}
		temp->prox = no;
	}
	printf("Sucesso ao Criar No\n");
}

void imprimirLista(inimigos *Head){
	printf("IMPRIMIR LISTA\n");
	inimigos *temp;
	if(Head->prox == NULL){
		printf("NAO E POSSIVEL IMPRIMIR UMA LISTA VAZIA !!!\n");
		exit(1);
	}
	temp = Head->prox;
	while(temp->prox != NULL){
		printf("1 %d ", temp->x);
		temp = temp->prox;
	}
	printf("\n");
}