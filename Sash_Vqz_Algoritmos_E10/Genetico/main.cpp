#include "iostream"
#include "Polinomio.h"
#include "cmath"
#include "cstdlib"
#include "ctime"
#include "ctime"

using namespace std;

int main(){
  int grado; 
  int semilla; 
  float *coeficientes = NULL; 
  
  cin>>semilla;
  srand(semilla); 
  cin >> grado;

  coeficientes = new float[grado+1];
  for (int i=0; i<=grado; i++) cin >> coeficientes[i];
  cout << endl;
  
  
  Polinomio p(grado, coeficientes);
  for (int i=0; i<5; i++) {
    cout <<"Iteracion "<<i<<endl;
    float raiz = p.obtenerRaiz();
    cout <<" Raiz " << raiz << endl;
  }
  return 0;
}
