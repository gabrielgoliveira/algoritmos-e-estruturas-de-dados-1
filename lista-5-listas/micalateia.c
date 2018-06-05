#include <stdio.h>
#include <stdlib>

struct Contatos {
	char nome[30];
	long int telefone;
	int quant; 
};
typedef Contatos contato;

struct Lista {
	contatos x;
	struct Lista *linker;
};
typedef Lista lista;
/*
struct Lista {
	
	struct Lista *linker;
};
typedef No elemento;
*/

lista* criarAgenda();
int listaVazia(lista *cabeca);
void op(char c);

int main(){
	char c = '1';
	lista *agenda;
	agenda = criarAgenda;
	while(c!='S'){
		scanf("%c", &c);
		op(c);
	}
}
lista* criarAgenda(){
	lista *cabeca;
	cabeca = (lista*) malloc(sizeof(lista));
	if(cabeca!=NULL){
		cabeca->prox = NULL;
	}
	return cabeca;
}
int listaVazia(lista *cabeca){
	if(cabeca->prox == NULL){
		return 1;
	} else {
		return 0;
	}
}
int inserction(cabeca){
	lista contato;
	printf("Insira o Nome do Contato: \n");
	scanf("%[^\n]s ", contato->nome);
	printf("Insira o Telefone do Contato: \n");
	scanf("%ld", &(contato->telefone));
	printf("Quantidade de Vezes que foi ligado: \n");
	scanf("%d", &(contato->quant));
	if(!listaVazia(cabeca)){
		//lista vazia inserir no primeiro no
		cabeca->prox
	}
}
void op(char c, lista *cabeca){
	
	switch(c){
		case 'I':
			inserction(cabeca);
		break;

		case 'G':

		break;
	}
}