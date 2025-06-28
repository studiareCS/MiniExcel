#ifndef __HOJAS_H__
#define __HOJAS_H__

#include "types.h"

class Hoja{
    private:
        Hoja_NameType nombre = 0;
        size_t filas = 10;
        size_t columnas = 10;

    public:
        
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

#endif // __HOJAS_H__