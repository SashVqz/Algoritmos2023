#include<iostream>
#include<string.h>
using namespace std;

/*
    Precondiciones ninguna
    Complejidad temporal T(n) = T(n-2) + 1 --> O(n)
    Complejidad espacial M(n) = M(n-2) + 1 --> O(n)
*/

bool esPalindromo(const string &text, int posI, int posF);

int main(){
  char palabra[20];
  int tam;
  cin>>palabra;
  tam=strlen(palabra);
  
  if(tam>0){
    cout<< esPalindromo(palabra, 0, tam)<< endl;
  }

  return 0;
}

bool esPalindromo(const string &text, int posI, int posF){
    if(text.length()==1) return true;

    if (text[posI]!=text[posF])return false;

    if (posI<(posF+1)) return esPalindromo(text, posI++, posF--);

    return true;
}