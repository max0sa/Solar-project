#include <stdio.h>
#include <string.h>

struct panel {
    char nombre[100];
    char tipo_panel[50];
    char tecnologia[50];
    int potencia;
    float eficiencia;
    int precio;
};

// funciones necesarias por implementar

void mostrarPaneles(struct panel paneles[], int n, int tipo);
int seleccionarPanel();
int calcularNpaneles(int consumo, int panel_selec);
int calcularCosto(struct panel paneles[], int n_panel, int cantidad);
void mostrarREsumen(struct panel paneles[], int n_panel, int cantidad, int costo);

