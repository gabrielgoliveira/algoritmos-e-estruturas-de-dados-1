//implementação do tipo abstrato de tados lista.h

#include "lista.h" //incluindo o arquivo de cabeçalho

/* Depois de incluir o arquivo lista.h
esse arquivo vai enchergar tudo que está nele*/

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
	scanf("%d", &(no->x));
	no->prox=NULL;

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
}

void imprimirLista(inimigos *Head){
	printf("IMPRIMIR LISTA\n");
	inimigos *temp;
	if(Head->prox == NULL){
		printf("NAO E POSSIVEL IMPRIMIR UMA LISTA VAZIA !!!\n");
		exit(1);
	}
	temp = Head->prox;
	while(temp != NULL){
		printf("%d ", temp->x);
		temp = temp->prox;
	}
	printf("\n");
}
int insercaoAposX(int p, int e, inimigos *Head){
	//e: é o nó no qual vai ser inserido um novo apos ele
	inimigos *novo = (inimigos*) malloc(sizeof(inimigos));
	inimigos *temp;
	void *aux;
	int flag = 0; 
	if(novo == NULL){
		printf("Erro de Alocacao\n");
		return 0;
	}
	//indexando inimigo ao nó criado
	novo->x = p;
	//procura do elemento e
	temp = Head->prox; //primeiro no da lista, considerando uma lista nao vazia
	while(temp->x != e){
		temp = temp->prox;
	}
	if(temp->x == e){
		flag=1;
		aux = (inimigos*) temp->prox; //ponteiro antigo
		temp->prox = novo; //apontando para o nó novo
		novo->prox = aux; //apontando o nó novo ao antigo
	}
	return flag;
}
int removeX(int p, inimigos *head){
	inimigos *temp;
	inimigos *aux_anterior = NULL;
	inimigos *aux_sucessor = NULL;
	temp = head->prox;
	if(temp == NULL){
		printf("Lista Vazia\n");
		return 0;
	}
	while(temp->x != p){
		if(temp->prox->x == p){
			aux_anterior = temp;
		}
		temp = temp->prox;
		if(temp->x == p){
			aux_sucessor = temp->prox;
		}
	}
	if(temp->x == p){
		//achou elemento
		aux_anterior->prox = aux_sucessor;
		free(temp);
		return 1;
	}
}
int quantidadeEntreAeB(int a, int b, inimigos *Head){
	inimigos *temp, *inicio;
	int cont = 0;
	temp = Head->prox;
	if(a == b){
		printf("%d\n", -1);
		return 0;
	}
	while(temp->x != a){
		//procurando elemento a
		if(temp->x == b){
			quantidadeEntreAeB(b, a, Head); //CASO O SEGUNDO ARGUMENTO VENHA ANTES DE A, CHAMAR A FUNÇÃO NOVAMENTE INVERTENDO OS ARGUMENTOS
			return 1; //IMPEDIR QUE A FUNÇÃO MOSTRE OUTRA SAIDA
		}
		temp = temp->prox;
	}
	if(temp->x == a){
		inicio = temp->prox;
		while(inicio->x != b){
			//procura de A até B incluindo B
			inicio = inicio->prox;
			cont++;
		}
	}
	printf("%d\n", cont);
	return cont;
}
void operacao(char c, inimigos *Head){
	int p, e, a, b;
	if(c == 'I'){
		//inserção
		scanf(" %d %d", &e, &p);
		insercaoAposX(e, p, Head);
	} else if(c == 'R'){
		//remove
		scanf(" %d", &p);
		removeX(p, Head);
	} else if(c == 'Q'){
		//quantos inimigos estao na lista entre a e b excluindo a e b
		scanf(" %d %d", &a,  &b);
		quantidadeEntreAeB(a, b, Head);
	} else if(c == 'F'){
		return ;
	} else {
		printf("Operacao Invalida\n");
		return ;
	}
}
