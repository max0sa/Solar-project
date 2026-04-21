#include <stdio.h>
#include <string.h>

struct panel {
    char nombre[50];
    int potencia;
    int consumo;
    int precio;

};

// funciones necesarias por implementar

void mostrarPanel(struct panel tipos[], int n);
