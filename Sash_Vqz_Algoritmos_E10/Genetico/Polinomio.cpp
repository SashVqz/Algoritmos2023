#include "Polinomio.h"
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

Polinomio::Polinomio(int n, float *coeficientes) {
	this->n=n;
	this->coeficientes=coeficientes;
}

Polinomio::~Polinomio() {
	delete[] this->coeficientes;
}

float Polinomio::obtenerAleatorioNormalEstandar() {
	float suma=0; 
	for (int i=0;i<12;i++) {
		suma+=rand()/(float)RAND_MAX;
	}
	return(suma-6);
}

float Polinomio::obtenerRaizRecursivo(SolucionParcial padre) {
    cout<<"Seleccionada"<<endl;
	padre.imprimir();
	cout<<"Mutaciones"<<endl;
	
	SolucionParcial* hijos=new SolucionParcial[10];
	for(int i=0;i<10;i++){
		hijos[i].x=obtenerAleatorioNormalEstandar()+padre.x;
		hijos[i].y=evaluar(hijos[i].x);
		hijos[i].imprimir();
	}

	SolucionParcial aux=padre;
	for(int i=0;i<10;i++){
		if((hijos[i].y<=0 && aux.y<=0 && hijos[i].y>aux.y) 
			|| (hijos[i].y>=0 && aux.y>=0 && hijos[i].y<aux.y) 
			|| (hijos[i].y>=0 && aux.y<=0 && (hijos[i].y<(-aux.y))) 
			|| (hijos[i].y<=0 && aux.y>=0 && (-hijos[i].y)<aux.y)){
			aux=hijos[i];
		}
	}
	
	if(aux.y!=padre.y && aux.x!=padre.x){
		return obtenerRaizRecursivo(aux);
	} else {
		return padre.x;
	}
}

float Polinomio::evaluar(float x) {
	float res=0;
	for(int i=0;i<=n;i++){
		res+=this->coeficientes[i]*pow(x, i);
	}
	return res;
}

float Polinomio::obtenerRaiz() {
	SolucionParcial aux;
	aux.x=0;
	aux.y=evaluar(aux.x);

	return obtenerRaizRecursivo(aux);
}
