#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** alocarCampo(int, int);
void liberarCampo(char **matriz, int linhas);

int main(){

	int l, c, i, j, quant_ataques, pos1, pos2;
	char **campo;	
	char *buffer;
	
	scanf("%d %d", &l, &c);
	/*Alocação Dinamica*/
	campo = alocarCampo(l, c);
	buffer = (char *) malloc((c+1)*sizeof(char));
	
	/*lendo a matriz*/
	for(i=0;i<l;i++){
		scanf("%s", buffer);
		strcpy(campo[i], buffer);
	}	
	
	/*Imprimindo o Belo Trabalho*/
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%c", campo[i][j]);
		}printf("\n");
			
	}
	/*Liberando a Memoria*/
	liberarCampo(campo, l);
	return 0;
}
char** alocarCampo(int linhas, int colunas){
	char **matriz;
	int i, j;
	matriz = (char **) malloc(linhas*sizeof(char *));
	for(i=0;i<linhas;i++){
		matriz[i] = (char *) malloc((colunas+1)*sizeof(char));
	}
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			matriz[i][j] = '0';
		}
	}
	if(matriz == NULL){
		printf("Erro de Alocacao: Memoria Insuficiente\n");
		system("pause");
		exit(1);
	}
	return matriz;
}

void liberarCampo(char **matriz, int linhas){
	int i;
	for(i=0;i<linhas;i++){
		free(matriz[i]);
	}
	free(matriz);
}

int recursao(int i){

	recursao(i-1);

	if(i <= 0){
		return 0;		
	}
	if(matriz[i] !='\0'){
	
	}
	
}
