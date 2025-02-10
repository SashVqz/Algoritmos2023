#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int aux=0, aux2=0;
    
    cout << "Ingrese la palabra --> ";
    getline(cin >> ws, str);
    
    for(int i=str.length()-1;i>=0;i--) {
        if(str[i]==str[aux]) {
            aux2++; 
        }
        aux++;
    }

    if(str.length()==aux2) {
        cout << "Es palindromo" << endl;
    } else {
        cout << "No es palindromo" << endl;
    }
    
    return 0;
}