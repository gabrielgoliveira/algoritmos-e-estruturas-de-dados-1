/*ok*/
#include <stdio.h>
#include <stdlib.h>
 
int* alocarVetor(int);
void lerVetor(int, int *);
int numTrocas(int, int *);
 
int main(){
    int casos;
    int tamanho_vetor;
    int *vetor;
    scanf("%d", &casos);
    while(casos--){
        scanf("%d", &tamanho_vetor);
        vetor = alocarVetor(tamanho_vetor);
        lerVetor(tamanho_vetor, vetor);
        printf("Numero  ideal  de  trocas  e  de  %d  troca(s).\n", numTrocas(tamanho_vetor, vetor));
        free(vetor);
    }
 
    return 0;
}
int* alocarVetor(int x){
    int *vetor;
    vetor = malloc(x*sizeof(int));
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
int numTrocas(int x, int *vetor){
    int i, j, num_trocas=0, aux;
    for(i=0;i<x;i++){
        for(j=0;j<x-1;j++){
            if(*(vetor+j) > *(vetor+j+1)){ //Fazer a troca se vet[j]>vet[j+1];
                num_trocas++;
                aux = *(vetor+j);
                *(vetor+j) = *(vetor+j+1);
                *(vetor+j+1) = aux;
            }   
 
            /*fim for j*/
        }
    }
    return num_trocas;
}