#include<iostream>
using namespace std;
//FUNCIONES PARA REALIZAR LOS TIPOS DE ORDENAMIENTO

void ord_array_derecha(int n, int array[] ){
	// por la derecha
	int aux;
	for (int i= 0 ; i< n-1 ; i++){
		for(int j= 0; j< n-i-1 ; j++){
			if (array[j] > array[j+1]){
				aux       = array[j];
				array[j]  = array [j+1];
				array[j+1]= aux;
			}
		}
	}
}

void ord_array_izquierda(int n, int array[]){
	//por la izquierda
	int aux;
	for(int i= n-1 ; i> 0 ; i--){
		for(int j= 0 ; j<i ; j++){
			if(array[j] > array[j+1]){
				aux        = array[j];
				array[j]   = array[j+1];
				array[j+1] = aux;
			}	
		}
	}
}

void ord_array_con_senial(int n, int array[]) {
    // con señal (centinela)
    int centinela = 1;
    int i = 1;
    int aux;
    
    while (i <= n-1 && centinela == 1) {
        centinela = 0;
        for (int j = 0; j < n-i; j++) {  
            if (array[j] > array[j+1]) {
                aux        = array[j];
                array[j]   = array[j+1];
                array[j+1] = aux;
                centinela = 1;
            }
        }
        i = i + 1;
    }
}

void ord_array_bidireccional(int n, int array[]){
    int izquierda = 0;
    int derecha = n - 1;
    bool intercambio = true; 
    int aux;
    
    while (intercambio){
        intercambio = false;
        
        for (int i = izquierda; i < derecha; i++){
            if (array[i] > array[i+1]){
                aux        = array[i];
                array[i]   = array[i+1];
                array[i+1] = aux;
                intercambio= true;
            }
        }
        
        if (!intercambio ) break;
        
        intercambio  = false;
        derecha--; 
        
        for (int i = derecha; i > izquierda; i--){
            if (array[i-1] > array[i]){
                aux        = array[i-1];
                array[i-1] = array[i];
                array[i]   = aux;
                intercambio= true;
            }
        }
        
        izquierda++; 
    }
}
void solicitar_datos(int &N, int array[]){
	cout <<"\n   BIENVENIDO AL PROGRAMA DE ORDENACION DE LOS ELEMENTOS DE UN ARREGLO   " << endl;
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

void mostrar_arreglo_ordenado(int N, int array[]){
	cout << "\n   Arreglo ordenado " << endl;
    for (int i = 0; i < N ; i++) {
        cout << array[i] << " ";
    }
    cout << endl;	
}

int menu_opciones(){
	int opcion;
	cout << "\n  MENU DE OPCIONES DE ORDENAMIENTO DIRECTO  \n"<<endl;
	cout <<"1.Intercambio directo por la derecha  " << endl;
	cout <<"2.Intercambio directo por la izqueirda" << endl;
	cout <<"3.Intercambio directo con señal       " << endl;
	cout <<"4.Intercambio directo bidireccional   " << endl;
	cout <<"5.Salir del programa                  " << endl;
	cout <<"\nSeleccione un opcion: ";
	cin  >> opcion;
	return opcion;
}


int main (){
	int opcion, N;
	int array[50];
	do{
		opcion = menu_opciones();
		switch(opcion){
			case 1:
				solicitar_datos(N, array);
				ord_array_derecha(N, array);
				mostrar_arreglo_ordenado(N, array);
				break;
			case 2:
				solicitar_datos(N, array);
				ord_array_izquierda(N, array);
				mostrar_arreglo_ordenado(N, array);
				break;
			case 3:
				solicitar_datos(N, array);
                ord_array_con_senial(N, array);
                mostrar_arreglo_ordenado(N, array);
				break;
			case 4:
				//
				solicitar_datos(N, array);
                ord_array_bidireccional(N , array);
                mostrar_arreglo_ordenado(N, array);
				break;
			case 5:
				cout << "\nSALIENDO DEL PROGRAMA .  .  .  " << endl;
				break;
			default:
				cout << "\nOpcion invalida , intentelo de nuevo" << endl;
				break;	
		}
	} while(opcion!=5);
	return 0;
}
