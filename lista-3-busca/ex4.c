#include <stdio.h>
#include <stdlib.h>

char** alocarMatriz(int);
int miniMundo(char **mundo, int linhas, int k);

int main(){
    int i, j,total;
    int nCasos, linhas, k;
    char **campo;
    scanf("%d", &nCasos);
    while(nCasos--){
        scanf("%d %d", &linhas, &k);
        campo = alocarMatriz(linhas);
     
        for(i=0;i<linhas;i++){
            for(j=0;j<linhas;j++){
                scanf(" %c", &campo[i][j]);
            }
        }
        total = miniMundo(campo, linhas, k);
        printf("%d\n", total);
        free(campo);

    }   

    return 0;
}
char** alocarMatriz(int linhas){
    int i;
    char **campo = (char**) malloc(linhas*sizeof(char*));;
    for(i=0;i<linhas;i++){
        campo[i] = (char*) malloc(linhas*sizeof(char));
    }

    if(campo == NULL){
        //printf("Allocation Error\n");
        exit(1);
    }else {
        //printf("Matriz Alocada\n");
    }
    return campo;
}

int miniMundo(char **mundo, int linhas, int k){
    int i, j, l, total=0, cont, proc;
 
    for(i=0;i<linhas;i++){
        for(j=0;j<linhas;j++){
            if(mundo[i][j] == 'P'){
                proc=k;
                cont=1;
                while(proc--){
                    /*Movimentando para trás*/
                    if(mundo[i][j-cont] == 'L' && ((j-cont)>=0)){
                        mundo[i][j-cont] = '0';
                        total++;
                        break;
                    }else if(mundo[i][j+cont] == 'L' && ((j+cont)<linhas)){
                        /*Movimentando pra frente*/
                        mundo[i][j+cont] = '0';
                        total++;
                        break;
                    }
                    cont++;
                }

            }
        }
    }

    return total;
}