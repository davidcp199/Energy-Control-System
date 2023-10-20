# Nombre del ejecutable
TARGET = executable

# Compilador y opciones de compilación
CC = g++
CFLAGS = -std=c++11 -Wall

# Carpetas
SRCDIR = src
INCDIR = include
BUILDDIR = bin
LIBDIR = lib

# Listas de archivos
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
HEADERS := $(wildcard $(INCDIR)/*.hpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Flags de búsqueda de directorios de inclusión
INCFLAGS = -I$(INCDIR)

# Librerías
LDFLAGS =

# Regla de construcción del objetivo
$(BUILDDIR)/$(TARGET): $(OBJECTS) $(BUILDDIR)/main.o
	$(CC) $(CFLAGS) $(INCFLAGS) -o $@ $^ $(LDFLAGS)

# Regla de compilación de archivos fuente
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(INCFLAGS) -c -o $@ $<

# Regla para compilar main.cpp
$(BUILDDIR)/main.o: main.cpp
	$(CC) $(CFLAGS) $(INCFLAGS) -c -o $@ $<

# Regla para limpiar archivos generados
clean:
	rm -rf $(BUILDDIR)/*

# El objetivo "all" compila el programa
all: $(BUILDDIR)/$(TARGET)
# El objetivo por defecto es "all"
.DEFAULT_GOAL := all

# Evitar conflictos con archivos llamados "clean" u otros
.PHONY: clean

run: $(BUILDDIR)/$(TARGET)
	time ./$(BUILDDIR)/$(TARGET)
