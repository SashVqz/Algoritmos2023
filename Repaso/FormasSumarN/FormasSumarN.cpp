#include <iostream>
#include<stdlib.h>

using namespace std;

void formasSumarN(int pos, int objetivo, int res, int *numeros);

int main(){
	int* numeros;
	int objetivo;

	cin >> objetivo;
	numeros=new int[objetivo];
	
	formasSumarN(0, objetivo, 0, numeros);

	return 0;
}

void formasSumarN(int pos, int objetivo, int res, int *numeros){
	int aux=res;
	for (int i=1;i<objetivo;i++){
		aux+=i;
		numeros[pos]=i;
		if(aux<objetivo && pos<objetivo-1){
			formasSumarN((pos+1), objetivo, aux, numeros);
		}

		if(aux==objetivo){
			for (int j=0;j<=pos;j++){
				cout << numeros[j] << " ";
			}
			cout << endl;
		}

		aux-=i;
	}
}
