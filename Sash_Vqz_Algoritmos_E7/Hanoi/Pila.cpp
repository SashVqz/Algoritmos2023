#include"Pila.h"

Pila::Pila(string name){
  this->name=name; 
  this->cima=NULL; 
}

string Pila::nombrePila(){
  return this->name;
}

void Pila::apilar(int num){
  if (num!=0){
    Nodo *aux = new Nodo(num); 
    aux->siguiente=this->cima; 

    this->cima=aux; 
    
    cout<<"Apilando disco "<<num<<" en poste "<<this->name<<endl;
  }
}
  
int Pila::desapilar(){
  Nodo *aux=this->cima; 
  int num=0;

  if (!estaVacia()){
    num=aux->valor;
    this->cima=this->cima->siguiente; 
    cout<<"Desapilando disco "<<num<<" del poste "<<this->name<<endl;
  }

  return num;
}

bool Pila::estaVacia(){
  if(this->cima==NULL) return true;
  
  return false;
}

