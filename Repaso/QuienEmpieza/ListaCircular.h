#include<cstdlib>
#include "Nodo.h"

class ListaCircular{
	Nodo *lista;
	int n;
	Nodo * getNodo (int posicion);

public:
	ListaCircular();
	int getValor(int posicion);
	void setValor(int posicion, int nuevoValor);
	int getN(); 
	void insertar (int posicion, int nuevoValor);
	void eliminar (int posicion);
	void saltar (int p);
	~ListaCircular();
};







