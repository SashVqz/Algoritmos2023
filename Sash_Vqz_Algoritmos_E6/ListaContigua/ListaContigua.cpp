#include <iostream>
#include <cstring>
#include "assertdomjudge.h"
#include "ListaContigua.h"

ListaContigua::ListaContigua(int incremento){
	this->incremento=incremento;
	this->capacidad=0;
	this->capacidad=this->capacidad+this->incremento; 
	this->vector=new int[this->incremento]; 
}

ListaContigua::~ListaContigua(){
	delete this->vector;
}

int ListaContigua::getValor(int posicion){
	assertdomjudge(posicion>=0 && posicion<=n-1);

	return this->vector[posicion];
}

void ListaContigua::setValor(int posicion, int nuevoValor){
	assertdomjudge(posicion>=0 && posicion<=n-1);
	
	this->vector[posicion]=nuevoValor;
}

int ListaContigua::getN(){
	return this->n;
}

int ListaContigua::getCapacidad(){
	return this->capacidad;
}

void ListaContigua::insertar(int posicion, int nuevoValor){
	assertdomjudge(posicion>=0 && posicion<=n);

	if (this->n==this->capacidad){
		this->vector=(int*)realloc(vector, sizeof(int)*(this->capacidad+this->incremento));
		this->capacidad=this->capacidad+incremento;
	}

 	memmove(&vector[posicion+1], &vector[posicion], sizeof(int)*(this->n-posicion));

	this->n++;
	
	setValor(posicion, nuevoValor);
}

void ListaContigua::eliminar(int posicion){
	assertdomjudge(posicion>=0 && posicion<=n-1);

	memmove(&vector[posicion], &vector[posicion+1], sizeof(int)*(this->n-posicion-1));
	this->n--;

	if ((capacidad-n)==(2*incremento)){
		this->vector=(int*)realloc(vector, sizeof(int)*(this->capacidad-this->incremento));
		this->capacidad=this->capacidad-this->incremento;
	}
}

void ListaContigua::concatenar(ListaContigua *listaAConcatenar){
	assertdomjudge(listaAConcatenar!=NULL);

	this->vector=(int*)realloc(vector, sizeof(int)*(this->capacidad+listaAConcatenar->getN()));
	this->capacidad=this->capacidad+listaAConcatenar->getN();

	for (int i=0;i<listaAConcatenar->getN();i++) insertar(this->n, listaAConcatenar->getValor(i));
}

int ListaContigua::buscar(int elementoABuscar){
	for (int i=0;i<this->n;i++){
		if (elementoABuscar==this->vector[i]) return i; 
	}
	
	return -1;
}

