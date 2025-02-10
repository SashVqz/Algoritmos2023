#include "ListaEnlazada.h"
#include <stdlib.h>
#include "assertdomjudge.h"

ListaEnlazada::ListaEnlazada(){
	lista=NULL; 
	this->n=0; 
}

ListaEnlazada::~ListaEnlazada(){
	while (n>0) eliminar(0);
}

Nodo* ListaEnlazada::getNodo(int posicion){
	assertdomjudge(posicion>=0 && posicion<=this->n-1 && this->n>0);
	
	Nodo* aux=lista;
	
	for (int i=0;i<posicion;i++)aux=aux->siguienteNodo;

	return aux;
}

int ListaEnlazada::getValor(int posicion){
	assertdomjudge(posicion>=0 && posicion<=this->n-1 && this->n>0);

	return getNodo(posicion)->elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor){
	assertdomjudge(posicion>=0 && posicion<=this->n-1 && this->n>0);
	
	getNodo(posicion)->elemento=nuevoValor;
}

int ListaEnlazada::getN(){
	return this->n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor){
	assertdomjudge(posicion>=0 && posicion<=n);

	Nodo* aux=new Nodo;
	aux->elemento=nuevoValor;

	if (n==0){
		lista=aux;
		aux->siguienteNodo=NULL;
	} else {
		if (posicion==n){ 
			aux->siguienteNodo = NULL; 
			getNodo(this->n-1)->siguienteNodo=aux; 
		} else if (posicion==0) { 
			aux->siguienteNodo=lista; 
			lista=aux;
		} else { 
			Nodo* anterior=getNodo(posicion-1); 
			Nodo* aux2=anterior->siguienteNodo;

			anterior->siguienteNodo=aux;   
			aux->siguienteNodo=aux2; 
		}
	}

	this->n++; 
}

void ListaEnlazada::eliminar(int posicion){
	assertdomjudge(posicion>=0 && posicion<=this->n-1 && this->n>0);

	Nodo* aux=NULL;

	if(posicion==0) {  
		aux=this->lista;

		Nodo* aux2=aux->siguienteNodo; 
		this->lista=aux2; 
	} else { 
		Nodo* anterior=getNodo(posicion-1); 
		aux=anterior->siguienteNodo; 
		
		Nodo* aux2=aux->siguienteNodo; 
		anterior->siguienteNodo=aux2; 
	}

	delete(aux);
	n--;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){
	assertdomjudge(listaAConcatenar!=NULL);

	for (int i=0;i<listaAConcatenar->getN();i++)insertar(this->n, listaAConcatenar->getValor(i));
}

int ListaEnlazada::buscar(int elementoABuscar){
	for(int i=0;i<n;i++) if(getNodo(i)->elemento==elementoABuscar) return i;

	return -1;
}