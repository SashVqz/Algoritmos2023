#include<iostream>
#include"ListaCircular.h"
using namespace std;

int main(){
  int n_recamaras;
  int giro;
  int pos_bala;
  string disparo;
 
  cin>>n_recamaras;

  cin>>pos_bala;
  
  ListaCircular pistola;
  for(int i=0;i<n_recamaras;i++){
    if(i==pos_bala){
      pistola.insertar(i,"BANG");
    }else{
      pistola.insertar(i,"CLACK");
    }
  }
  
  do{
    cin>>giro;
    pistola.girar(giro);
    disparo=pistola.getValor(0);
    cout<<disparo<<endl;
  }while(disparo!="BANG");

  for(int i=0;i<n_recamaras;i++){
    pistola.eliminar(0);
  }
   
  return 0;
}
