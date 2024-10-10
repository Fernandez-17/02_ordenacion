/*Se tienen los siguientes atributos de personal: DNI, nombres, día, mes y año de nacimiento. 
Se pide ordenar por fecha de nacimiento. Sugerencia: Use dos registros (uno para personal y 
otro para fecha) y dos funciones (una para la ordenación por selección directa y otra para la
comparación de dos fechas).*/
#include <iostream>
using namespace std;

struct Fecha {    
    int dia;
    int mes;
    int anio;
};

struct Persona {
    string nombre;
    string DNI;
    Fecha nacimiento;
};

bool Comparar_fechas(const Fecha& f1, const Fecha& f2) {
    if (f1.anio != f2.anio) {
        return f1.anio < f2.anio; 
    }
    if (f1.mes != f2.mes) {
        return f1.mes < f2.mes; 
    }
    return f1.dia < f2.dia; 
}

void Ordenacion_por_seleccion_directa(Persona array[], int n) {
    Persona menor;
    int k;
    
    for (int i = 0; i < n - 1; i++) {
        menor = array[i]; 
        k = i; 
        for (int j = i + 1; j < n; j++) {
            if (Comparar_fechas(array[j].nacimiento, menor.nacimiento)) {
                menor = array[j];
                k = j; 
            }
        }
        if (k != i) {
            array[k] = array[i]; 
            array[i] = menor;   
        }
    }
}

int main() {
    int tam;
    Persona array[50];
    cout << "Ingrese la cantidad de personas: ";
    cin >> tam;

    for (int i = 0; i < tam; i++) {
        cout << "\n----------------------------\n";
        cout << "Persona " << (i + 1) << ":\n";
        cout << "Nombre: ";
        cin >> array[i].nombre;
        cout << "DNI   : ";
        cin >> array[i].DNI;
        cout << "Fecha de Nacimiento:\n";
        cout << "Dia   : ";
        cin >> array[i].nacimiento.dia;
        cout << "Mes   : ";
        cin >> array[i].nacimiento.mes;
        cout << "Anio  : ";
        cin >> array[i].nacimiento.anio;
    }
    
    Ordenacion_por_seleccion_directa(array, tam);
    
    cout << "\n        PERSONAL ORDENADO POR FECHAS           \n";
    for (int i = 0; i < tam; i++) {
        cout << "\n----------------------------\n";
        cout << "Persona " << (i + 1) << ":"  << endl;
        cout << "Nombre: " << array[i].nombre << endl;
        cout << "DNI   : " << array[i].DNI    << endl;
        cout << "Fecha de Nacimiento: " 
             << array[i].nacimiento.dia  << "/" 
             << array[i].nacimiento.mes  << "/" 
             << array[i].nacimiento.anio << "\n";
    }
    return 0;
}


