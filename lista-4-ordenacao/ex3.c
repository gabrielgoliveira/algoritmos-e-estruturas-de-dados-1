/*ok*/
#include <stdio.h>
#include <stdlib.h>

int* alocarVetor(int);
void lerVetor(int, int *);
void ordenarVetor(int, int *);
int main(){
    int casos, pessoas, i;
    int *vetor;
    scanf("%d", &casos);
    while(casos--){
        scanf("%d", &pessoas);
        vetor = alocarVetor(pessoas);
        lerVetor(pessoas, vetor);
        ordenarVetor(pessoas, vetor);
        for(i=0;i<pessoas;i++){
            printf("%d ", vetor[i]);
        }
        printf("\n");
        free(vetor);
    }
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