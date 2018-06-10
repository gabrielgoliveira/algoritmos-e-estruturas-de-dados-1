#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
 
char str[10000];
 
typedef struct NO_pilha{
    char valor;
    struct NO_pilha *previous, *next;
}NO_pilha;
 
typedef struct pilha{
    int quantidade;
    NO_pilha*inicio, *fim;
}Pilha;
 
void inicializaPilha(Pilha *pilha){
    pilha->fim = NULL;
    pilha->inicio = NULL;
    pilha->quantidade = 0;
}
 
void insereNoTopoDaPilha(Pilha *pilha, char valor){
    NO_pilha*novo;
    novo = (NO_pilha*) malloc(sizeof(NO_pilha));
    novo->previous = pilha->fim;
    novo->next = NULL;
    
    novo->valor = valor;
 
    if( pilha->inicio == NULL ){
        pilha->inicio = pilha->fim = novo;
    }
    else{
        novo->next = pilha->inicio;
        pilha->inicio = novo;
    }
 
    pilha->quantidade++;
}
 
bool pilhaVazia(Pilha *pilha){
    if(!pilha->quantidade) return true;
    return false;
}
 
void removeDoTopoDaPilha(Pilha *pilha){
    NO_pilha *remover;
    remover = (NO_pilha*) malloc(sizeof(NO_pilha));
    
    remover = pilha->inicio;
    pilha->inicio = pilha->inicio->next;
    if(pilha->inicio == NULL) pilha->fim = NULL;
    else pilha->inicio->previous = NULL;
 
    free(remover); remover = NULL;
    pilha->quantidade--;
}
 
char obtemTopoDaPilha(Pilha *pilha){
    return pilha->inicio->valor;
}
 
 
bool checkSeEvalida(){
    Pilha *pilha = NULL;
    pilha = (Pilha*) malloc(sizeof(Pilha));
    
    int i, qtd = 0;
    for(i = 0; i < strlen(str); i++){
        if( str[i] == '(' ) insereNoTopoDaPilha(pilha, '(');
        else if( str[i] == ')' ){
            if( pilhaVazia(pilha) || obtemTopoDaPilha(pilha) != '(' ) return false;
            removeDoTopoDaPilha(pilha);
        }
    }
    return pilhaVazia(pilha);
}
 
int main(){
    char at;
    int i;
    int prioridade[500];
    prioridade['+'] = prioridade['-'] = 0;
    prioridade['/'] = prioridade['*'] = 1;
    prioridade['^'] = 2;
    prioridade['('] = -1;
 
    Pilha *pilha = NULL;
    pilha = (Pilha*) malloc(sizeof(Pilha));
    bool flag = false;
    while(scanf("%s", str) != EOF){
        //if( flag ) printf("\n");
        printf("%s\n", str);
        bool ok = false;
        if( checkSeEvalida() ){
            for(i = 0; i < strlen(str); i++){
                if( str[i] == '(' ){
                    insereNoTopoDaPilha(pilha, '(');
                }
                else if( str[i] == ')' ){
                    at = '$';
                    while( !pilhaVazia(pilha) && at != '('){
                        at = obtemTopoDaPilha(pilha);
                        if( at != '(' ){
                            if( ok ) printf(" ");
                            ok = true;
                            printf("%c", at);
                        }
                        removeDoTopoDaPilha(pilha);
                    }
                }
                else if ( isalpha(str[i]) || isdigit(str[i]) ) {
                    if( ok ) printf(" ");
                    ok = true;
                    printf("%c", str[i]);
                }
                else{
                    while( !pilhaVazia(pilha) && prioridade[obtemTopoDaPilha(pilha)] >= prioridade[str[i]] ){
                        if( ok ) printf(" ");
                        ok = true;
                        printf("%c", obtemTopoDaPilha(pilha));
                        removeDoTopoDaPilha(pilha);
                    }
                    insereNoTopoDaPilha(pilha, str[i]);
                }
            }
            while(!pilhaVazia(pilha)){
                if( ok ) printf(" ");
                ok = true;
                printf("%c", obtemTopoDaPilha(pilha));
                removeDoTopoDaPilha(pilha);
            }
            printf("\n\n");
        }
        else{
            printf("Expressao invalida\n\n");
        }
    }
}