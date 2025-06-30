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
    Menu();    
    // Encabezados de columna
    for (int c = 0; c < columnas; ++c) {
        mvprintw(8, 17 + c * 12, "Col %d", c);
    }

    // Filas
    for (int f = 0; f < filas; ++f) {
        mvprintw(10 + f * 2, 0, "Fila %d", f);

        for (int c = 0; c < columnas; ++c) {
            int y = 10 + f * 2;  
            int x = 15 + c * 12;

            // Si es la celda activa, resaltamos
            if (f == cursorRow && c == cursorCol) {
                attron(A_REVERSE); // Invierte colores
                mvprintw(y, x, "|%-5s|", datos[f][c].c_str());
                attroff(A_REVERSE);
            } else {
                mvprintw(y, x, "|%-5s|", datos[f][c].c_str());
            }
        }
    }

    refresh();
}

//Constructor    cd M
Interfaz::Interfaz(int fil, int col) {
    cursorRow=0;
    cursorCol=0;
    filas=fil;
    columnas=col;

    // Inicializamos la matriz de datos
    // Usamos un puntero a puntero para crear una matriz dinámica de strings
    datos= new string*[filas];
    for(int i=0; i<filas; i++){
        datos[i]= new string[columnas];
    }
} 

Interfaz::~Interfaz(){}


void Interfaz::EditarCelda(){
    char buffer[10];

    echo();          // Hacer que se muestre lo que escribes
    curs_set(1);     // Mostrar cursor

    // Pedir entrada en la parte inferior
    move(filas * 4, 0);
    getnstr(buffer, 9); //lee hasta 50 caracteres

    // Guardar el texto en la celda activa
    datos[cursorRow][cursorCol] = buffer;


    clrtoeol();

    noecho();        // Ocultar input
    curs_set(0);     // Ocultar cursor
}

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

void Menu(){
    mvprintw(0, 0, "---------------");
    mvprintw(1, 0, "MiniExcel");
    mvprintw(2, 0, "---------------");
    mvprintw(3, 0, "1. Editar celda (Enter)");
    mvprintw(4, 0, "2. Mover cursor (Flechas)");
    mvprintw(5, 0, "3. Salir (q)");
}




