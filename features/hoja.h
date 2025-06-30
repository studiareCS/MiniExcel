#ifndef __HOJA_H__
#define __HOJA_H__

#include "types.h"
#include "../values.h"
#include <vector>
using namespace std;

class Hoja{
    private:
        Hoja_NameType nombre = 0;
        size_t filas = FILAS_INICIALES;
        size_t columnas = COLUMNAS_INICIALES;

    public:

        // Establecer el tamaño inicial de la tabla
        vector <vector<int>> tabla;

        // Destructor
        virtual ~Hoja();

        // Aumentar filas
        void aumentarFila();

        // Aumentar columnas
        void aumentarColumna();

        // Getters y Setters
        Hoja_NameType getNombre() const {
            return nombre;
        }
        void setNombre(Hoja_NameType nuevoNombre) {
            nombre = nuevoNombre;
        }

        size_t getFilas() const {
            return filas;
        }
        void setFilas(size_t nuevasFilas) {
            if (nuevasFilas > 0) {
                filas = nuevasFilas;
            }
        }

        size_t getColumnas() const {
            return columnas;
        }
        void setColumnas(size_t nuevasColumnas) {
            if (nuevasColumnas > 0) {
                columnas = nuevasColumnas;
            }
        }
};

void DemoHoja();

#endif // __HOJA_H__