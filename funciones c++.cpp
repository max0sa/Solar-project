#include "calculadora_c++.h"

panel::panel(std::string n, std::string t, std::string tec, int p, float e, int pr){
    nombre = n;
    tipo = t;
    tecnologia = tec;
    potencia = p;
    eficiencia = e;
    precio = pr;
}

std::string panel::getNombre(){
    return nombre;
}
std::string panel::getTipo(){
    return tipo;
}
std::string panel::getTecnologia(){
    return tecnologia;
}
int panel::getPotencia(){
    return potencia;
}
float panel::getEficiencia(){
    return eficiencia;
}
int panel::getPrecio(){
    return precio;
}

bateria::bateria(std::string n, int c, int pr){
    nombre = n;
    capacidad= c;
    precio = pr;
}

std::string bateria::getNombre(){
    return nombre;
}
int bateria::getCapacidad(){
    return capacidad;
}
int bateria::getPrecio(){
    return precio;
}

inversor::inversor(std::string n, int m, int pr){
    nombre = n;
    maxpotencia = m;
    precio = pr;
}

std::string inversor::getNombre(){
    return nombre;
}
int inversor::getMaxpoteencia(){
    return maxpotencia;
}
int inversor::getPrecio(){
    return precio;
}

void mostrarPaneles(panel paneles[], int n, int opcionTipo){
    if(opcionTipo == 1){
        std::cout<<"\n------------------Monocristalinos------------------\n";
        for (int i = 0; i < n; i++){
            if(paneles[i].getTipo() == "monocristalino"){
                std::cout<<"panel solar "<<paneles[i].getPotencia()<<" watts "<<paneles[i].getNombre()<<" "<<paneles[i].getTecnologia()<<std::endl;
                std::cout<<"___________________________________________________"<<std::endl;
            }
        }
    }
    else if(opcionTipo == 2){
        std::cout<<"\n------------------Policristalinos------------------\n";
        for (int i = 0; i < n; i++){
            if(paneles[i].getTipo() == "policristalinos"){
                std::cout<<"panel solar "<<paneles[i].getPotencia()<<" watts "<<paneles[i].getNombre()<<" "<<paneles[i].getTecnologia()<<std::endl;
                std::cout<<"___________________________________________________"<<std::endl;
            }
        }
    }
    else if(opcionTipo == 3){
        std::cout<<"\n----------------------------repertorio----------------------------\n";
        for (int i = 0; i < n; i++){
            std::cout<<i+1<<"- panel solar "<<paneles[i].getPotencia()<<" watts "<<paneles[i].getNombre()<<" "<<paneles[i].getTecnologia()<<std::endl;
            std::cout<<"_________________________________________________________________"<<std::endl;
        }
    }
}

void mostrarBaterias(bateria baterias[], int n){
    std::cout<<"\n----------------baterias----------------\n";
    for (int i = 0; i < n; i++){
        std::cout<<"bateria "<<baterias[i].getNombre()<<" de "<<baterias[i].getCapacidad()<<" watts  $"<<baterias[i].getPrecio()<<std::endl;
        std::cout<<"___________________________________________"<<std::endl;
    }
}

void mostrarInversore(inversor inversores[], int n){
    std::cout<<"\n----------------inversores----------------\n";
    for (int i = 0; i < n; i++){
        std::cout<<"bateria "<<inversores[i].getNombre()<<" de "<<inversores[i].getMaxpoteencia()<<" watts  $"<<inversores[i].getPrecio()<<std::endl;
        std::cout<<"_______________________________________________"<<std::endl;
    }
}

int seleccionarPanel(panel paneles[]){
    int seleccion;
    std::cout<<"seleccione un panel(1-10)"<<std::endl;
    std::cin>>seleccion;
    if(seleccion<=10 && seleccion >=1){
        std::cout<<"seleccion registrada"<<std::endl;
        return seleccion;
    }
    else{
        std::cout<<"Error: Seleccione una opcion valida"<<std::endl;
        return -1;
    }
}

int seleccionarBateria(bateria baterias[]){
    int seleccion;
    std::cout<<"seleccione una bateria(1 o 2)"<<std::endl;
    std::cin>>seleccion;
    if(seleccion<=2 && seleccion >=1){
        std::cout<<"seleccion registrada"<<std::endl;
        return seleccion;
    }
    else{
        std::cout<<"Error: Seleccione una opcion valida"<<std::endl;
        return -1;
    }
}

int seleccionarInversores(inversor inversores[]){
    int seleccion;
    std::cout<<"seleccione un inversor(1 o 2)"<<std::endl;
    std::cin>>seleccion;
    if(seleccion<=2 && seleccion >=1){
        std::cout<<"seleccion registrada"<<std::endl;
        return seleccion;
    }
    else{
        std::cout<<"Error: Seleccione una opcion valida"<<std::endl;
        return -1;
    }
}

int calcularNpaneles(panel paneles[], int consumo,double cobertura, int panel_selc, int lugar){
    double horas_pico[14] = {4.554, 4.828, 4.346, 4.258, 3.570, 3.520, 3.676,3.672, 3.475, 3.076, 2.626,2.603, 2.107,1.563}; // horas pico de sol segun la región
    if(panel_selc <= 1 && panel_selc >= 10 ){
        std::cout<<"Seleccione un panel primero \n";
        return -1;
    }
    if(lugar < 1 || lugar > 14){
        std::cout<< "zona invalida por favor selecionar una de las zonas disponibles\n";
        return -1;
    }
    cobertura = cobertura/100.0;
    double consumoAcubrir = consumo * cobertura; // consumo energetico que se tiene que cubrir
    double PPD = horas_pico[lugar - 1] * (paneles[panel_selc -1].getPotencia()  /1000.0); //Potencia del panel por dia en promedio
    double PN = (consumoAcubrir/30.0) / (PPD*1.25); //Paneles necesarios
    std::cout << "se necesitan " << PN << "  paneles \n";
    return PN;
}