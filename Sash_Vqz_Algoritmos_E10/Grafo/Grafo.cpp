#include <iostream>
#include<stdlib.h>

using namespace std;

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

int** matrizAyacencia(int n);
void rellenarMatrizAyacencia(int v, int a, int **m, char* grupo);
void imprimir(int v, int **m);

bool esBipartido(int v, int** m, char* grupo);

/**
 * @brief The main function of the program.
 * 
 * This function reads input from the user, creates a graph, and checks if the graph is bipartite.
 * It repeatedly prompts the user for the number of vertices and edges until the user enters 0 for the number of vertices.
 * For each input, it creates an adjacency matrix and a group array, fills them with user-provided values, and checks if the graph is bipartite.
 * Finally, it deallocates the memory used by the adjacency matrix.
 * 
 * @return 0 indicating successful execution of the program.
 */
int main(){
    bool aux=true;
	int v=0, a=0;
	int **m;
    char *grupo;

    do{
        cin >> v;

        if(v==0){
    	   aux=false;
        }else{
            assertdomjudge(v>=1 && v<=100);
            
            cin >> a;
            
            m=matrizAyacencia(v);
            grupo=new char[v];
            
            rellenarMatrizAyacencia(v, a, m, grupo);

            if (esBipartido(v, m, grupo)){
                cout << "SI" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }while(aux==true);

    for (int i=0;i<v;i++){
        delete[] m[i];
    }

    return 0;
}

int** matrizAyacencia(int n){
    int **m=new int*[n];
    for (int i=0;i<n;i++) {
        m[i]=new int[n];
        for (int j=0;j<n;j++) {
            m[i][j]=0;
        }
    }

    return m;
}

void imprimir(int v, int **m){
    for (int i=0;i<v;i++){
        for (int j=0;j<v;j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void rellenarMatrizAyacencia(int v, int a, int **m, char* grupo){
    int v1=0, v2=0;
    for (int i=0;i<a;i++) {
        cin >> v1 >> v2;

        assertdomjudge(v1>=0 && v1<v && v2>=0 && v2<=v);
        assertdomjudge(v1!=v2);
        assertdomjudge(m[v1][v2]!=1 && m[v2][v1]!=1);

        m[v1][v2]=1;
        m[v2][v1]=1;

        grupo[v1]=' ';
        grupo[v2]=' ';
    } 
}

bool esBipartido(int v, int** m, char* grupo){
    grupo[0]='R';
    for (int i=0;i<v;i++) {
        for (int j=0;j<v;j++) {
            if (m[i][j]==1 && m[j][i]==1) {
                if (grupo[j]==' ' && grupo[i]=='R') {
                    grupo[j]='B';
                }
                
                if (grupo[j]==' ' && grupo[i] =='B') {
                    grupo[j]='R';
                }
            }
        }
    }

    for (int i=0;i<v;i++) {
        for (int j=0;j<v;j++) {
            if (m[i][j]==1 && m[j][i]==1 && grupo[i]==grupo[j]) {
                return false;
            }
        }
    }

    return true;
}