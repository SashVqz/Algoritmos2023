#include <iostream>
#include<string>
#include "AgendaCerrada.h"

using namespace std;

int main() {
	int capacidad; 
	char opcion; 
	long telefono; 
	string nombre; 
	cout << "Introduce la capacidad de la tabla: ";
	cin >> capacidad;
	Agenda agenda(capacidad);

	do {
		cin >> opcion;

		switch (opcion) {
			case 'I':
				agenda.imprimir();
				break;
			case 'C':
				cout << "Numero de telefono del contacto ";
				cin >> telefono;
				if (agenda.existeContacto(telefono)) 
					cout << "El contacto SI esta\n";
				else 
					cout << "El contacto NO esta\n";
				break;
			case 'V':
				cout << "Numero de telefono del contacto: ";
				cin >> telefono;
				cout << "Nombre: " << agenda.getContacto(telefono) << endl;
				break;
			case 'A':
				cout << "Numero de telefono del contacto: ";
				cin >> telefono;
				cout << "Nombre del contacto: ";
				cin >> nombre;
				agenda.introducirContacto(telefono, nombre);
				break;
			case 'E':
				cout << "Numero de telefono del contacto: ";
				cin >> telefono;
				agenda.eliminarContacto(telefono);
				break;
			case 'S':
					break;
			default:
				cout << "Opcion incorrecta\n";
				break;
		}
	} while (opcion != 'S'); 

	return 0;
}
