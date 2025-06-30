#include "interfaz.h"
using namespace std;

void InicializarNcurses() {
    initscr(); //cambia la terminal a tamaño completo
    noecho();  //hace que no se muestren los caracteres introducidos por el usuario
    cbreak();  //hace que la entrada de teclado se procese inmediatamente
    keypad(stdscr, TRUE); //permite que getch() detecte teclas especiales
    curs_set(0); //para la interfaz más limpia
}

void FinalizarNcurses() {
    endwin();
}   

void Interfaz::Mover(int tecla) {
    
    switch (tecla)
    {
    case KEY_UP:
        up();
        return;
    case KEY_DOWN:
        down();
        return;
    case KEY_LEFT:
        left();
        return;
    case KEY_RIGHT:
        right();
        return;
    }

}


void Interfaz::MostrarTabla() {
    clear();

    // Encabezados de columna
    for (int c = 0; c < columnas; ++c) {
        mvprintw(1, 8 + c * 12, "Col %d", c);
    }

    // Filas
    for (int r = 0; r < filas; ++r) {
        mvprintw(3 + r * 2, 0, "Fila %d", r);

        for (int c = 0; c < columnas; ++c) {
            int y = 3 + r * 2;
            int x = 8 + c * 12;

            // Si es la celda activa, resaltamos
            if (r == cursorRow && c == cursorCol) {
                attron(A_REVERSE); // Invierte colores
                mvprintw(y, x, "     ");
                attroff(A_REVERSE);
            } else {
                mvprintw(y, x, "     ");
            }
        }
    }

    refresh();
}

//Constructor    
Interfaz::Interfaz(int fil, int col) : cursorRow(0), cursorCol(0), filas(fil), columnas(col) {}


void Interfaz::up() {
    cursorRow = (cursorRow - 1 + filas) % filas;
}

void Interfaz::down() {
    cursorRow = (cursorRow + 1) % filas;
}

void Interfaz::left() {
    cursorCol = (cursorCol - 1 + columnas) % columnas;
}

void Interfaz::right() {
    cursorCol = (cursorCol + 1) % columnas;
}




