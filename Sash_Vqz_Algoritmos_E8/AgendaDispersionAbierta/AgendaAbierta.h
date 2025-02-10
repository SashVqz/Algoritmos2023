#include "ListaEnlazada.h"
#include <iostream>

using namespace std;

class Agenda{
public:
	int capacidad;
	int n;
	ListaEnlazada *tabla;

	Agenda(int capacidad);
	~Agenda();
	int obtenerPosicion(long telefono);
	bool existeContacto(long telefono);
	string getContacto(long telefono);
	void introducirContacto(long telefono, string contacto);
	void eliminarContacto(long telefono);
	void imprimir();
};
