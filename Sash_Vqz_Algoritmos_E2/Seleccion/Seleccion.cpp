#include<iostream>
using namespace std;

/*
  precondicion: Ninguna
  complejidad temporal: t(n)= n^2/2 + 3n/2 + 1 --> O(n^2)
  complejidad espacial: O(1)
*/

void imprimir(int *x, int len);
void ordenarSeleccion(int *x, int len);

int main(){
 	int n;
 	cin>>n;
 	int *x=new int[n];
 	
 	for(int i=0;i<n;i++){
   		cin>>x[i];
	}

 	ordenarSeleccion(x, n);
}


void ordenarSeleccion(int *x, int len){
    int auxValorPos=0;
    int auxValor=0;

    for (int i=0;i<len;i++){ 
      auxValorPos=i; 
      
      for (int j=i+1;j<len;j++){ 
        if (x[j]<x[auxValorPos]) auxValorPos=j; 
      }

      auxValor=x[auxValorPos];
      x[auxValorPos]=x[i];
      x[i]=auxValor;

      imprimir(x, len);
    }
}

void imprimir(int *x, int len){
  for (int i=0;i<len;i++){
    cout << x[i]<< " ";
  }

  cout << endl;
}