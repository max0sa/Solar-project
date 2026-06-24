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

bateria::bateria(std::string n, std::string m, int c, int pr){
    nombre = n;
    material = m;
    capacidad= c;
    precio = pr;
}

std::string bateria::getNombre(){
    return nombre;
}
std::string bateria::getmaterial(){
    return material;
}
int bateria::getCapacidad(){
    return capacidad;
}
int bateria::getPrecio(){
    return precio;
}

inversor::inversor(std::string n, int m, int pr, int i, int mp){
    nombre = n;
    maxPotencia = m;
    precio = pr;
    imax = i;
    mppt = mp;
}

std::string inversor::getNombre(){
    return nombre;
}
int inversor::getMaxPotencia(){
    return maxPotencia;
}
int inversor::getPrecio(){
    return precio;
}
int inversor::getImax(){
    return imax;
}
int inversor::getMppt(){
    return mppt;
}

void mostrarPaneles(panel paneles[], int n, int opcionTipo){
    if(opcionTipo == 1){
        std::cout<<"\n------------------Monocristalinos------------------\n";
        for (int i = 0; i < n; i++){
            if(paneles[i].getTipo() == "monocristalino"){
                std::cout<<"\nPanel solar "<<paneles[i].getPotencia()<<" watts "<<paneles[i].getNombre()<<" "<<paneles[i].getTecnologia()<<std::endl;
                std::cout<<"___________________________________________________"<<std::endl;
            }
        }
    }
    else if(opcionTipo == 2){
        std::cout<<"\n------------------Policristalinos------------------\n";
        for (int i = 0; i < n; i++){
            if(paneles[i].getTipo() == "policristalino"){
                std::cout<<"\nPanel solar "<<paneles[i].getPotencia()<<" watts "<<paneles[i].getNombre()<<" "<<paneles[i].getTecnologia()<<std::endl;
                std::cout<<"___________________________________________________"<<std::endl;
            }
        }
    }
    else if(opcionTipo == 3){
        std::cout<<"\n----------------------------repertorio----------------------------\n";
        for (int i = 0; i < n; i++){
            std::cout<<i+1<<"- Panel solar "<<paneles[i].getPotencia()<<" watts "<<paneles[i].getNombre()<<" "<<paneles[i].getTecnologia()<<std::endl;
            std::cout<<"_________________________________________________________________"<<std::endl;
        }
    }
}

void mostrarBaterias(bateria baterias[], int n){
    std::cout<<"\n----------------baterias----------------\n";
    for (int i = 0; i < n; i++){
        std::cout<<"\nBateria "<<baterias[i].getNombre()<<" de "<<baterias[i].getCapacidad()<<" watts"<<std::endl;
        std::cout<<"___________________________________________"<<std::endl;
    }
}

void mostrarInversore(inversor inversores[], int n){
    std::cout<<"\n----------------inversores----------------\n";
    for (int i = 0; i < n; i++){
        std::cout<<"\nInversor "<<inversores[i].getNombre()<<" de "<<inversores[i].getMaxPotencia()<<" watts"<<std::endl;
        std::cout<<"_______________________________________________"<<std::endl;
    }
}

int seleccionarPanel(panel paneles[]){
    int seleccion;
    std::cout<<"Seleccione un panel(1-10)"<<std::endl;
    std::cin>>seleccion;
    if(seleccion<=10 && seleccion >=1){
        std::cout<<"Seleccion registrada"<<std::endl;
        return seleccion;
    }
    else{
        std::cout<<"ERROR: Seleccione una opcion valida"<<std::endl;
        return -1;
    }
}

int seleccionarBateria(bateria baterias[]){
    int seleccion;
    std::cout<<"Seleccione una bateria(1 o 2)"<<std::endl;
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
    std::cout<<"Seleccione un inversor(1 o 2)"<<std::endl;
    std::cin>>seleccion;
    if(seleccion<=2 && seleccion >=1){
        std::cout<<"Seleccion registrada"<<std::endl;
        return seleccion;
    }
    else{
        std::cout<<"ERROR: Seleccione una opcion valida"<<std::endl;
        return -1;
    }
}

int calcularNpaneles(panel paneles[], int consumo,double cobertura, int panel_selc, int lugar){
    double horas_pico[14] = {4.554, 4.828, 4.346, 4.258, 3.570, 3.520, 3.676,3.672, 3.475, 3.076, 2.626,2.603, 2.107,1.563}; // horas pico de sol segun la región
    if(panel_selc < 1 || panel_selc > 10 ){
        std::cout<<"ERROR: Seleccione un panel primero \n";
        return -1;
    }
    if(lugar < 1 || lugar > 14){
        std::cout<< "ERROR: Zona invalida por favor selecionar una de las zonas disponibles\n";
        return -1;
    }
    cobertura = cobertura/100.0;
    double consumoAcubrir = consumo * cobertura; // consumo energetico que se tiene que cubrir
    double PPD = horas_pico[lugar - 1] * (paneles[panel_selc -1].getPotencia()  /1000.0); //Potencia del panel por dia en promedio
    double PN = std::ceil(((consumoAcubrir/30.0)*1.25) / PPD); //Paneles necesarios
    return PN;
}

int calcularBaterias(bateria baterias[],int consumo, double cobertura, int bateria_selc){
    double coberturaXcubrir;
    int Nbaterias;
    if(bateria_selc <= -1){
        std::cout<<"ERROR: Primero debes seleccionar una bateria"<<std::endl;
        return -1;
    }
    cobertura = cobertura/100.0;
    coberturaXcubrir = (consumo * cobertura)/30.0; // divido en 30 ya que los calculos que vi eran en dias y el consumo que se entrega es al mes y 30 es el promedio
    if(baterias[bateria_selc - 1].getmaterial() == "gel"){
        Nbaterias = std::ceil((coberturaXcubrir * 1000.0 * 1.25)/(baterias[bateria_selc - 1].getCapacidad() * 0.60)); // el 1.25 es por posibles perdidas de energia del sistema ya que en la formula se ve como "factor de correccion"
                                                                                                // y el 0.60 es por la profundidad de descarga en gel es de entre 50% y 70%
    }
    else if(baterias[bateria_selc - 1].getmaterial() == "litio"){
        Nbaterias = std::ceil((coberturaXcubrir * 1000.0 * 1.25)/(baterias[bateria_selc - 1].getCapacidad() * 0.75));//el 0.75 es por la profundidad de descarga que en el litio es de entre 70% y 80%
    }
    return Nbaterias;
}

int potenciaTotalSistema(int consumo, int lugar){    
    double horas_pico[14] = {4.554, 4.828, 4.346, 4.258, 3.570, 3.520, 3.676,3.672, 3.475, 3.076, 2.626,2.603, 2.107,1.563};   
    double factorRendimiento = 0.77;
    double potencia = (consumo / 30.0) / (factorRendimiento * horas_pico[lugar - 1]);
    return potencia;
}


int calcularInversores(panel paneles[], int consumo, int lugar, double cobertura, int panel_selc, int inversorSelec, inversor inversores[]){ 
    double potenciaTeorica = potenciaTotalSistema(consumo, lugar); 
    double nPaneles = calcularNpaneles(paneles, consumo, cobertura, panel_selc, lugar);     
    if (nPaneles <= 0) {
        return 0;
    }
    double pRealKW = nPaneles * (paneles[panel_selc - 1].getPotencia() / 1000.0);
    double potInversorKW = inversores[inversorSelec - 1].getMaxPotencia() / 1000.0;
    int nInversoresPorPotencia = std::ceil(pRealKW / potInversorKW); //Determina cuántos inversores se necesitan para soportar la potencia total de los paneles
    double vMaxInversor = 450.0; //Los inversores seleccionados toleran un máximo de 450V DC de entrada.
    double maxPanelesSerie = vMaxInversor / 35.0; //calculado con el voltaje máximo que el panel puede generar
    int stringsTotales = std::ceil(nPaneles / maxPanelesSerie); //cantidad de hileras de paneles del proyecto
    double maxStringParalelo = (double)inversores[inversorSelec - 1].getImax() / 15.0; //limite de cadenas en paralelo por cada entrada MPPT
    int capacidadInvStrings = std::ceil(maxStringParalelo) * inversores[inversorSelec - 1].getMppt(); //capacidad de strings que puede recibir solo un inversor
    int nInversoresPorStrings = std::ceil((double)stringsTotales / capacidadInvStrings); //inversores por string
    int nInversores = std::max(nInversoresPorPotencia, nInversoresPorStrings); //total de inversores
    return nInversores;
}

int calcularCosto(panel paneles[], bateria baterias[], inversor inversores[], int panel_selec, int bateria_select, int inversor_selec, int total_paneles, int total_baterias, int total_inversores){
    int costoPaneles;
    int costoBaterias;
    int costoInversores;
    int costoTotal;
    if(panel_selec <= -1){
        std::cout<<"ERROR: Primero debes seleccionar un panel"<<std::endl;
        return -1;
    }
    if(bateria_select <= -1){
        std::cout<<"ERROR: Primero debes seleccionar una bateria"<<std::endl;
        return -1;
    }
    if(inversor_selec <= -1){
        std::cout<<"ERROR: Primero debes seleccionar un inversor"<<std::endl;
        return -1;
    }
    if(total_paneles == 0){
        std::cout<<"ERROR: Primero debes calcular el numero de paneles y haber seleccionado un panel"<<std::endl;
    }
    if(total_baterias == 0){
        std::cout<<"ERROR: primero debes haber seleccionado una bateria"<<std::endl;
    }
    if(total_inversores == 0){
        std::cout<<"ERROR: Primero debes haber seleccionado Inversores"<<std::endl;
    }
    costoPaneles = total_paneles * paneles[panel_selec - 1].getPrecio();
    costoBaterias = total_baterias * baterias[bateria_select -1].getPrecio();
    costoInversores = total_inversores * inversores[inversor_selec - 1].getPrecio();
    costoTotal =  costoPaneles + costoBaterias + costoInversores;
    return costoTotal;
}

void mostrarCantidades(panel paneles[], bateria baterias[], inversor inversores[], int panel_selec, int bateria_select, int inversor_selec, int total_paneles, int total_baterias, int total_inversores){
    if(panel_selec <= -1){
        std::cout<<"ERROR: Primero debes seleccionar un panel"<<std::endl;
        return;
    }
    if(bateria_select <= -1){
        std::cout<<"ERROR: Primero debes seleccionar una bateria"<<std::endl;
        return;
    }
    if(inversor_selec <= -1){
        std::cout<<"ERROR: Primero debes seleccionar un inversor"<<std::endl;
        return;
    }
    if(total_paneles == 0){
        std::cout<<"ERROR: Primero debes calcular el numero de paneles y haber selecionado un pnael"<<std::endl;
        return;
    }
    if(total_baterias == 0){
        std::cout<<"ERROR: Primero debes calcular el numero de Baterias"<<std::endl;
        return;
    }
    if(total_inversores == 0){
        std::cout<<"ERROR: Primero debes calcular el numero de Inversores"<<std::endl;
        return;
    }
    std::cout<<"------------------------CANTIDADES------------------------"<<std::endl;
    std::cout<<"__________________________________________________________"<<std::endl;
    std::cout<<"--Panel solar de "<<paneles[panel_selec -1].getPotencia()<<" watts "<<paneles[panel_selec -1].getNombre()<<" "<<paneles[panel_selec -1].getTecnologia()<<": "<<total_paneles <<std::endl;
    std::cout<<"--Bateria de "<<baterias[bateria_select -1].getmaterial()<<" "<<baterias[bateria_select -1].getCapacidad()<<" watts "<<baterias[bateria_select -1].getNombre()<<": "<<total_baterias<<std::endl;
    std::cout<<"--Inversor de "<<inversores[inversor_selec-1].getMaxPotencia()<<" watts "<<inversores[inversor_selec -1].getNombre()<<": "<<total_inversores<<std::endl; 
    std::cout<<"__________________________________________________________"<<std::endl;
}

void mostrarResumen(panel paneles[], bateria baterias[], inversor inversores[], int panel_selec, int bateria_select, int inversor_selec, int total_paneles, int total_baterias, int total_inversores,int costoTotal){
    if(panel_selec <= -1){
        std::cout<<"ERROR: Primero debes seleccionar un panel"<<std::endl;
        return;
    }
    if(bateria_select <= -1){
        std::cout<<"ERROR: Primero debes seleccionar una bateria"<<std::endl;
        return;
    }
    if(inversor_selec <= -1){
        std::cout<<"ERROR: Primero debes seleccionar un inversor"<<std::endl;
        return;
    }
    if(costoTotal > 0){
        std::cout<<"\n===============================================\n";
        std::cout<<("              PRESUPUESTO \n");
        std::cout<<"================================================\n";
        std::cout<<"-Paneles:"<<std::endl;
        std::cout<<"Panel solar de "<<paneles[panel_selec -1].getPotencia()<<" watts "<<paneles[panel_selec -1].getNombre()<<" "<<paneles[panel_selec -1].getTecnologia()<<": "<<total_paneles <<std::endl;
        std::cout<<"-baterias:\n";
        std::cout<<"Bateria de "<<baterias[bateria_select -1].getmaterial()<<" "<<baterias[bateria_select -1].getCapacidad()<<" watts "<<baterias[bateria_select -1].getNombre()<<": "<<total_baterias<<std::endl;
        std::cout<<"-Inversores \n";
        std::cout<<"Inversor de "<<inversores[inversor_selec-1].getMaxPotencia()<<" watts "<<inversores[inversor_selec -1].getNombre()<<": "<<total_inversores<<std::endl;
        std::cout<<"================================================\n";
        std::cout<<"El costo estimado es de: $"<<costoTotal<<"CLP"<<std::endl;
        std::cout<<"================================================\n";
    }
    else{
        std::cout<<"\n===============================================\n";
        std::cout<<("              PRESUPUESTO \n");
        std::cout<<"================================================\n";
        std::cout<<"-Paneles:"<<std::endl;
        std::cout<<"Panel solar de "<<paneles[panel_selec -1].getPotencia()<<" watts "<<paneles[panel_selec -1].getNombre()<<" "<<paneles[panel_selec -1].getTecnologia()<<": "<<total_paneles <<std::endl;
        std::cout<<"-baterias:\n";
        std::cout<<"Bateria de "<<baterias[bateria_select -1].getmaterial()<<" "<<baterias[bateria_select -1].getCapacidad()<<" watts "<<baterias[bateria_select -1].getNombre()<<": "<<total_baterias<<std::endl;
        std::cout<<"-Inversores \n";
        std::cout<<"Inversor de "<<inversores[inversor_selec-1].getMaxPotencia()<<" watts "<<inversores[inversor_selec -1].getNombre()<<": "<<total_inversores<<std::endl;
        std::cout<<"================================================\n";
        std::cout<<"El costo estimado no ha sido calculado todavia"<<std::endl;
        std::cout<<"================================================\n";
    }
}
