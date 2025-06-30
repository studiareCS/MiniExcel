#include <iostream>
#include "interfaz.h"
#include "features/hoja.h"
using namespace std;

int main(){
    InicializarNcurses();
    

    Interfaz tabla(5, 5); // Tabla de 5x5

    int tecla;
    do { 
        tabla.MostrarTabla();

        tecla = getch();

        if (tecla == 10) { // Enter
            tabla.EditarCelda();
        } else {
            tabla.Mover(tecla);
        }

    } while (tecla != 'q');

    tabla.~Interfaz();
    delete [] tabla.datos;
    FinalizarNcurses();
return 0;
}