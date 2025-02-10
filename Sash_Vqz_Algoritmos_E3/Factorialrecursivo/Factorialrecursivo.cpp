#include <iostream>
using namespace std;

#define assertdomjudge(x) if(!(x)){cout<<"ERROR"<<endl; exit(0);}

/*
    Precodndiciones --> n>=0 | r>=0 | n>=r | n y r naturales {1 , 2, ... , n } 
    Complejidad temporal de factorial T(n)= T(n-1) + 1 --> O(n)
    Complejidad espacial de factorial O(n)
*/

int factorial(int n);
int combinaciones(int n, int r);

int main(){
    bool aux = true;
	int n=0, r=0;
    do{
        cin >> n >> r;
        if(n<0){
    	   aux=false;
        }else{
           assertdomjudge((n>0 && r>0) && (n>=r));
    	   cout << combinaciones(n, r) << "\n";
           cout << endl;
        }
    }while(aux==true);

    return 0;
}

int factorial(int n){
    if (n==0){
        return 1;
    } else {
    	return n*factorial(n-1);
    }
}

int combinaciones(int n, int r) {
	return (factorial(n)/(factorial(r)*factorial(n-r)));
}
