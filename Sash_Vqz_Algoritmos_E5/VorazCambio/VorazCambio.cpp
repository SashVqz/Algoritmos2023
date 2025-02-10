#include <iostream>
using namespace std;

#define TAM 8

void devolucion(int n);

int main(){
   int n=0;

   cin >> n;
   while(n>=0){
      devolucion(n);
      cin >> n;
   }

   return 0;
}

void devolucion(int n){
   int monedas[]={500,200,100,50,25,10,5,1};
   int solve[TAM];

   for (int i=0;i<TAM;i++){
      solve[i]=0;
   }
   
   if (n>=1){
      for (int j=0;j<TAM;j++){
         while (n>=monedas[j]){
            solve[j]++;
            n-=monedas[j];
         }
      }
   }

   for (int k=0;k<TAM;k++){
      cout << solve[k]<< " ";
   }
   cout << "\n";
}