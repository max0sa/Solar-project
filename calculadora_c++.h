#ifndef CALCULADORACPP_H
#define CALCULADORACPP_H

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
        std::string material;
        int capacidad;
        int precio;
    public:
        bateria(std::string n, std::string m, int c, int pr);
        std::string getNombre();
        std::string getmaterial();
        int getCapacidad();
        int getPrecio();
};

class inversor{
    private:
        std::string nombre;
        int maxPotencia;
        int precio;
        int imax;
        int mppt;
    public: 
        inversor(std::string n, int m, int pr, int i, int mppt);
        std::string getNombre();
        int getMaxPotencia();
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

int calcularBaterias(bateria baterias[],int consumo,double cobertura,int bateria_selc);

int calcularInversores(panel paneles[], int consumo, int lugar, double cobertura, int panel_selc, int inversorSelec, inversor inversores[]);

int calcularCosto(panel paneles[], bateria baterias[], inversor inversores[], int panel_selec, 
    int bateria_select, int inversor_selec, int total_paneles, int total_baterias, int total_inversores);

void mostrarResumen(panel paneles[], bateria baterias[], inversor inversores[], int panel_selec, 
    int bateria_select, int inversor_selec, int total_paneles, int total_baterias, int total_inversores,int costoTotal);

void mostrarCantidades(panel paneles[], bateria baterias[], inversor inversores[], int panel_selec, int bateria_select, 
    int inversor_selec, int total_paneles, int total_baterias, int total_inversores);
    
int potenciaTotalSistema(int consumo, int lugar);
#endif
