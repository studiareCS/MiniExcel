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

Hoja::~Hoja() {
    // Destructor vacío, ya que no hay recursos que liberar
}