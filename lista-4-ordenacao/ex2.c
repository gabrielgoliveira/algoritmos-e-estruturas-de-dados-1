#include <stdio.h>
#include <stdlib.h>

int* alocarVetor(int);
void lerVetor(int, int *);
void ordenaVetor(int*, int);
int main(){
    int num, i;
    int *vetor;
    scanf("%d", &num);
    vetor = alocarVetor(num);
    lerVetor(num, vetor);
    ordenaVetor(vetor, num);
 /*
    printf("Vetor Ordenacao Final\n");
*/
    for(i=0;i<num;i++){
        printf("%d\n", vetor[i]);
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

void ordenaVetor(int *vetor, int x){
    int i, aux, flag=0, j, beggin_odd;
    //SEPARANDO AS PARTES PARES E IMPARES
    for(i=0;i<x;i++){
        if(vetor[i]%2!=0){
            while(!flag && j >=0){
                //j >=0 é pra assegurar que se não existir nenhum impar o programa não ira entrar em loop
                j=x-1;
                if(vetor[j]%2 == 0){
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                    flag = 1;
                } else {
                    flag++;
                }
            }
        }
    }
    i=0;
    //contando tamanho do vetor pares
    while(vetor[i]%2 == 0){
        i++;
    }
    beggin_odd = i;
 /*
    printf("Primeiro Impar: %d\n", beggin_odd);
    printf("\nVetor separado impar e par\n");
    for(int i=0;i<x;i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
*/
    //ordenando PARES
    i = beggin_odd;
    do{
        flag=0;
        for(j=0;j<=beggin_odd-2;j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                flag=j;
            }
        }
        beggin_odd--;
    }while(flag != 0);

    beggin_odd = i;
    //ordenando IMPARES
    do{
        flag=0;
        for(j=beggin_odd;j<x-1;j++){
            if(vetor[j] < vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                flag = j;
            }
        }
        x--;
    }while(flag!=0);
  
}