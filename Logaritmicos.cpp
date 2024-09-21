#include <iostream>
using namespace std;
void Funcion_shell_sort(int array [], int n){
 	int cen,i,aux,k;
 	k = n+1;
 	while ( k > 1){
 		k = k/2;
 		cen = 1;
 		while (cen == 1){
 			cen = 0;
 			i   = 0;
 			while(i+k < n){
 				if (array [i+k] < array[i]){
 					aux = array [i];
 					array [i] = array [i+k];
 					array[i+k] = aux;
 				    cen = 1;
				}
				i = i+1;
			}
		}
	}
}

void mostrar_arreglo_ordenado (int array[], int n){
	
	cout << "\n Arreglo ordenado " << endl;
	for (int i=0 ; i<n;i++){
		cout << array[i] << " ";		
	}
	cout << endl;
}


int main (){
	int tam;
	int array [50];
	cout << "\n   PROGRAMA DE ORDENAMIENTO DE UN ARREGLO    " << endl;
	cout << "\n            METODO SHELL SORT                " << endl;
	cout << "\nIngrese la cantidad de elementos: ";
	cin  >> tam;
	
	for(int i=0 ; i <tam; i++){
		cout << "\nElemento ["<< i+1 <<"] : ";
		cin  >> array[i];
	}
	
	cout << " \n  Arreglo actual  " << endl;
	for (int i = 0; i<tam; i++){
		cout <<array[i] << " ";
	}
	cout << endl;
	
	Funcion_shell_sort (array, tam);
	mostrar_arreglo_ordenado(array, tam);
	
	return 0;
}

