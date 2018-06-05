#include <stdio.h>
#include <stdlib.h>

int main(){
	inimigos *lista;
	int n, i, aux;
	char c;

	lista = criarLista();
	//printf("Insira a Quantidade de Nos Iniciais: ");
	scanf("%d", &n);
	//inserindo n nós na lista
	//printf("Insira os Nos: \n");
	for(i=0;i<n;i++){
		criarNoFinal(lista);
	}
	//lendo as operações
	do{	
		/*
		printf("Operacoes: \n");
		printf("I - Inserir (pessoa, elemento)\nR - Remova Inimigo e\nQ - Quantidade Inimigos Entre A e B\nOp: ");
		*/
		scanf(" %c", &c);
		operacao(c, lista);
		//imprimirLista(lista);
	}while(c != 'F');
	

	return 0;
}
