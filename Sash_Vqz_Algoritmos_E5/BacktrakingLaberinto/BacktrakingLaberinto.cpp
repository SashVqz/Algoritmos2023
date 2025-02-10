 #include<iostream>
using namespace std;
#define TAM 10

void crearLab(char **lab);
bool recorrerLab(char **lab, int &x, int &y);

int main(){
    int x=0,y=0;
    char** lab;
    
    lab=new char *[TAM];
    for(int i=0; i<TAM; i++){
        lab[i]=new char[TAM];
    }
    crearLab(lab);

    if(!recorrerLab(lab, x, y)){
        cout << "INALCANZABLE" << endl;
    }
    
    return 0;
}

void crearLab(char **lab){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            cin>>lab[i][j];
        }
    }
}

bool solveLab(char **lab, int &x, int &y){
    bool aux=false;
    int k=0;
    int X[4]={-1,0,1,0}, Y[4]={0,1,0,-1};

    while(k<4 && !aux){
        lab[x][y]='X';
        
        int i=x+X[k];
        int j=y+Y[k];

        if(i>-1 && j>-1 && i<TAM && j<TAM){
            if(lab[i][j]=='.' || lab[i][j]=='T'){
                if(lab[i][j]=='.'){
                    aux=solveLab(lab, i, j);

                    if(lab[i][j]=='X' && !aux){
                        lab[i][j]='#';
                        aux=false;
                    }
                } else { 
                    aux=true; 
                    
                    x=i;
                    y=j;

                    for(int i=0;i<TAM;i++){
                        for(int j=0;j<TAM;j++){
                            
                            if(lab[i][j]=='#'){
                                lab[i][j]='.';
                            }

                            if(lab[0][0]=='.'){
                                lab[i][j]='X';
                            }

                            cout << lab[i][j];
                        }
                        cout << "\n";
                    }

                    cout << "ENCONTRADO " << i << " " << j << endl;
                }   
            } 
        }
        k++;
    }

    return aux;
}