#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*Para compilar uma TAD:

	- Primeiro é necessario compilar a implementação das funções, o arquivo: lista.c
		1) Flag -c do gcc tambem serve para compilar arquivos que não tem uma função
		main, logo ele não vai gerar um executavel do arquivo, mas sim um codigo
		objeto.
			Comando:
				gcc -c lista.c -o lista.o //gera um codigo objeto

				O gcc vai gerar um arquivo objeto

		2) Para Executar o Programa que utiliza da TAD, é necessario informar ao compilador onde
		está a implementação das funções (o arquivo compilado objeto).

			Comando:
				gcc mainLista.c lista.o -o mainLista //Gera o Executavel Compilado

		3) O arquivo .c consegue ver o arquivo .h, mas o inverso não é valido, então,
		se for declarado algum tipo ou função dentro do arquivo de implementação .c
		so ele tera acesso ao mesmo, funcionaria como um tipo privado de dados, pois
		so as funções do arquivo .c podera utiliza-las.
		
		
*/
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
