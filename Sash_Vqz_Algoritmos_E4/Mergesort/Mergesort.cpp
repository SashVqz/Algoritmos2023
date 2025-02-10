#include<iostream>
using namespace std;

void  combinar (int a[], int len_a, int b[], int len_b, int c[]);
void ordenarMergeSort (int x[], int len);

int main(){
  int n=0;
  cin>>n;
  int* x=new int[n];
  
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  ordenarMergeSort(x, n);
}

void ordenarMergeSort (int x[], int len){
  int posM=len/2;
  int* temp=new int[len];

  if (len==1){
    return;
  }else{
    ordenarMergeSort(&x[0], posM); // iqz

    ordenarMergeSort(&x[posM], len-posM); // der

    combinar(&x[0], posM, &x[posM], len-posM, temp);

    for (int k=0;k<len;k++) {
      x[k]=temp[k];
      cout<<x[k]<<" ";
    }
    cout<<endl;
  }
}

void  combinar (int a[], int len_a, int b[], int len_b, int c[]){
  int i=0, j=0, k=0;

  while((i<len_a) && (j<len_b)){
    if(a[i]<=b[j]){
      c[k]=a[i];
      i++;
    }else{
      c[k]=b[j];
      j++;
    }
    k++;
  }

  while(i<len_a){
    c[k]=a[i];
    k++;
    i++;
  }

  while(j<len_b){
    c[k]=b[j];
    k++;
    j++;
  }
}