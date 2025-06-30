#include <iostream>
#include "interfaz.h"
#include "features/hoja.h"
using namespace std;

int main(){
    InicializarNcurses();
    Interfaz mc(10,10);

int Tabla;
do {

    mc.MostrarTabla();
    Tabla = getch();
    mc.Mover(Tabla);

} while (Tabla != 'q');

    FinalizarNcurses();
    // DemoHoja();
    return 0;
}