#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** alocaMatriz(int n);
void imprimeMatriz(int **matriz, int n);
int** MultMatrizNxN(int **matrizA, int **matrizB, int n);
void lerMatriz(int **matriz, int n);
void liberarMatriz(int **matriz, int n);

int main(){
    int n;
    int **matrizA, **matrizB, **matrizC;
    srand(time(NULL));
    n = rand() %20;
    if(n == 0){
        n=1;
    }

    printf("Matrizes Tamanho %dx%d\n", n, n);
    matrizA = alocaMatriz(n);
    matrizB = alocaMatriz(n);
/*  lerMatriz(matrizA, n);
    lerMatriz(matrizB, n);
*/
    imprimeMatriz(matrizA, n);
    printf("\n");
    imprimeMatriz(matrizB, n);

    matrizC = MultMatrizNxN(matrizA, matrizB, n);
    printf("\n");
    imprimeMatriz(matrizC, n);
    printf("O algoritmo gastou: %d passos para gerar a matriz\n", n*n*n);
    /*
    Na função onde é feita a multiplicação das matrizes a complexidade é n^3
    */
    // Liberar Memoria Alocada
    liberarMatriz(matrizA, n);
    liberarMatriz(matrizB, n);
    liberarMatriz(matrizC, n);
    return 0;
}
int** alocaMatriz(int n){
    int **matriz;
    int i, j;
    matriz = (int**) malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        matriz[i] = (int*) malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            matriz[i][j] = 100 - rand()%200; 
        }
    }
    if(matriz == NULL){
        printf("Erro de Alocacao na Memoria\n");
        exit(1);
    }else {
        return matriz;
    }
}
void imprimeMatriz(int **matriz, int n){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
int** MultMatrizNxN(int **matrizA, int **matrizB, int n){
    /*So matriz do tipo NxN*/
    int **matrizC;
    int i, j, k;
    matrizC = alocaMatriz(n);
    /*Complexidade n^3*/
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            // zerando matriz pois na aloca matriz ela recebe valores aleatorios
            matrizC[i][j]=0;
            for(k=0;k<n;k++){
                matrizC[i][j] += matrizA[i][k]*matrizB[k][j]; 
            }
        }
    }
    return matrizC;
}
void lerMatriz(int **matriz, int n){
    int i, j;
    printf("Lendo uma matriz Tamanho %dx%d\n", n, n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
void liberarMatriz(int **matriz, int n){
    int i;
    for(i=0;i<n;i++){
        free(matriz[i]);
    }
    free(matriz);
    
}