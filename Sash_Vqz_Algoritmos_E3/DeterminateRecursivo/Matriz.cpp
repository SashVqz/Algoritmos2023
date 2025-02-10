#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

// Constructor Default 
Matriz::Matriz() {
  this->n_filas=0;
  this->n_columnas=0;
  matriz=NULL;
}

// Constructor por parametros
Matriz::Matriz(int n_filas, int n_columnas) {
  this->n_filas=n_filas;
  this->n_columnas=n_columnas;
  matriz = new double*[n_filas];
  for (int i=0;i<n_filas;i++){
    matriz[i]=new double[n_columnas];
  }
}
     
// Constructor copia
Matriz::Matriz(const Matriz& copia){
  this->n_columnas=copia.n_columnas;
  this->n_filas=copia.n_filas;

  matriz=new double*[n_filas];
  for (int i=0;i<n_filas; i++) {
      matriz[i]=new double[n_columnas];
  }
  
  for(int i=0;i<n_filas;i++){
    for(int j=0;j<n_columnas;j++){
      matriz[i][j]=copia.matriz[i][j];
    }
  }
}

// Destructor
Matriz::~Matriz() {
  for (int i=0;i<this->n_filas;i++){
    delete this->matriz[i];
  }
  delete this->matriz;
}

// Asignacion de matrices
Matriz& Matriz::operator= (const Matriz &m){
  if(matriz!=NULL){
    for (int i=0;i<n_filas;i++){
      delete[] matriz[i];
      delete[] matriz;
      matriz=NULL;
    }
  }

  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;


  //assertdomjudge(n_filas>0 && n_columnas>0);

  if(n_filas>0 && n_columnas>0){
    matriz= new double *[n_filas];
    for (int i = 0;i<n_filas; i++){
      matriz[i] = new double[n_columnas];  
      for(int j=0;j<n_columnas; j++){
        matriz[i][j]=m.matriz[i][j];
      }
    }
  }

  return(*this); 
}

// Suma de matrices
Matriz Matriz::operator+ (const Matriz &m) {
    assertdomjudge(this->n_filas == m.n_filas && this->n_columnas == m.n_columnas);

    Matriz aux = Matriz(*this);

    for(int i=0;i<n_filas;i++){
      for(int j=0;j<n_columnas;j++){
        aux.matriz[i][j]=matriz[i][j]+m.matriz[i][j];
      }
    }

    return(aux);
}

// Resta de matrices
Matriz Matriz::operator- (const Matriz &m) {
    assertdomjudge(this->n_filas==m.n_filas && this->n_columnas==m.n_columnas);

    Matriz aux = Matriz(*this);

    for(int i=0;i<n_filas;i++){
      for(int j=0;j<n_columnas;j++){
        aux.matriz[i][j]=matriz[i][j]-m.matriz[i][j];
      }
    }

    return(aux);
}

// Producto de matrice
Matriz Matriz::operator* (const Matriz &m) {
    assertdomjudge(this->n_columnas==m.n_filas);

    Matriz aux = Matriz(this->n_filas, m.n_columnas);

    for(int i=0;i<aux.n_filas;i++){
      for(int j=0;j<aux.n_columnas;j++){
        for (int k=0;k<this->n_columnas;k++) {
          aux.matriz[i][j]+=matriz[i][k]*m.matriz[k][j];
        }
      }
    }

    return(aux);
}

// Producto escalar 
Matriz Matriz::operator* (const double& scalar){
  Matriz result = Matriz(this->n_filas, this->n_columnas);

  for (int i=0;i<n_filas;i++){  
    for(int j=0;j<n_columnas;j++){
      result.matriz[i][j] = this->matriz[i][j] * scalar;
    }
  }

  return result; 
}

// Matriz transpuesta
Matriz Matriz::calcularTraspuesta(){
  Matriz aux=Matriz(this->n_columnas,this->n_filas);
  
  for (int i=0;i<aux.n_filas;i++){ 
    for(int j=0;j<aux.n_columnas;j++){
      aux.matriz[i][j]=matriz[j][i];
    }
  }

  return aux; 
}

// Comprobar si la matriz es simetrica
bool Matriz::esSimetrica(){
  for (int i=0;i<n_filas;i++){
    for (int j=0;j<n_columnas;j++){
      if(matriz[i][j]!=matriz[j][i]){
        return false;
      }
    }
  }

  return true;
}

// Maximo y Minimo
double Matriz::obtenerMaximo(){
  double maximo=matriz[0][0];

  for (int i=0;i<n_filas;i++){
    for (int j=0;j<n_columnas;j++){
      if (maximo<matriz[i][j]){
        maximo=matriz[i][j];
      }  
    }
  }

  return maximo;
}

double Matriz::obtenerMinimo(){
  double minimo=matriz[0][0];

  for (int i=0;i<n_filas;i++){
    for (int j=0;j<n_columnas;j++){
      if (minimo>matriz[i][j]){
        minimo=matriz[i][j];
      }  
    }
  }

  return minimo;
}

// Calcular determinante de una matriz
double Matriz::calcularDeterminante(){
  double det=0;

  //caso base
  if (n_filas==1) return matriz[0][0];

  // precondicion: matriz cuadrada
  if (n_columnas==n_filas){
    Matriz aux = Matriz(n_filas-1, n_columnas-1);
    // buscamos el caso base de cada submatriz es devir dividimos al matriz hasta llegar a una matriz de orden 1
    for (int k=0;k<n_columnas;k++){
      for (int i=0;i<aux.n_filas;i++){
        for (int j=0;j<aux.n_columnas;j++){
          if (j<k){
            aux.matriz[i][j]=matriz[i+1][j];
          } else { 
            aux.matriz[i][j]=matriz[i+1][j+1];
          }
        }
      }

      // realizamos el metodo de cofactores dependiendo si el indice es par o impar restamos o sumamos 

      /*
        |1 2 3|         llamada recursiva 
        |4 5 6| = + 1 * (5*9 - 6*8) - 2 * (4*9 - 6*7) + 3 (4*8 - 5*7)
        |7 8 9|   par               impar             par    
      */

      if ((k%2)==0){
        det+=matriz[0][k]*aux.calcularDeterminante();
      } else {
        det-=matriz[0][k]*aux.calcularDeterminante();
      }
    }

    return det;
  } else {
    assertdomjudge(0);
  }
}

// Leer matriz
void Matriz::rellenarManual(){
  double elemento;
  for (int i = 0; i < n_filas; i++){
    cout << "Fila " << i << endl;
    for (int j = 0; j < n_columnas; j++){
      cout << "Elemento " << j << endl;
      cin >> elemento;
      matriz[i][j] = elemento;
    }
    cout << endl;
  }
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed){
  srand(seed);
  for (int i = 0; i < n_filas; i++){
    for (int j = 0; j < n_columnas; j++){
      matriz[i][j]=rand();
    }
  }
}

// Imprimir Matriz
void Matriz::mostrarMatriz(){
  for (int i = 0; i < n_filas; i++){
	  for (int j = 0; j < n_columnas; j++){
	    cout << matriz[i][j] << " ";       
      cout << endl;
    }
  }
}
