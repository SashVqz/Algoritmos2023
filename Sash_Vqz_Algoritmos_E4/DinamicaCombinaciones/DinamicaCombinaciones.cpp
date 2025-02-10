#include <iostream>
using namespace std;

#define assertdomjudge(x) if(!(x)){cout<<"ERROR"<<endl;}

int** pascal(int n);

int main(){
    int n=0, r=0;
    int **m=pascal(11);

    cin >> n >> r;
    while(n >= 0){
        if((r < 0) || (r > n)){
            cout << "ERROR\n";
        } else{
            cout << m[n][r] << "\n";
        }
        cin >> n >> r;
    }

    return 0;
}

int** pascal(int n){
    int **m=(int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        m[i]=(int*)malloc((i+1)*sizeof(int));
        for(int j=0;j<(i+1);j++){
            if(i<=1 || j==0 || j==i){
                m[i][j]=1;
            }else{
                m[i][j]=m[i-1][j-1]+m[i-1][j];
            }
        }
    }

    return m;
}
