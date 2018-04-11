#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, quant_vogais;
    string trees;
    int vogais[] = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};
    cin>>n;
    while(n--){
        cin>>trees;
        cin.ignore();
        quant_vogais = 0;
        for(int i=0;i<trees.size();i++){
            for(int k=0;k<10;k++){
                if(trees[i] == vogais[k]){
                    quant_vogais++;
                }
            }
        }
        cout<<quant_vogais<<endl;
        trees.clear();
    }

    return 0;
}
