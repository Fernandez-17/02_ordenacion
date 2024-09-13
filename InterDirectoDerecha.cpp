//ordenacion por intercambio directo
#include<iostream>
using namespace std;

void ord_array_derecha(int n, int array[] ){
	// por la derecha
	int aux;
	for (int i=0 ; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if (array[j] = array[j+1]){
				aux = array[j];
				array[j] = array [j+1];
				array[j+1]= aux;
			}
		}
	}
}

int main (){
	int N, aux;
	int array[50];

	cout <<"   BIENVENIDO AL PROGRAMA DE ORDENACION DE LOS ELEMENTOS DE UN ARREGLO   " << endl;
	cout << "Ingrese el numero de elementos del arreglo" << endl;
	cin  >> N;
		
	for (int i = 0; i < N; i++){
		cout <<"Elemento["<<i+1<<"]:";
		cin  >> array[i];
	} 
	cout << "Arreglo antes de ordenar"<< endl;
		for (int i=0 ;i < N; i++){
		cout << array[i]<< " ";
	}
	cout << endl;
	
	ord_array_derecha (N,array);
	
	cout << "Arreglo ordenado: ";
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;


	return 0;
}