#include <stdio.h>
#include <stdlib.h>

char** alocarMatriz(int, int);

int main(){
    int i, j;
    int nCasos, linhas, colunas;
    char **campo;
    scanf("%d", &nCasos);
    while(nCasos--){
        scanf("%d %d", &linhas, &colunas);
        campo = alocarMatriz(linhas, colunas);
     
        for(i=0;i<linhas;i++){
            for(j=0;j<colunas;j++){
                scanf("%c", &campo[i][j]);
            }
        }
/*
        for(i=0;i<linhas;i++){
            for(j=0;j<colunas;j++){
                printf("%c ", campo[i][j]);
            }
            printf("\n");
        }
*/
        free(campo);

    }   

    return 0;
}
char** alocarMatriz(int linhas, int colunas){
    int i;
    char **campo = (char**) malloc(linhas*sizeof(char*));;
    for(i=0;i<linhas;i++){
        campo[i] = (char*) malloc(colunas*sizeof(char));
    }

    if(campo == NULL){
        printf("Allocation Error\n");
        exit(1);
    }else {
        printf("Matriz Alocada Porra\n");
    }
    return campo;
}