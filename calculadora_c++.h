#ifndef CALCULADORAC++_H
#define CALCULADORAC++_H

#include <iostream>
#include <string>
#include <cmath>

class panel{
    private:
        std::string nombre;
        std::string tipo;
        std::string tecnologia;
        int potencia;
        float eficiencia;
        int precio;


    public:
        panel(std::string n, std::string t, std::string tec, int p, float e, int pr);
        std::string getNombre();
        std::string getTipo();
        std::string getTecnologia();
        int getPotencia();
        float getEficiencia();
        int getPrecio();
};

class bateria{
    private:
        std::string nombre;
        int capacidad;
        int precio;
    public:
        bateria(std::string n, int c, int pr);
        std::string getNombre();
        int getCapacidad();
        int getPrecio();
};

class inversor{
    private:
        std::string nombre;
        int maxpotencia;
        int precio;
        int imax;
        int mppt;
    public: 
        inversor(std::string n, int m, int pr, int i, int mppt);
        std::string getNombre();
        int getMaxpoteencia();
        int getPrecio();
        int getImax();
        int getMppt();
};

void mostrarPaneles(panel paneles[], int n, int opcionTipo);

void mostrarBaterias(bateria baterias[], int n);

void mostrarInversore(inversor inversores[], int n);

int seleccionarPanel(panel paneles[]);

int seleccionarBateria(bateria baterias[]);

int seleccionarInversores(inversor inversores[]);

int calcularNpaneles(panel paneles[], int consumo,double cobertura, int panel_selc, int lugar);

int calcularBaterias(bateria baterias[],int consumo,double cobertura, int capacidadBateria, int bateria_selc);

int calcularInversores(inversor ibversores[], int potensiaSis, int potenciaInversor, int inversor_select);

double calcularCosto(panel paneles[], bateria baterias[], inversor inversores[], int panel_selec, 
    int bateria_select, int inversor_selec, int total_paneles, int total_baterias, int total_inversores);

void mostrarResumen(panel paneles[], bateria baterias[], inversor inversores[], int panel_selec, 
    int bateria_select, int inversor_selec, int total_paneles, int total_baterias, int total_inversores,
    double costoTotal);
    
#endif