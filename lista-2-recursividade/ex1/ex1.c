#include <stdio.h>
 
int imprimirNaturais(int n);
 
int main(){
    int n;
    scanf("%d", &n);
    imprimirNaturais(n);
    return 0; 
}
 
int imprimirNaturais(int n){
    if(n == 0){
        return 0;
    }
    imprimirNaturais(n-1);
    printf("%d ", n);
}
