#include "core.h"
#include "../values.h"
#include "../interfaz.h"

#include <iostream>
using namespace std;


void sumarCeldas(int hoja[FILAS_INICIALES][COLUMNAS_INICIALES], int fila1, int columna1, int fila2, int columna2, int filaR, int columnaR){
    hoja[filaR][columnaR] = hoja[fila1][columna1] + hoja[fila2][columna2];
}

void restarCeldas(int hoja[FILAS_INICIALES][COLUMNAS_INICIALES], int fila1, int columna1, int fila2, int columna2, int filaR, int columnaR){
    hoja[filaR][columnaR] = hoja[fila1][columna1] - hoja[fila2][columna2];
}

void multiplicarCeldas(int hoja[FILAS_INICIALES][COLUMNAS_INICIALES], int fila1, int columna1, int fila2, int columna2, int filaR, int columnaR){
    hoja[filaR][columnaR] = hoja[fila1][columna1] * hoja[fila2][columna2];
}

void dividirCeldas(int hoja[FILAS_INICIALES][COLUMNAS_INICIALES], int fila1, int columna1, int fila2, int columna2, int filaR, int columnaR){
    if (hoja[fila2][columna2] != 0) {
        hoja[filaR][columnaR] = hoja[fila1][columna1] / hoja[fila2][columna2];
    } else {
        hoja[filaR][columnaR] = 0; // No se puede dividir por cero, por tanto se asigna 0
    }
}

void Demo(){
    int hoja[FILAS_INICIALES][COLUMNAS_INICIALES];

}