#include<iostream>
#include<math.h>
using namespace std;

#define assertdomjudge(x) if(!(x)){cout<<"ERROR"<<endl; exit(0);}

/* 
  Precondiciones: n>=0 | error>0
  Complejidad temporal O(n^2)
  Complejidad espacial O(n^2) --> mejor caso es 0(1)
*/

void raizCuadrada(double cuadrado, double error, double min, double max);

int main(){
  double cuadrado;
  double error;
  cin>>cuadrado;
  cin>>error;

  assertdomjudge(cuadrado>0 && error>=0);
  
  raizCuadrada(cuadrado, error, 0, cuadrado);
  
  return 0;
}

void raizCuadrada(double cuadrado, double error, double min, double max){
  double raiz=(min+max)/2;
  
  if((raiz*raiz)-cuadrado>error){ 
    min=raiz;
    raizCuadrada(raiz, error, min, max);
  }

  if ((raiz*raiz)-cuadrado<(error*-1)){
    max=raiz;
    raizCuadrada(raiz, error, min, max);
  }

  cout<<raiz<<endl;
}
