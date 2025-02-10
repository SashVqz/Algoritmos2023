#include<iostream>
#include<stdlib.h>

using namespace std;

char calcular_ganador(char *equipos, int n, int ronda){
    int posM=n/2;
    char* temp= new char[posM];

    if(n==2){
        if((ronda%2)==0){
            cout << "Ronda " << ronda << " Ganador " << equipos[0] << "\n";
            return equipos[0]; 
        } else {
            cout << "Ronda " << ronda << " Ganador " << equipos[1] << "\n";
            return equipos[1];
        }
    } else {
        temp[0]=calcular_ganador(&equipos[0], posM, ronda+1);
        temp[1]=calcular_ganador(&equipos[posM], n-posM, ronda+1); 

        return calcular_ganador(&temp[0], 2, ronda);
    }
}

int main() {
    int n;
    cin >> n;
    char *equipos = new char[n+1];

    for(int i = 0;i <n; i++){
        equipos[i]='A'+i;
    }
    
    equipos[n]=0;
    calcular_ganador(equipos,n,0);
}