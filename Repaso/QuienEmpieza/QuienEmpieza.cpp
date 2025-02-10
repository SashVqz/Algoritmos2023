#include <iostream>
#include<stdlib.h>

using namespace std;

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

int main(){
	int n_ninos;
	int numero_saltos;

	cin >> n_ninos >> numero_saltos;

	assertdomjudge(n>=0 && n_ninos<10000);
	assertdomjudge(n>=0 && numero_saltos<=1000);
	
	if (n_ninos==0 && numero_saltos==0){
		ListaCircular ninos;
		int numero_ninos=0;

		for (int i=0;i<n_ninos;i++){
			ninos.insertar(i, numero_ninos+1);
		}

		int pos;
		do {
			ninos.saltar(ninos.getN());
			pos=ninos.getValor(0);
			cout << pos << endl;
		}while(n_ninos!=0 && numero_saltos!=0);

		for(int i=0;i<n_ninos;i++){
    		ninos.eliminar(0);
  		}
	}

	return 0;
}