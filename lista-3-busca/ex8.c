#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, i, aux;
    unsigned long long int produto=1, temp;
    int *vetor;
    scanf("%d", &n);
    vetor = malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d", (vetor+i));
        produto *= vetor[i]; 
    }
    i = 1;
    while(pow(i, n) < produto){
        i++;
    }
    aux = i;
    for(i=0;i<n;i++){
        vetor[i] = aux;
    }
    for(i=0;i<n;i++){
        printf("%d ", *(vetor+i)); 
    }
    return 0;
}