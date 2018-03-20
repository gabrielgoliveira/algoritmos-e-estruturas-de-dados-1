#include <stdio.h>

/*Esse algoritmo calcula fatorial de um numero utilizando recursão*/

int fatorial(int);

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", fatorial(n));
	return 0;
}
int fatorial(int num){
	/*Caso Base 0! = 1*/
	if(num == 0){
		return 1;
	} else {
		return num*fatorial(num-1);
	}


}
