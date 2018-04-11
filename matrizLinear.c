#include <stdio.h>
#include <stdlib.h>

int* alocaVetor(int);
int* alocaMatriz(int, int);

int main(){
    int i;
    int *vetor;
    vetor = alocaVetor(3);
    alocaMatriz(3, 3);
    for(i=0;i<3;i++){
        printf("%d ", vetor[i]);
    }
    return 0;
}

 int *alocaVetor(int linha){
     int *campo = (int *) malloc(linha*sizeof(int));
     for(int i=0;i<linha;i++){
         campo[i]=0;
     }
     return campo;
 }

int* alocaMatriz(int linha, int coluna)
{
    int i,j;
    int *campo = (int *)malloc(linha*coluna*sizeof(int));

    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            campo[i+linha*j] = 0; //Inicializa com 0.
            printf("%d ", campo[i+linha*j]);

/*          coluna = 3
            linha = 3
            i=0;
            campo[0+3*0] -> pos 0
            campo[0+3*1] -> pos 3
            campo[0+3*2] -> pos 6
            i=1;
            campo[1+3*0] -> pos 1
            campo[1+3*1] -> pos 4
            campo[1+3*2] -> pos 7
            i=2;
            campo[2+3*0] -> pos 2
            campo[2+3*1] -> pos 5
            campo[2+3*2] -> pos 8
            


*/
        }
        printf("\n");
    }
    campo[0+linha*0]=1;
    return campo;
}
