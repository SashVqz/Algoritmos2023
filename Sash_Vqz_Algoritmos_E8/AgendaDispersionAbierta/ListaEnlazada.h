#pragma once
#include "Nodo.h"

class ListaEnlazada{
	Nodo *lista;
	int n;
	int posicionUltimoNodoAccedido;
	Nodo *punteroUltimoNodoAccedido;
	Nodo * getNodo (int posicion);

public:
	ListaEnlazada();
	Contacto getValor(int posicion);
	void setValor(int posicion, Contacto nuevoValor);
	int getN(); 
	void insertar (int posicion, Contacto nuevoValor);
	void eliminar (int posicion);
	void concatenar(ListaEnlazada *listaAConcatenar);
	int buscar(Contacto elementoABuscar);
	~ListaEnlazada();
};







