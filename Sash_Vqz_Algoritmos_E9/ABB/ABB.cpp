#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

#define MAX(x,y) ((x)>(y)?(x):(y))

ABB::ABB() {
    this->n=0;
    this->raiz=NULL;
}

ABB::~ABB(){
    if (raiz!=NULL){
        eliminarSubarbol(this->raiz);
    }   
}

void ABB::insertar (int nuevoElemento){
    Nodo* aux=new Nodo;
    Nodo* padre=new Nodo;
    
    aux->contenido=nuevoElemento;
    aux->padre=NULL;
    aux->hijoIzquierdo=NULL;
    aux->hijoDerecho=NULL;

    if (n==0){
        this->raiz=aux;
    }else{
        padre=buscarHueco(raiz, nuevoElemento);
        if (nuevoElemento<=padre->contenido){
            padre->hijoIzquierdo=aux;
        } else {
            padre->hijoDerecho=aux;
        }
        aux->padre=padre;
    }

    this->n++;
}

void ABB::eliminar(int elementoAEliminar) {
    Nodo* aux=buscar(elementoAEliminar);
    
    eliminarNodo(aux);
    n--;

    if(n==0){
        raiz=NULL;
    }
}

void ABB::eliminarSubarbol (Nodo *raizSubarbol){
    assertdomjudge(raizSubarbol!=NULL);

    if (raizSubarbol->hijoIzquierdo!=NULL) eliminarSubarbol(raizSubarbol->hijoIzquierdo);

    if (raizSubarbol->hijoDerecho!=NULL) eliminarSubarbol(raizSubarbol->hijoDerecho);
      
    Nodo* aux=raizSubarbol->padre;

    if (aux!=NULL){
        if (aux->hijoIzquierdo==raizSubarbol) aux->hijoIzquierdo=NULL;
        if (aux->hijoDerecho==raizSubarbol) aux->hijoDerecho=NULL;
    }

    delete raizSubarbol;
}

void ABB::eliminarNodo (Nodo *nodoParaEliminar){
    Nodo* aux=NULL;

    if (nodoParaEliminar!=NULL){
        if (nodoParaEliminar->hijoIzquierdo==NULL && nodoParaEliminar->hijoDerecho==NULL){
            Nodo* padreNodoParaEliminar=nodoParaEliminar->padre;

            if(padreNodoParaEliminar!=NULL){
                if (padreNodoParaEliminar->hijoIzquierdo==nodoParaEliminar) padreNodoParaEliminar->hijoIzquierdo=NULL;
            
                if (padreNodoParaEliminar->hijoDerecho==nodoParaEliminar) padreNodoParaEliminar->hijoDerecho=NULL;
            }

            delete nodoParaEliminar;
        } else {

            if (nodoParaEliminar->hijoIzquierdo!=NULL && nodoParaEliminar->hijoDerecho!=NULL){
                if (alturaNodo(nodoParaEliminar->hijoDerecho) > alturaNodo(nodoParaEliminar->hijoIzquierdo)){
                    aux=buscarMinimo(nodoParaEliminar->hijoDerecho);
                }else{
                    aux=buscarMaximo(nodoParaEliminar->hijoIzquierdo);
                }    

            } else if (nodoParaEliminar->hijoIzquierdo==NULL && nodoParaEliminar->hijoDerecho!=NULL){
                aux=buscarMinimo(nodoParaEliminar->hijoDerecho);
            } else {
                aux=buscarMaximo(nodoParaEliminar->hijoIzquierdo);
            }
        
            nodoParaEliminar->contenido=aux->contenido;
            eliminarNodo(aux);
        }
    }
}

Nodo* ABB::buscar(int elementoABuscar) {
    return buscarRecursivo(raiz, elementoABuscar);
}

Nodo* ABB::buscarHueco(Nodo* raizSubarbol, int elementoAInsertar) {
    assertdomjudge(raizSubarbol!=NULL);

    if (elementoAInsertar<=raizSubarbol->contenido) {
        if (raizSubarbol->hijoIzquierdo==NULL) return raizSubarbol;
    
        return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
    } else {
        if (raizSubarbol->hijoDerecho==NULL) return raizSubarbol;
        
        return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
    }
}

Nodo* ABB::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar) {
    Nodo* aux=new Nodo();
    
    if (raizSubarbol==NULL) aux=NULL;
    if (elementoABuscar==raizSubarbol->contenido) aux=raizSubarbol;
    if (elementoABuscar<raizSubarbol->contenido) aux=buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
    if (elementoABuscar>raizSubarbol->contenido) aux=buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
    
    return aux;
}

Nodo* ABB::buscarMaximo(Nodo* raizSubarbol) {
    assertdomjudge(raizSubarbol!=NULL);

    Nodo* maximo=new Nodo();

    if (raizSubarbol->hijoDerecho==NULL) {
        maximo=raizSubarbol;
    } else {
        maximo=buscarMaximo(raizSubarbol->hijoDerecho);
    }

    return maximo;
}

Nodo* ABB::buscarMinimo(Nodo* raizSubarbol) {
    assertdomjudge(raizSubarbol!=NULL);

    Nodo* minimo=new Nodo();

    if (raizSubarbol->hijoIzquierdo==NULL) {
        minimo=raizSubarbol;
    } else {
        minimo=buscarMinimo(raizSubarbol->hijoIzquierdo);
    }

    return minimo;
}

int ABB::alturaNodo(Nodo *raizSubarbol){
    if (raizSubarbol == NULL){
        return -1;
    }else{
        return (MAX(alturaNodo(raizSubarbol->hijoIzquierdo), alturaNodo(raizSubarbol->hijoDerecho)) + 1);
    }    
}

bool ABB::esABB() {
    return esSubABB(raiz);
}

bool ABB::esSubABB(Nodo* raizSubarbol) {
    bool esABBI=true, esABBD=true;

    if (raizSubarbol == NULL){
        return true;
    }else{
        if (raizSubarbol->hijoIzquierdo!=NULL)
            esABBI=(buscarMaximo(raizSubarbol->hijoIzquierdo)->contenido < raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoIzquierdo);

        if (raizSubarbol->hijoDerecho!=NULL)
            esABBD=(buscarMinimo(raizSubarbol->hijoDerecho)->contenido > raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoDerecho);
        
        return (esABBI && esABBD);
    }
}

bool ABB::esAVL() {
  return (esSubABB(raiz) && esSubAVL(raiz));
}

bool ABB::esSubAVL(Nodo* raizSubarbol) {
    if (raizSubarbol == NULL){
        return true;
    }
        
    int difAltura=alturaNodo(raizSubarbol->hijoDerecho)-alturaNodo(raizSubarbol->hijoIzquierdo);
    return (difAltura>-2 && difAltura<2 && esSubAVL(raizSubarbol->hijoIzquierdo) && esSubAVL(raizSubarbol->hijoDerecho));
}

void ABB::imprimir(){
    if(raiz==NULL){
        cout<<"VACIO"<<endl;
    } else {   
        imprimirRecorrido(raiz);
    } 
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol){
    cout<<raizSubarbol->contenido<<endl;

    if(raizSubarbol->hijoIzquierdo!=NULL){
        cout<<"I";
        imprimirRecorrido(raizSubarbol->hijoIzquierdo);
        cout<<endl;
    }
  
    if(raizSubarbol->hijoDerecho!=NULL){
        cout<<"D";
        imprimirRecorrido(raizSubarbol->hijoDerecho);
        cout<<endl;
    }
}

void ABB::leerArbol(){
    raiz=leerSubarbol(NULL);
}

Nodo * ABB::leerSubarbol(Nodo *padre){
    int contenido;
    cin>>contenido;
    if(contenido>=0){
        Nodo *arbol=new Nodo;
        
        arbol->contenido=contenido;
        arbol->hijoIzquierdo=leerSubarbol(arbol);
        arbol->hijoDerecho=leerSubarbol(arbol);
        arbol->padre=padre;
        
        return arbol;
    }
    
    return NULL;
}
