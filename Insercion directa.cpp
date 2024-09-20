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

int Funcion_insercion_directa( int array [],int n){
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

int Funcion_insercion_binaria( int array [],int n){
	int aux,izq,der,m,j;
	for ( int i=1 ; i <n ;i++){
	    aux = array [i];
		izq =0;
		der = i-1;
		while ( izq <= der){
			m =(izq + der ) /2;
			if (aux < array [m]){
				der = m -1;
			} else{
				izq = m + 1;
			}	
		}
		j = i -1 ;
		while ( j >= izq ){
			array [j+1] = array [j];
			j = j--; 
		}
		array [izq] = aux;
	}
}

int main (){
	int array[50];
	int N, opcion;
	
	do {
	cout << "    MENU DE ORDENAMIENTO POR INSERCION " << endl;
	cout << "1.Mentodo insercion directa" << endl;
	cout << "2.Metodo insercion binaria " << endl;
	cout << "3.Salir del programa"        << endl;
	cout << "\n Seleccione una opcion : ";
	cin  >> opcion;
	
	    switch(opcion){
		    case 1: 
		    solicitar_datos(array,N);
			Funcion_insercion_directa(array,N);
			mostrar_arreglo_ordenado(array,N);
			break;
		    case 2: 
			solicitar_datos(array,N);
			Funcion_insercion_binaria(array,N);
			mostrar_arreglo_ordenado(array,N);
		    case 3:
			cout << "    Saliendo del programa .  .  .  " << endl;
			}
		} while (opcion !=3);
	return 0;
}