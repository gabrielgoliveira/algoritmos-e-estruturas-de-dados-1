#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct r {
    char nome[20];
    int pontos;
}Ranking;

void swap(Ranking *, Ranking *);
void ordenacaoNota (Ranking *, int);
void ordenacaoNome(Ranking *, int n);

int main(){
    Ranking *placar;
    int n, i;
    char buffer[50];
    scanf("%d", &n);
    placar = (Ranking *) malloc(n*sizeof(Ranking));
    i=0;
    while(n--){
        scanf("%s %d", placar[i].nome, &placar[i].pontos);
        i++;
    }
    n=i;
    ordenacaoNota(placar, n);
    ordenacaoNome(placar, n);

    for(i=0;i<n;i++){
        printf("%s %d\n", placar[i].nome, placar[i].pontos);
    }

    free(placar);
    return 0;
}

void ordenacaoNota (Ranking *placar, int n){
    int i, continuar;
    char buffer[50];
    char aux;
    //bubble sort
    do {
        continuar = 0;
        for(i=0;i<n-1;i++){
            if(placar[i].pontos < placar[i+1].pontos){
                swap(&placar[i], &placar[i+1]);
                continuar = i;
            }
        }
        n--;
    }while(continuar);
}
void swap(Ranking *a, Ranking *b){
    char buffer[50];
    int aux;
    //salvando o a nas variaveis auxiliares
    strcpy(buffer, a->nome);
    aux = a->pontos;
    //copiando b para a
    strcpy(a->nome, b->nome);
    a->pontos = b->pontos;
    //copiando a pra b
    strcpy(b->nome, buffer);
    b->pontos = aux;
}

void ordenacaoNome(Ranking *placar, int n){
    int i, j, a, b;
    for(i=0;i<(n-1);i++){
        if(placar[i].pontos == placar[i+1].pontos){
            j=0;
            do{
                if(placar[i].nome[j] == placar[i+1].nome[j]){
                    j++;
                }
            }while( (placar[i].nome[j] == placar[i+1].nome[j]) || placar[i].nome[j]=='\0');

            a = placar[i].nome[j];
            b = placar[i+1].nome[j];

            if(a>b){
                swap(&placar[i], &placar[i+1]);
            }
        }
    }
    
}