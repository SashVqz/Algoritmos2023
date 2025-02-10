#include <iostream>
#include<stdlib.h>

using namespace std;

void calcularCoches(int n);
int* ordenarBurbuja(int* x,int len);

int main(){
  int n=0;

  cin >> n;
  calcularCoches(n);
  
  return 0;
}

void calcularCoches(int n){
  int nPilas=0, nCoches;
  int voltnecesarios=0, auxVoltnecesarios=0;
  int *pilas;

  while(n>0){
    cin >> nPilas >> voltnecesarios;
      
    pilas=new int[nPilas];
    for (int i=0;i<nPilas;i++){
      cin >> pilas[i]; 
    }

    nCoches=0;

    for (int j=0;j<nPilas;j++){
      if(auxVoltnecesarios<=0){
        auxVoltnecesarios=voltnecesarios;
        nCoches++;
      }else{
        if(auxVoltnecesarios>=0){
          auxVoltnecesarios-=pilas[j];
        }
      }
    }

    cout << nCoches << endl;
    n--;
  }
  cout << endl;
}

int* ordenarBurbuja(int* x,int len){
  int aux;
  for(int i=0;i<len;i++){
    for (int j=0;j<len-i;j++){
      if (x[j]<x[j+1]){
        aux=x[j];
        x[j]=x[j+1];  
        x[j+1]=aux;
      }
    }    
  }
  return x;
}