#include "AgendaCerrada.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

Agenda::Agenda(int capacidad) {
	this->capacidad=capacidad;
	this->nombres=new string[capacidad];
	this->telefonos=new long[capacidad];
	this->vacias=new bool[capacidad];
	this->borradas=new bool[capacidad];

	memset(telefonos, 0, capacidad * sizeof(long));
	memset(vacias, true, capacidad * sizeof(bool));
	memset(borradas, false, capacidad * sizeof(bool));
}

Agenda::~Agenda() {
	delete[] telefonos;
	delete[] nombres;
	delete[] vacias;
	delete[] borradas;
}

int Agenda::obtenerPosicion(long telefono) {
	return telefono%capacidad;
}

bool Agenda::isLlena() {
	for (int i=0;i<capacidad;i++) {
		if(vacias[i]) return false;
	}
	return true;
}

int Agenda::buscarContacto(long telefono) {
	for (int i=0;i<capacidad;i++) {

		if(!vacias[i] && telefonos[i]==telefono) return i;
				
		else
			if(!borradas[i]) return -1;
	}

	return -1;
}

int Agenda::buscarHueco(long telefono) {
	assertdomjudge(!isLlena());

	for (int i=obtenerPosicion(telefono);i<capacidad;i++) {
		if (vacias[i]) return i;
	}

	for (int i=0;i<obtenerPosicion(telefono);i++) {
		if (vacias[i]) return i;
	}
}

bool Agenda::existeContacto(long telefono) {
	if((!vacias[buscarContacto(telefono)]) && telefonos[buscarContacto(telefono)]==telefono) {
		return true;
	}
	return false;
}

string Agenda::getContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));

	return nombres[buscarContacto(telefono)];
}

void Agenda::introducirContacto(long telefono, string contacto) {
	int posicion=buscarHueco(telefono);
	
	assertdomjudge(!isLlena());

	nombres[posicion]=contacto;
	telefonos[posicion]=telefono;
	vacias[posicion]=false;
}

void Agenda::eliminarContacto(long telefono) {
	int posicion=buscarContacto(telefono);

	assertdomjudge(existeContacto(telefono));

	vacias[posicion]=true;
	borradas[posicion]=true;
}

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}