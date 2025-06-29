#ifndef __INTERFAZ_H__
#define __INTERFAZ_H__
#include <string>
#include <ncurses.h>

class Interfaz {
    public:

    int cursorRow=0;
    int cursorCol=0;
    int filas;
    int columnas;

    Interfaz(int filas, int columnas);
    void Mover(int tecla);
    void MostrarTabla();
    void up();
    void right();
    void left();
    void down();

};


void InicializarNcurses();
void FinalizarNcurses();
void Menu();
#endif // __INTERFAZ_H__