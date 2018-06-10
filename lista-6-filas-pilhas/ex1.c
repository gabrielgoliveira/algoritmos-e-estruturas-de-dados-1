#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 
typedef struct no_fila{
    int chegada, limite;
    struct no_fila *previous, *next;
}NO_fila;
 
typedef struct fila{
    int quantidade;
    NO_fila *inicio, *fim;
}Fila;
 
void inicializaFila(Fila *fila){
    fila->fim = NULL;
    fila->inicio = NULL;
    fila->quantidade = 0;
}
 
void insereNoFinalDaFila(Fila *fila, int chegada, int limite){
    NO_fila *novo;
    novo = (NO_fila*) malloc(sizeof(NO_fila));
    novo->previous = fila->fim;
    novo->next = NULL;
    novo->chegada = chegada;
    novo->limite = limite;
 
    if( fila->fim == NULL ){
        fila->inicio = fila->fim = novo;
    }
    else{
        fila->fim->next = novo;
        fila->fim = novo;
    }
 
    fila->quantidade++;
}
 
bool filaVazia(Fila *fila){
    if(!fila->quantidade) return true;
    return false;
}
 
void removeDaFrenteDaFila(Fila *fila){
    NO_fila *remover;
    remover = (NO_fila*) malloc(sizeof(NO_fila));
    remover = fila->inicio;
    
    fila->inicio = fila->inicio->next;
    if(fila->inicio == NULL) fila->fim = NULL;
    else fila->inicio->previous = NULL;
 
    free(remover); remover = NULL;
    fila->quantidade--;
}
 
int obtemFrenteDaFilaChegada(Fila *fila){
    return fila->inicio->chegada;
}
 
int obtemFrenteDaFilaLimite(Fila *fila){
    return fila->inicio->limite;
}
 
 
int main(){
    int n, i, hora, min, chegada, limite;
    int tempoAtual = 7*60, ans = 0;
    Fila *fila = (Fila*) malloc(sizeof(Fila));
 
    scanf("%d", &n);
 
    for(i = 0; i < n; i++){
        scanf("%d %d %d", &hora, &min, &limite);
        chegada = hora * 60 + min;
        insereNoFinalDaFila(fila, chegada, chegada + limite);
    }
 
    while( tempoAtual + 30 < obtemFrenteDaFilaChegada(fila) ){
        tempoAtual += 30;
    }
    removeDaFrenteDaFila(fila);
    while( !filaVazia(fila) ){
        tempoAtual += 30;
 
        if( tempoAtual >= obtemFrenteDaFilaChegada(fila) ){
            if( tempoAtual > obtemFrenteDaFilaLimite(fila) ){
                ans++;
                //tempoAtual -= 30;
            }
            removeDaFrenteDaFila(fila);
        }
    }
 
    printf("%d\n", ans);
 
    return 0;
}