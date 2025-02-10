// Entrega 1 algoritmos --> sumar pares y impares

#include <iostream>
using namespace std;

int main() {
    int sumaP = 0;
    int sumaI = 0;
 
    for(int i=1;i<=10;i++) {
        if((i%2)==0) {    
            sumaP+=i;
        } else {   
            sumaI+=i;
        }
    }
 
    cout << "Pares" << sumaP << endl;
    cout << "Impares" << sumaI << endl;

    return 0;
}