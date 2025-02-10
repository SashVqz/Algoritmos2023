#include <iostream>
#include<stdlib.h>

using namespace std;

void numble(int i ,int objetivo, int *numeros);

int main(){
	int* numeros=new int[4];
	int objetivo;
	
	for (int i=0;i<4;i++){
		cin >> numeros[i];
	}
	cin >> objetivo;
	numble(0, objetivo, numeros);

	return 0;
}

void numble(int i ,int objetivo, int *numeros){	
	int auxI=i;
	bool esComodin=false; 

	if(i<4){
		auxI++;
		if(numeros[i]==-1){ 
			esComodin=true; 
			for(int n=0;n<10;n++){
				numeros[i]=n;
				numble(i, objetivo, numeros);
			}
		} else {
			numble(auxI, objetivo-numeros[i], numeros);
		}
	}else{ 
		if(objetivo==0){ 
			for (int i=0;i<4;i++){ 
				cout << numeros[i] << " ";
			}
			cout << endl;
		}
	}

	if(esComodin) numeros[i]=-1;
	esComodin=false;
}
