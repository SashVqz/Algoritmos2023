#include "ColaPrioridad.h"
#include "assertdomjudge.h"

ColaPrioridad::ColaPrioridad() {
	this->vector=ListaContigua();
}

void ColaPrioridad::reestructurar(){
	assertdomjudge(vector.getN()>=2);

	int posicion=vector.getN(), posicionPadre=1, posicionHijo;
	int valorPosicion=vector.getValor(posicionPadre-1), ValorHijoIqz, ValorHijoDer;
	int auxValor;
	bool aux=false;

	while(!aux){
		
		if(((posicionPadre*2)+1)>posicion){
			posicionHijo=posicionPadre*2;
		}else{
			ValorHijoDer=vector.getValor(posicionPadre*2);
			ValorHijoIqz=vector.getValor((posicionPadre*2)-1);

			if(ValorHijoDer>ValorHijoIqz){
		        posicionHijo=posicionPadre*2;	
			} else {
				posicionHijo=(posicionPadre*2)+1;
			}
		}

		auxValor=vector.getValor(posicionHijo-1);

		if (valorPosicion>auxValor){
			vector.setValor(posicionPadre-1, auxValor);
			vector.setValor(posicionHijo-1, valorPosicion);

			posicionPadre=posicionHijo;
			if (posicionPadre>posicion/2) {
				aux=true;
			}
		}else {
			aux=true;
		}
	}
}

void ColaPrioridad::encolar(int nuevoElemento){
	this->vector.insertarAlFinal(nuevoElemento);
	
	int aux, posicion=vector.getN();
	// comparamos padre y hijo
	while(posicion>1 && vector.getValor(posicion-1)<vector.getValor((posicion/2)-1)){
		// reservamos el valor del hijo 
		aux=vector.getValor((posicion/2)-1);
		
		// intercambiamos con el padre 
		vector.setValor(((posicion/2)-1), vector.getValor(posicion-1));
		
		// padre= valor del hijo
		vector.setValor(posicion-1, aux);
	}
}


int ColaPrioridad::desencolar(){
	assertdomjudge(!estaVacia());

	int principio=this->vector.getValor(0);
	int final=this->vector.getValor(vector.getN()-1);
	
	// sustituimos el primero por el ultimo
	this->vector.setValor(0, final);
	
	// eliminamos el final
	this->vector.eliminarAlFinal();

	// reestructuramos si n>=2
	if (this->vector.getN()>=2){
		this->reestructurar();
	}

	return principio;
}

bool ColaPrioridad::estaVacia(){
	if (this->vector.getN()==0){
		return true;
	}
	return false;
}