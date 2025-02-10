#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

Agenda::Agenda(int capacidad){
	this->capacidad=capacidad;
	
	nombres=new string[capacidad];
	
	telefonos=new long[capacidad];
	// telefonos={0};

	ocupados=new bool[capacidad];
	// ocupados={false};
	
	for (int i=0;i<capacidad;i++){
		telefonos[i]=0;
		ocupados[i]=false;
	}
}

Agenda::~Agenda(){
	delete[] nombres;
	delete[] ocupados;
	delete[] telefonos;
}

int Agenda::obtenerPosicion(long telefono){
	return telefono % capacidad;	
}

bool Agenda::existeContacto(long telefono){
	if(ocupados[obtenerPosicion(telefono)] && telefonos[obtenerPosicion(telefono)]==telefono){
		return true;
	}
	return false;
}

string Agenda::getContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	
	return nombres[obtenerPosicion(telefono)];
}

void Agenda::introducirContacto(long telefono, string contacto){
	int posicion=obtenerPosicion(telefono);
	
	assertdomjudge(!ocupados[posicion]);
	
	nombres[posicion]=contacto;
	telefonos[posicion]=telefono;
	ocupados[posicion]=true;
}

void Agenda::eliminarContacto(long telefono){
	assertdomjudge(existeContacto(telefono));

	ocupados[obtenerPosicion(telefono)]=false;
}

void Agenda::imprimir() {
	for (int i=0;i<capacidad;i++){
		cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
	}
}
