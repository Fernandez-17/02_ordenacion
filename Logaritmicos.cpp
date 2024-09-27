#include <iostream>
using namespace std;
void Funcion_shell_sort(int array [], int n){
 	int cen,i,aux,k;
 	k = n/2;
 	while ( k > 0){
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
		k/=2;
	}
}
void Reduce (int array [],int inicio, int final){
	int izq = inicio;
	int der = final;
	int pos = izq;
	int cen=1;
	int aux;
	while (cen == 1){
		cen=0;
		// recorrido de derecha a izquierda 
		while ( array [pos] <= array [der] && pos != der){
			der = der -1;	
		}
		if ( pos != der){
			aux = array [pos];
			array [pos] = array [der];
			array [der] = aux;
			pos = der ;
			// recorrido de izquierda a derecha
			while (array [pos] >= array[izq] && pos != izq){
				izq = izq +1;
			}
			if (pos != izq){
				aux =array [pos];
				array [pos] = array [izq];
				array [izq] = aux;
				pos = izq ;
				cen = 1;
			}
		}
		if (pos - 1> inicio){
			/*llamado recursivo a quick sort para el sub arreglo izquierdo*/
			Reduce (array,inicio, pos -1);
		}
		if (pos +1< final){
			/*llamado recursivo a quick sort para el sub arreglo derecho*/
			Reduce (array , pos +1,final);
		}
	}
}

void Funcion_quick_sort(int array [], int n){
	Reduce(array,0,n);
}

void mostrar_arreglo_ordenado (int array[], int n){
	
	cout << "\n Arreglo ordenado " << endl;
	for (int i=0 ; i<n;i++){
		cout << array[i] << " ";		
	}
	cout << endl;
}

int menu_opciones (){
	int opcion;
	cout << "\n    MENU DE OPCIONES DE METODOS DE ORDENAMIENTOS ALGORITMICOS \n" << endl;
	cout << "1.Metodo shell sort"   << endl;
	cout << "2.Metodo quick sort"   << endl;
	cout << "3.Salir del programa"  << endl;
	cout << " \nSeleccione una opcion :";
	cin  >> opcion; 
	return opcion;
}

void solicitar_datos(int array [], int &n){
	
	cout << "\nIngrese la cantidad de elementos del arreglo: ";
	cin  >> n;
	
	for(int i = 0; i<n; i++){
		cout << "Elemento [ "<<i+1<<"]: ";
		cin  >> array[i];
	}
	
	cout << "\n   Arreglo actual   \n" << endl;
	for (int i=0 ; i<n ; i++){
		cout << array [i] << " ";
	}
	cout << endl;
}

int main (){
	int tam,opcion;
	int array [50];
	
	do {
	opcion = menu_opciones();
	
	switch(opcion){
		case 1:
			solicitar_datos(array, tam);
			Funcion_shell_sort (array, tam);
			mostrar_arreglo_ordenado(array, tam);
			break;
		case 2:
			solicitar_datos(array, tam);
			Funcion_quick_sort (array, tam-1);
			mostrar_arreglo_ordenado(array, tam);
			break;
		case 3:
		    cout << "Saliendo del programa  .    .    .    " << endl;
			break;
		default:
			cout << "Opcion inavlida intentelo nuevamente  " << endl;
			break;		
	}
}while (opcion !=3);

	return 0;
}

