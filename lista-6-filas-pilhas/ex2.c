#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int valor[1000];
char nome[1000][50];
int used[1000];
 
int obtemPrimeiroLivre(int n){
    int i = 0;
    for(i =0; i < n; i++){
        if( used[i] == 0 ){
            return i;
        }
    }
    return 0;
}
 
int main(){
    int n, i, j, valorAt, posAt, aux, prox, valorQt;
 
    scanf("%d", &n);
 
    for(i = 0; i < n; i++){
        scanf("%s %d", nome[i], &valor[i]);
    }    
 
    valorQt = valor[0];
    for(i = 0; i < n-1; i++){
        posAt = obtemPrimeiroLivre(n);
        if( !(valorQt % 2) ){
            prox = posAt;
            for(j = 0; j < valorQt; ){
                prox = ((prox-1)+n)%n;
                while(true){
                    if( used[prox] == 0 ){
                        //printf(" = %s\n", nome[prox]);
                        j++;
                        break;
                    }
                    prox = ((prox-1)+n)%n;
                }
            }
            used[prox] = 1;
            valorQt = valor[prox];
            //printf("<- %s\n", nome[prox]);
        }
        else{
            prox = posAt;
            for(j = 0; j < valorQt; ){
                prox = (prox+1)%n;
                while(true){
                    if( used[prox] == 0 ){
                        j++;
                        //printf(" = %s\n", nome[prox]);
                        break;
                    }
                    prox = (prox+1)%n;
                }
            }
            used[prox] = 1;
            valorQt = valor[prox];
            //printf("-> %s\n", nome[prox]);
        }
    }
 
    for(i = 0; i < n; i++){
        if( used[i] == 0 ){
            printf("Vencedor(a) : %s\n", nome[i]);
        }
    }
 
    return 0;
}