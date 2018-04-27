/*ok*/
#include <stdio.h>
#include <stdlib.h>

int* alocarVetor(int);
void lerVetor(int, int *);
void ordenarVetor(int, int *);
int ordemPrimo(int);
int primo(int num);

int main(){
    int tamanho, i;
    int *vetor;
    scanf("%d", &tamanho);
    vetor = alocarVetor(tamanho);
    
    lerVetor(tamanho, vetor);
    ordenarVetor(tamanho, vetor);
    for(i=0;i<tamanho;i++){
        vetor[i] = ordemPrimo(vetor[i]);
        printf("%d ", vetor[i]);
    }
    printf("\n");
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

int ordemPrimo(int ordem){

    int num = 2, i = 0;
    while(i<ordem){
        if(primo(num)){
            i++;
        } 
        num++;
    }
    num=num-1;
    return num;
}

int primo(int num){
    int cont = 0, boole, i = num;
    if(num == 1){
        return 0;
    }
    while(i>0){
        if(num%i == 0){
            cont++;
        }

        if(cont > 2 && i > 1){
            return 0;
        }   
        i--;
    }

    if(cont == 2){
        boole = 1;
    } else {
        boole = 0;
    }

    return boole;
}