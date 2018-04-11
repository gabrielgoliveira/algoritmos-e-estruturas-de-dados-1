#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
	int n_lanchonetes, p_bebida, n_dd, n_moedas, aux;
	vector<int> valores;
	vector<int> moedas_dia;
	vector<int> quant;
//	cout<<"quantidade de lanchonetes: ";
	cin>>n_lanchonetes;
	while(n_lanchonetes--){
//		cout<<"preco do cafee na lanchonte "<<n_lanchonetes<<" ";
		cin>>p_bebida;
		/*armazenando valores das bebidas*/
		valores.push_back(p_bebida);
	}
//	cout<<"numeros de dias qua vai comprar cafe: ";
	cin>>n_dd;
	aux = n_dd;
	while(aux--){
//		cout<<"valor que pode ser gasto no dia: ";
		cin>>n_moedas;
		/*armazenando quantidade de moedas que pode ser gasta por dia*/
		moedas_dia.push_back(n_moedas);
	}
	
	/*ordenando vetor*/
	sort(valores.begin(), valores.end());

	aux = 0;
	for(int i=0;i<n_dd; i++){
		for(int j=0;j<valores.size();j++){
			if(moedas_dia[i] >= valores[j]){
				aux++;
			}
		}
		cout<<aux<<endl;
		aux=0;
	}

	return 0;
}
