#include <iostream>
using namespace std;

int partition(int* a, int principio, int final){
	int pivot = a[final];
	int i = principio - 1;

	for (int j = principio; j < final; j++){
		if (a[j] <= pivot){
			i++;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[final]);
	return i + 1;
}

void quickSort(int* a, int principio, int final){
	if (principio < final){
		int posPivot = partition(a, principio, final);
		quickSort(a, principio, posPivot - 1);
		quickSort(a, posPivot + 1, final);
	}
}

int main(){
	int len = 9;
	int a[len] = {5, 12, 7, 1, 13, 2 ,23, 11, 18};
	
	cout << "Desordenado : ";
	for (int i = 0; i < len; i++){
		cout << a[i] << " ";
	}
	cout << endl;

	quickSort(a, 0, len - 1);
	
	cout << "Ordenado: ";
	for (int i = 0; i < len; i++){
		cout << a[i] << " ";
	}

	return 0;
}
