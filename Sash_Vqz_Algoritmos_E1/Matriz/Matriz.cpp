#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>]

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}


Matriz::Matriz() {
  this->n_filas=0;
  this->n_columnas=0;
  matriz=NULL;
}

Matriz::Matriz(int n_filas, int n_columnas) {
  this->n_filas=n_filas;
  this->n_columnas=n_columnas;
  matriz = new double*[n_filas];
  for (int i=0;i<n_filas;i++){
    matriz[i]=new double[n_columnas];
  }
}
     
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

Matriz::~Matriz() {
  for (int i=0;i<this->n_filas;i++){
    delete this->matriz[i];
  }
  delete this->matriz;
}

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

  // assertdomjudge(n_filas>0 && n_columnas>0);

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

Matriz Matriz::operator*(const double& scalar){
  Matriz(*this);

  for (int i=0;i<n_filas;i++){  
    for(int j=0;j<n_columnas;j++){
      matriz[i][j]=matriz[i][j]*scalar;
    }
  }

  return(*this); 
}

Matriz Matriz::calcularTraspuesta(){
  Matriz aux=Matriz(this->n_columnas,this->n_filas);
  
  for (int i=0;i<aux.n_filas;i++){ 
    for(int j=0;j<aux.n_columnas;j++){
      aux.matriz[i][j]=matriz[j][i];
    }
  }

  return aux; 
}

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

void Matriz::rellenarAleatorio(long seed){
  srand(seed);
  for (int i = 0; i < n_filas; i++){
    for (int j = 0; j < n_columnas; j++){
      matriz[i][j]=rand();
    }
  }
}

void Matriz::mostrarMatriz(){
  for (int i = 0; i < n_filas; i++){
	  for (int j = 0; j < n_columnas; j++){
	    cout << matriz[i][j] << " ";       
      cout << endl;
    }
  }
}
