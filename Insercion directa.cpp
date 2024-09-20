#include <iostream>
using namespace std;

void solicitar_datos(int array[], int &N){
	cout <<"\n   BIENVENIDO AL PROGRAMA DE ORDENACION DE LOS ELEMENTOS DE UN ARREGLO   " << endl;
	cout <<"\n                       METODO INSERCION DIRECTA                          " << endl;
	cout <<"\n Ingrese el numero de elementos del arreglo: ";
	cin  >> N;
	cout << endl;
		
	for (int i = 0; i < N ; i++){
		cout <<"Elemento["<<i+1<<"]:";
		cin  >> array[i];
	} 
	cout << "\n   Arreglo actual   "<< endl;
		for (int i=0 ; i < N ; i++){
		cout << array[i]<< " ";
	}
	cout << endl;

}

void mostrar_arreglo_ordenado(int array[],int n){
    cout << "\n   Arreglo ordenado   " << endl;
	for (int i =0; i <n; i++){
		cout << array [i] << " ";
	}
	cout << endl;
}

int Funcion_seleccion_directa( int array [],int n){
	int aux, k;
	for ( int i=1 ; i <n ;i++){
		 aux = array [i];
		k = i-1;
		while ( k > -1 && aux < array[k]){
			array [k+1] = array [k];
			k = k -1;
		}
		array [k+1] = aux;
	}
}

int main (){
	int array[50];
	int N;
	solicitar_datos(array,N);
	Funcion_seleccion_directa(array,N);
	mostrar_arreglo_ordenado(array,N);
	return 0;
}