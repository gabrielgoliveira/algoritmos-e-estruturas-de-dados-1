#include <stdio.h>
#include <stdlib.h>

struct elemento {
	int x;
	struct elemento *link;
};
typedef struct elemento elem;
typedef struct elemento head;

head* criarCabeca();
void insertBack(int num, head *cabeca);
void imprimirElementos(head *cabeca);
void op(int x, head *cabeca);
int main(){
	head *cabeca;
	int flag;
	cabeca = criarCabeca();
	printf("\n\n---------- Lista Criada ---------- \n\n");
	do{
		printf("1 - Inserir Elementos\n");
		printf("2 - Imprimir Lista\n");
		printf("6 - Limpar Tela\n");
		printf("-1 para encerrar o programa\n");
		scanf("%d", &flag);
		op(flag, cabeca);
	}while(flag != -1);
	return 0;
}
head* criarCabeca(){
	head *cabeca;
	cabeca = (head*) malloc(sizeof(head));
	if(cabeca!=NULL){
		(*cabeca).link = NULL;
	}
	return cabeca;
}
void insertBack(int num, head *cabeca){
	head *novo = (head*) malloc(sizeof(head));
	head *temp;
	if(novo != NULL){
		if((*cabeca).link == NULL){
			//Lista vazia, inserir na primeira posição
			cabeca->link = novo;
			(*novo).link = NULL;
			(*novo).x = num;

		} else {
			//ja existe elementos na lista, nesse caso descobrir qual é o ultimo elemento
			temp = cabeca->link; //recuperando o primeiro elemento referenciado pela cabeca
			novo->x = num;
			novo->link = NULL;

			while(temp->link != NULL){
				temp = temp->link;
			}
			temp->link = novo;
			
		}
	}

}

void imprimirElementos(head *cabeca){
	head *temp;
	if((*cabeca).link == NULL){ //verifica lista vazia
		printf("NAO E POSSIVEL IMPRIMIR UMA LISTA VAZIA!!\n");
		exit(1);
	} else {
		printf("ELEMENTOS DA LISTA: \n");
		temp = (*cabeca).link; //pega primeiro elemento lista
		while(temp != NULL){ //loop ate chegar no ultimo
			printf("%d ", temp->x);
			temp = temp->link;
		}
		printf("\n\n");
	}
}

void op(int x, head *cabeca){
	int a;
	printf("Operacoes: \n\n");
	switch(x){
		case 1:
			printf("Digite um inteiro a ser inserido na lista: \n");
			scanf("%d", &a);
			insertBack(a, cabeca);
		break;
		case 2:
			imprimirElementos(cabeca);
		break;
		case 6: 
			system("cls");
		break;
		default:
			printf("Option Invalid\n");
	}
}