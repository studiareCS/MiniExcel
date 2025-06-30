#ifndef __INTERFAZ_H__
#define __INTERFAZ_H__
#include <string>
#include <ncurses.h>
using namespace std;

class Interfaz {
    public:

    int cursorRow;
    int cursorCol;
    int filas;
    int columnas;
    string ** datos;

    

    Interfaz(int filas, int columnas);
    ~Interfaz();
    void Mover(int tecla);
    void MostrarTabla();

    void EditarCelda();


    void up();
    void right();
    void left(); 
    void down();

    
};
    void Menu();
    void InicializarNcurses();
    void FinalizarNcurses();

#endif // __INTERFAZ_H__