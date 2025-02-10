#include"Cola.h"

Cola::Cola(){  
	this->principio=NULL; 
	this->final=NULL;
}

void Cola::encolar(int num){
	Nodo *aux=new Nodo(num); 	

	if(this->principio==NULL){ 
		this->principio=aux; 
	}else{
		this->final->siguiente=aux; 
	}
	this->final=aux;
}

int Cola::desencolar(){
	int num=this->principio->valor;
	Nodo *aux=this->principio;

	if(principio->siguiente==NULL){ 
		principio=NULL;
		final=NULL;
	}else{ 
		principio=aux->siguiente;
	}

	delete(aux);
	
	return num;
}

bool Cola::estaVacia() {
	if (this->principio==NULL && this->final==NULL) { 
		return true;
	}
	return false;
}