#include "hoja.h"

void DemoHoja(){
    Hoja hoja;
    hoja.setNombre(1);
    hoja.setFilas(20);
    hoja.setColumnas(15);

    std::cout << "Nombre de la hoja: " << hoja.getNombre() << std::endl;
    std::cout << "Filas: " << hoja.getFilas() << std::endl;
    std::cout << "Columnas: " << hoja.getColumnas() << std::endl;
    
}

// Agregar nueva fila al final de la tabla
void Hoja::aumentarFila(){
    filas++;
    vector<int> nuevaFila(columnas, 0); // Crear una nueva fila con el número de columnas y llenarla con ceros
    tabla.push_back(nuevaFila);         // Redimensionar la tabla
}

// Agregar nueva columna al final de la tabla
void Hoja::aumentarColumna(){
    columnas++;
    for (auto& fila : tabla) {
        fila.push_back(0); // Agregar un nuevo elemento con valor 0 a cada
    }
}

Hoja::~Hoja() {
    // Destructor vacío, ya que no hay recursos que liberar
}