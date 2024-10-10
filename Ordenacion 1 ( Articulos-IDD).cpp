/*Se tienen los siguientes atributos de un art�culo: c�digo, descripci�n, precio, cantidad. 
Ordene un conjunto de art�culos descendentemente seg�n el monto de inversi�n (el monto de
inversi�n se calcula multiplicando el precio de cada art�culo por la cantidad de art�culos).
 Use ordenaci�n por intercambio directo por la derecha.*/
#include <iostream>
#include <string>
using namespace std;

struct Articulo{
	string cod;
	string des;
	double precio;
	int cant;
};

void Ordenacion_intercambio_directo_por_la_derecha ( Articulo arrayArt[] ,int n){
	Articulo aux;
	//Ordene un conjunto de art�culos descendentemente seg�n el monto de inversi�n
	for (int i=0; i<n;i++){
		for(int j = n-1;j >i ;j--){
			if( arrayArt[j].cant * arrayArt[j].precio > arrayArt [j-1].cant * arrayArt [j-1].precio){
				aux = arrayArt [j];
				arrayArt[j]= arrayArt [j-1];
				arrayArt [j-1] = aux;
			}
		}
	}
}



int main (){
	Articulo arrayArt [50];
	int tam ;
	cout << "Ingrese la cantidad de elementos: ";
	cin  >> tam;
	
	cout << "\n                        ARTICULOS                  \n"<< endl;
	for (int i=0 ; i <tam ; i++){
		cout << "............................."<< endl;
		cout << "\nArticulo "<<i+1<< " : \n" << endl;
		cout << "Codigo     : ";
		cin  >> arrayArt[i].cod;
		cout << "Descripcion: ";
		cin  >> arrayArt[i].des;
		cout << "Precio     : ";
		cin  >> arrayArt[i].precio;
		cout << "Cantidad   : ";
		cin  >> arrayArt[i].cant;
	}
	
	Ordenacion_intercambio_directo_por_la_derecha ( arrayArt ,tam);
	cout << "\n                   ARTICULOS ORDENADOS             \n"<< endl;	
	for (int i=0; i<tam ; i++){
		cout <<" -------------------------------------------"<< endl;
		cout <<"\nArticulo "<<i+1<<" : \n"<< endl;
		cout <<"Codigo      : "<< arrayArt[i].cod    << endl;
		cout <<"Descripcion : "<< arrayArt[i].des    << endl;
		cout <<"Precio      : "<< arrayArt[i].precio << endl;
		cout <<"Cantidad    : "<< arrayArt[i].cant  << endl;
	}
	
	
	
	
	return 0;
}
