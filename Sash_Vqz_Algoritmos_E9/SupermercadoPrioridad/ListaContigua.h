#pragma once

#define INCREMENTO 2

class ListaContigua{
	int *vector;
	int n;
	int capacidad;
	bool isLlena();

public:
	ListaContigua();
	int getValor(int posicion);
	void setValor(int posicion, int nuevoValor);
	int getN(); 
	int getCapacidad(); 
	void insertarAlFinal (int nuevoValor);
	void eliminarAlFinal();
	void insertar(int posicion, int nuevoValor);
	void eliminar(int posicion);
	void concatenar(ListaContigua *listaAConcatenar);
	int buscar(int elementoABuscar);
	~ListaContigua();
};








