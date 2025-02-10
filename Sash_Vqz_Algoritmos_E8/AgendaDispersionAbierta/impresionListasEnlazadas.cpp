#include "impresionListasEnlazadas.h"
#include "assertdomjudge.h"
#include <iostream>
using namespace std;

void imprimirListaEnlazada(ListaEnlazada *lista) {
	assertdomjudge(lista != NULL);
	cout << "n=" << lista->getN() << "|ListaEnlazada=";

	if (lista->getN() == 0) cout << "vacia";

	else {
		if (lista->getN() > 20) cout << "demasiadosElementosParaMostrar";
		else {
			for (int i = 0; i < lista->getN(); i++) {
				Contacto elemento = lista->getValor(i); 
				cout << "(" << elemento.telefono << "," << elemento.nombre << ")";
				if (i < lista->getN() - 1) cout << ",";
			}
		}
	}
	
	cout << endl;
}
