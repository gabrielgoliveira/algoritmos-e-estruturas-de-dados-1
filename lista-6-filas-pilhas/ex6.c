#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char str[10000];

typedef struct _data_node {
	char x;
}data_node;

typedef struct _no {
	data_node data;
	struct _no *previous, *next;
}node;

typedef struct _stack {
	int size;
	node *start, *end;
}stack;

stack* createStack();
bool emptyStack(stack *header);
void push(stack *header, data_node info);
void pop(stack *header);
bool checkSeEvalida();

int main(){

	scanf("%s", str);

	if(checkSeEvalida()){
		printf("Correta\n");
	} else {
		printf("Incorreta\n");
	}

	return 0;
}

bool checkSeEvalida(){
    int i, qtd = 0;
    for(i = 0; i < strlen(str); i++){
        if( str[i] == '(' ) qtd++;
        else if( str[i] == ')' ) qtd--;
        if( qtd < 0 ) return false;
    }
    return (qtd == 0);
}

stack* createStack(){
	stack *start = (stack*) malloc(sizeof(stack));
	if(start != NULL){
		start->size = 0;
		start->start = NULL;
		start->end = NULL;
	}
}
bool emptyStack(stack *header){
	if(header==NULL){
		return false;
	}
	return (header->start == NULL);
}
void push(stack *header, data_node info){
	//stack insertion in finish list
	node *new_node = (node*) malloc(sizeof(node));
	if(new_node == NULL || header == NULL){
		return ;
	}
	new_node->data = info;
	new_node->next = NULL; 
	if(emptyStack(header)){
		//if stack be empty
		header->start = new_node;
		header->end = new_node;
		new_node->previous = NULL;
	} else {
		new_node->previous = header->end; //linking new node to old node
		header->end->next = new_node; //linking old node to new node
		header->end = new_node; //linking end stack to new node
	}
	header->size++;
}

void pop(stack *header){
	node *delet;
	delet = header->end;
	header->end = header->end->previous;
	free(delet);
	delet = NULL;
	header->size--;
}

