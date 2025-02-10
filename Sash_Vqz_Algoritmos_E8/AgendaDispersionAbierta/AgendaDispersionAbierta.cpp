#include "AgendaAbierta.h"
#include "assertdomjudge.h"
#include "ListaEnlazada.h"
#include <iostream>
#include "impresionListasEnlazadas.h" 

using namespace std;

Agenda::Agenda(int capacidad) {
	this->capacidad=capacidad;
	this->n=0;
	this->tabla=new ListaEnlazada[capacidad];
}

Agenda::~Agenda() {
	delete[] tabla;
}

int Agenda::obtenerPosicion(long telefono) {
	return telefono%capacidad;
}

bool Agenda::existeContacto(long telefono) {
	Contacto aux;
	aux.telefono=telefono;
	if (tabla[obtenerPosicion(telefono)].buscar(aux)!=-1) {
		return true;
	}
	return false;
}

string Agenda::getContacto(long telefono){
	assertdomjudge(existeContacto(telefono));

	Contacto aux;
	aux.telefono=telefono;
	
	return (tabla[obtenerPosicion(telefono)].getValor(tabla[obtenerPosicion(telefono)].buscar(aux)).nombre);
}

void Agenda::introducirContacto(long telefono, string contacto) {
	assertdomjudge(!existeContacto(telefono));
	
	Contacto aux;
	aux.telefono=telefono;
	aux.nombre=contacto;

	tabla[obtenerPosicion(telefono)].insertar(0, aux);
	n++;
}

void Agenda::eliminarContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));

	Contacto aux;
	aux.telefono = telefono;

	tabla[obtenerPosicion(telefono)].eliminar(tabla[obtenerPosicion(telefono)].buscar(aux));

	n--;
}

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}
