#include <stdio.h>

int main(){
    int a, b, c, k, case_test, x;
    scanf("%d", &case_test);
    while(case_test--){
        scanf("%d %d %d %d", &a, &b, &c, &k);
        x=0;
        do{
            if(a*(x*x)+b*x+c <k){
                 x++;
            } else  if(a*(x*x)+b*x+c >= k){
                printf("%d\n", x);
                break;
            }
        }while(1);
    }
    return 0;
}