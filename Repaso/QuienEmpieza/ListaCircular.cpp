#include "ListaCircular.h"

Nodo* ListaCircular::getNodo(int posicion) {
	Nodo* aux=lista;
	
	if (posicion>0) { 
		for (int i=0;i<posicion;i++) aux=aux->siguienteNodo; 
	}else{ 
		for (int i=0;i<-posicion;i++) aux=aux->anteriorNodo; 
	}
	
	return aux;
}

ListaCircular::ListaCircular() {
	n=0; 
	lista=NULL; 
}

ListaCircular::~ListaCircular(){
	while(n>0) eliminar(0);
}

int ListaCircular::getValor(int posicion){
	return getNodo(posicion)->elemento;
}

void ListaCircular::setValor(int posicion, int nuevoValor){
	getNodo(posicion)->elemento=nuevoValor;
}

int ListaCircular::getN(){
	return this->n;
}

void ListaCircular::insertar(int posicion, int nuevoValor) {
	Nodo *aux = new Nodo; 
	
	if (n==0) {
		aux->elemento=nuevoValor;
		
		aux->anteriorNodo=aux; 
		aux->siguienteNodo=aux;
		
		lista=aux;
	}else{ 
		aux->elemento=nuevoValor;

		aux->siguienteNodo=getNodo(posicion);
		aux->anteriorNodo=getNodo(posicion-1);
		
		aux->siguienteNodo->anteriorNodo=aux;
		aux->anteriorNodo->siguienteNodo=aux;
	}
	
	n++; 
}

void ListaCircular::eliminar(int posicion) {
	if (posicion==0) lista=getNodo(posicion+1);

	getNodo(posicion-2)->siguienteNodo=getNodo(posicion); 
	getNodo(posicion)->anteriorNodo=getNodo(posicion - 2);
	
	n--;
}

void ListaCircular::saltar (int p){
	lista=getNodo(p+3);
}
