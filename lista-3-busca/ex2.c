#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, dd, x, i, j;
    int *valor, *n_moedas;
    //numero de lanchonetes disponiveis
    scanf("%d", &n);
    valor = (int *) malloc(n*sizeof(int));
    if(valor == NULL){
        printf("Allocation Error\n");
        exit(1);
    }

    for(i =0;i<n;i++){
        //Valor do cafe em cada lanchonete
        scanf("%d", &valor[i]);
    }
    
    //numero de dias que o carinha quer comprar cafe
    scanf("%d", &dd);
    n_moedas = (int *) malloc(dd*sizeof(int));
    if(n_moedas == NULL){
        printf("Allocation Error\n");
        exit(1);
    }
    for(i=0;i<dd;i++){
        scanf("%d", &n_moedas[i]);
    }


/*Logica e Saida*/
    for(i=0;i<dd;i++){
        x=0;
        //repetir a quantidade de dias que o cara vai comprar cafe
        for(j=0;j<n;j++){
            //percorre vetor lanchonetes
            if(n_moedas[i] >= valor[j]){
                x++;
            }
        }
        printf("%d\n", x);
        
    }

    free(n_moedas);
    free(valor);
    return 0;
}