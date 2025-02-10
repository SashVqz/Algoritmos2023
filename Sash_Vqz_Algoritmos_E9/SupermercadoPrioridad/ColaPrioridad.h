#pragma once
#include "ListaContigua.h"

class ColaPrioridad{
protected:
	ListaContigua vector; 
	void reestructurar();

public:
	ColaPrioridad();
	void encolar(int nuevoElemento);
	int desencolar();
	bool estaVacia();
};

