#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include <string.h>

ListaEnlazada::ListaEnlazada(){
    lista=NULL;
    this->n=0;
}

ListaEnlazada::~ListaEnlazada(){
    while (n>0){
        eliminar(0);
    }
}

Nodo* ListaEnlazada::getNodo(int posicion){
    assertdomjudge(posicion>=0 && posicion<=this->n-1 && this->n>0);
    
    Nodo* aux=lista;
    for (int i=0;i<posicion;i++){
        aux=aux->siguienteNodo;
    }

    return aux;
}

Contacto ListaEnlazada::getValor(int posicion){
    assertdomjudge(posicion>=0 && posicion<this->n);
    return this->getNodo(posicion)->elemento;
}

void ListaEnlazada::setValor(int posicion, Contacto nuevoValor){
    assertdomjudge(posicion>=0 && posicion<this->n);
    this->getNodo(posicion)->elemento=nuevoValor;
}

int ListaEnlazada::getN(){
    return this->n;
}

void ListaEnlazada::insertar (int posicion, Contacto nuevoValor){
    assertdomjudge(posicion>=0 && posicion<=this->n);

    Nodo* aux=new Nodo;
    aux->elemento=nuevoValor;

    if(posicion==0){
        aux->siguienteNodo=this->lista;
        this->lista=aux;
    } else {
        aux->siguienteNodo=this->getNodo(posicion-1)->siguienteNodo;
        this->getNodo(posicion-1)->siguienteNodo=aux;
    }

    this->n++;
}

void ListaEnlazada::eliminar(int posicion){
    assertdomjudge(posicion>=0 && posicion<this->n);

    Nodo* aux=this->getNodo(posicion);

    if(posicion==0){
        this->lista=aux->siguienteNodo;
    } else {
        this->getNodo(posicion-1)->siguienteNodo=aux->siguienteNodo;
    }
    delete aux;
    this->n--;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){
    assertdomjudge(listaAConcatenar != NULL);

    for (int i=0;i<listaAConcatenar->getN();i++){
        insertar(this->n, listaAConcatenar->getValor(i));
    }
}

int ListaEnlazada::buscar(Contacto elementoABuscar){
    Nodo* aux=this->lista;

    for(int i=0;i<this->n;i++){
        if(aux->elemento.telefono==elementoABuscar.telefono) return i;
        
        aux=aux->siguienteNodo;
    }

    return -1;
}
