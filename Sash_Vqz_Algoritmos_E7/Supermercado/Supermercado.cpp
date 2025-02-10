#include"Supermercado.h"
#include"assertdomjudge.h"

Supermercado::Supermercado(int n){
    this->n_cajas=n;
    this->cajas=new Cola[this->n_cajas];
}

void Supermercado::nuevoUsuario(int n, int id){
    this->cajas[n].encolar(id); 
}

void Supermercado::cerrarCaja(int n){
    int i=n;
    
    do{ 
        if (i!=n && !this->cajaVacia(n)) cajas[i].encolar(cajas[n].desencolar()); 
        
        i++; 

        if(i>=this->n_cajas) i=0;
    
    }while (!this->cajaVacia(n));
}  

int Supermercado::atenderUsuario(int n){
    assertdomjudge(n>=0 && n<n_cajas);
    
    return this->cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n){
    if(this->cajas[n].estaVacia()) return true;
    
    return false;
}