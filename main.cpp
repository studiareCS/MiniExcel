#include <iostream>
#include "interfaz.h"
#include "features/hoja.h"
using namespace std;

int main(){
    InicializarNcurses();
    
    Interfaz tabla(10, 10); // Tabla de n*n

    int tecla;
    do { 
        tabla.MostrarTabla();
        tecla = getch(); 

        if (tecla == 10) {  // codigo Ascii de enter 
            tabla.EditarCelda();
        } else {
            tabla.Mover(tecla);
        }

    } while (tecla != 'q');

    tabla.~Interfaz();
    FinalizarNcurses();
    
return 0;
}