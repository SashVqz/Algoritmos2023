#include<iostream>
using namespace std;

/*
  precondicion: Ninguna
  complejidad temporal: t(n)= n^2/2 + n/2 + 1 --> O(n^2)
  complejidad espacial: O(1)
*/

void ordenarBurbuja(int *x, int len);
void imprimir(int *x, int len);

int main(){
 	int n;
 	cin>>n;
 	int *x=new int[n];
 	
 	for(int i=0;i<n;i++){
   	cin>>x[i];
	}

 	ordenarBurbuja(x, n);
} 

void ordenarBurbuja(int *x, int len){
  int aux=0;

  for(int i=0;i<len;i++){ 
    for(int j=0;j<len-i;j++){ 
      if(x[j]>x[j+1]){ 
        aux=x[j];
        x[j]=x[j+1];
        x[j+1]=aux;
      }
    }

    imprimir(x, len);
  }
}

void imprimir(int *x, int len){
  for (int i=0;i<len;i++){
    cout << x[i]<< " ";
  }

  cout << endl;
}