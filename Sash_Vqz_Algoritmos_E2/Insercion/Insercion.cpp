#include<iostream>
using namespace std;

/*
  precondicion: Ninguna
  complejidad temporal: t(n)= n^2/2 + n/2 + 1 --> O(n^2)
  complejidad espacial: O(1)
*/

void ordenarInsercion(int *x, int len);
void imprimir(int *x, int len);

int main(){
	int n;
 	cin>>n;
 	int *x=new int[n];
 	
 	for(int i=0;i<n;i++){
		cin>>x[i];
 	}
 	
 	ordenarInsercion(x,n);
}

void ordenarInsercion(int *x, int len){
  int aux=0;
  int j=0;

  for(int i=0;i<len;i++){
    aux=x[i]; 

    j=i-1; 
    while(j>=0 && aux<=x[j]){ 
      x[j+1]=x[j]; 
      j--; 
    }

    x[j+1]=aux; 

    imprimir(x, len);
  }
}

void imprimir(int *x, int len){
  for (int i=0;i<len;i++){
    cout << x[i]<< " ";
  }

  cout << endl;
}