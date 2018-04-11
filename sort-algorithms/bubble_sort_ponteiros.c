#include <stdio.h>
void bubbleSort(int *v);
int main(){

    int v[10], i;
    int *teste;
    teste = v;

    for(i=0;i<10;i++){
        printf("Digite o %d num: ", i);
        scanf(" %d", &v[i]);
    }

    bubbleSort(v);
    printf("O vetor ordenado eh \n");
    for(i=0;i<10;i++){
        printf("%d\n", v[i]);
    }
  
    return 0;
}

void bubbleSort(int *vetor){
    int i, j, temp;
    int *tempEnd = vetor;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            /*Os operadores no if está manipulando o endereço de memoria*/
            if(*vetor > *(vetor+1)){
                /*realizando o swap*/
                temp = *vetor;
                *vetor = *(vetor+1);
                *(vetor+1) = temp;
            }
            /*Pulando para o proximo endereço de memoria*/
            vetor++;
        }
        /*Setando o vetor para a posição inicial*/
       vetor = tempEnd;
    }
}