#include <stdio.h>
#include <string.h>
#include <math.h>

struct panel {
    char nombre[100];
    char tipo_panel[50];
    char tecnologia[50];
    int potencia;
    float eficiencia;
    int precio;
};

extern int opcion1;
extern int opcion2;
extern int opcion3;
extern int panel_selec;
extern double consumo;
extern double cobertura;
extern double consumoAcubrir;
extern double prodPanel;
extern double prodPanelxDia;
extern double totalN;
extern int costoTotal;


void mostrarPaneles(struct panel paneles[], int n, int tipo);
int seleccionarPanel(struct panel paneles[]);
int calcularNpaneles(int consumo, int panel_selec, double cobertura, struct panel paneles[],int lugar);
double calcularCosto(struct panel paneles[], int panel_selec, double totalN);
void mostrarResumen(struct panel paneles[], int panel_selec, double totalN, double costo);
