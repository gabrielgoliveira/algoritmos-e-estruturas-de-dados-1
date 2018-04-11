#include <stdio.h>

int somatoria(int);

int main(){

    printf("%d\n", somatoria(5));

    return 0;
}

int somatoria(int x){

    if(x == 1){
        return 1;
    } else {
        return x + somatoria(x-1);
    }

}