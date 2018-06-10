#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int cor[1000000], vis = 1;
int used[1000000];
int anoes[1000000];
 
int main(){
 
    int t, n, c, i, m, a, b, ans, alvo;
    scanf("%d", &t);
 
    while( t-- ){
        scanf("%d %d", &n, &c);
        for( i = 0; i < n; i++){
            scanf("%d", &anoes[i]);
        }
        scanf("%d", &m);
        for(i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            a--; b--;
            ans = -1;
            alvo = ((b-a)+1) / 2;
            vis++;
            while( a <= b ){
                if( used[anoes[a]] != vis ){
                    cor[anoes[a]] = 0;
                }
                used[anoes[a]] = vis;
                cor[anoes[a]]++;
                if( cor[anoes[a]] > alvo ){
                    ans =  anoes[a];
                    break;
                }
                a++;
            }
            if( ans != -1 ){
                printf("Sim %d\n", ans);
            }
            else{
                printf("Nao\n");
            }
        }
    }
    return 0;
}