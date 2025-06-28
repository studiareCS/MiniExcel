# MAKEFILE PARA COMPILAR EL PROYECTO MINIEXCEL

# Definición de variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -pthread
LDFLAGS = -pthread

# Nombre del ejecutable
TARGET = main

# Archivos fuente
SRCS = main.cpp

# Lista de objetos generados a partir de los archivos fuente
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto para compilar el ejecutable
all: $(TARGET)

# Regla para enlazar los objetos y crear el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

# Regla para compilar los archivos fuente a objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Regla para limpiar los archivos generados y el ejecutable
.PHONY: all clean