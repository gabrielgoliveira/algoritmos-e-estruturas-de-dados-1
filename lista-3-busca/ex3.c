#include <stdio.h>
#include <stdlib.h>
char* alocaString(char *);
int contaVogal(char *);

int main(){
    int n, aux;
    char buffer[100];
    char *trees;

    scanf("%d", &n);
    while(n--){
        scanf(" %[^\n]s", buffer);
        trees = alocaString(buffer);
        aux = contaVogal(trees);
        printf("%d\n", aux);
    }
    return 0;
}
int contaVogal(char *frase){
    int i=0, cont=0, j;
    int vogais[] = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};
    while(frase[i]!='\0'){
        for(j=0;j<10;j++){
            if(frase[i] == vogais[j]){
                cont++;
                //parar de buscar no vetor pois a vogal ja foi encontrada
                break;
            }
        }
        i++;
    }
    return cont;
}
char* alocaString(char *frase){
/*Essa função recebe um frase e o aloca em 
outro de tamanho exato copia a frase pra ele 
e o retorna*/
    char *string;
    int i=0, j;
    while(frase[i]!='\0'){
        i++;
    }
    i++; //adicionando o caracter \0
    string = (char*) malloc(i*sizeof(char));
    if(string == NULL){
        exit(1);
    }
    for(j=0;j<i-1;j++){
        string[j] = frase[j];
    }
    string[i-1] = '\0';
    return string;

}