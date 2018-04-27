/*ok*/
#include <stdio.h>
#include <stdlib.h>

int* alocarVetor(int);
void lerVetor(int, int *);
void ordenarVetor(int, int *);

int main(){
    int tamanho, l, k, soma;
    int *vetor;
    scanf("%d", &tamanho);
    vetor = alocarVetor(tamanho);
    lerVetor(tamanho, vetor);
    ordenarVetor(tamanho, vetor);
    scanf("%d %d", &l, &k);
    l = l-1;
    k = k-1;
    soma = vetor[l] + vetor[k];
    printf("%d\n", soma);

    return 0;
}
int* alocarVetor(int x){
    int *vetor;
    vetor = (int*) malloc(x*sizeof(int));
    if(vetor == NULL){
        printf("Erro de Alocacao\n");
        exit(1);
    } else {
        return vetor;
    }
} 
void lerVetor(int x, int *vetor){
    int i;
    for(i=0;i<x;i++){
        scanf("%d", vetor+i);
    }
}

void ordenarVetor(int x, int *vetor){
    int aux, continua, i;
    do{
        continua=0;
        for(i=0;i<x-1;i++){
            if(vetor[i]>vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                continua = i;
            }
        }
        x--;
    }while(continua!=0);
}
