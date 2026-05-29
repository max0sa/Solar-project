#include "calculadora_c++.h"

int main(){
    int opcion1;
    int opcion2;
    int opcion3;
    int panelSelec = -1;
    int bateriaSelec = -1;
    int inversorSelec = -1;
    int consumo;
    int cobertura;
    int totalPaneles = 0;
    int totalBaterias = 0;
    int totalInversores = 0;
    int valorTotal = 0;
    int lugarSelec = -1;

    panel paneles[10] ={
        {"Restarsolar", "monocristalino", "celda grado A", 250, 23.5, 127415},
        {"Canadian Solar", "monocristalino", "mono perc", 410, 21, 114750},
        {"DAH Solar", "monocristalino", "mono perc", 450, 20.7, 187200},
        {"JA Solar", "monocristalino", "half-cell", 550, 21.3, 142000},
        {"Canadian Solar", "monocristalino", "N-type topcon", 595, 23, 111250},
        {"Resun", "policristalino", "standard poly", 150, 15.2,6900},
        {"Resun", "policristalino", "standard poly", 200, 15.5, 113400},
        {"Sine Energy", "policristalino", "standard poly", 285, 15.8, 105900},
        {"Jinko Solar", "policristalino", "standard poly", 305, 16, 75000},
        {"Sine Energy", "policristalino", "standard poly",340, 16.2, 128990},
    };

    bateria baterias[2]={
        bateria("Deep Cycle", "gel",1200, 115000),
        bateria("Pylontech","litio",2400, 480000),
    };

    inversor inversores[2]={
        inversor("Voltronic 3kW", 3000, 320000,27,1),
        inversor("Growatt 5kW", 5000, 580000,13,2),
    };

    std::cout<<"Bienvenido a Solar Proyect\n";
    
    do{
        std::cout<<"\n___________MENU___________\n";
        std::cout<<"1.Tipos de paneles solares\n";
        std::cout<<"2.Ingresar consumo electrico\n";
        std::cout<<"3.Seleccionar bateria\n";
        std::cout<<"4.Seleccionar inversor\n";
        std::cout<<"5.Calcular cantidad de paneles\n";
        std::cout<<"6.Mostrar cantidades\n";
        std::cout<<"7.Calcular costo\n";
        std::cout<<"8.Mostrar resumen\n";
        std::cout<<"0.SALIR\n";
        std::cout<<"Seleccione una opcion: ";
        std::cin>>opcion1;

        switch(opcion1){
            case 1: //Tipos de paneles solares
            do{
                std::cout<<"\n----------categorias----------\n";
                std::cout<<"1.Monocristalinos  *solo vista*\n";
                std::cout<<"2.Policristalinos  *solo vista*\n";
                std::cout<<"3.Elegir tipo de panel\n";
                std::cout<<"0.Volver al menu principal\n";
                std::cout<<"Seleccione un opcion: ";
                std::cin>> opcion2;

                switch(opcion2){
                    case 1:
                    mostrarPaneles(paneles, 10, 1);
                    break;

                    case 2:
                    mostrarPaneles(paneles,10,2);
                    break;

                    case 3:
                    mostrarPaneles(paneles,10,3);
                    panelSelec = seleccionarPanel(paneles);
                    break;

                    case 0:
                    std::cout << "\n-Volviendo al menu principal-\n";
                    break;

                    default:
                    std::cout<< "\n**No existe esa opcion**\n";

                }
            }while(opcion2 != 0);
            break;
        
            case 2: //Ingresar consumo eléctrico

            do{
                std::cout<<"\nIngrese su consumo mensual (kW): ";
                std::cin >> consumo;
                if (consumo <= 0){
                    std::cout <<"\n**no se pueden ingresar consumos negativos o nulos**\n";
                }
            }while (consumo <= 0);

            do{
                std::cout << "\nIngrese que porcentaje de su consumo desea cubrir: ";
                std::cin >> cobertura;
                if (cobertura < 10 || cobertura > 100){
                    std::cout<<"\n**la cobertura debe ser entre 10-100**\n";
                }

            }while(cobertura < 10 || cobertura > 100);
            break;

            case 3: //seleccionar bateria
            mostrarBaterias(baterias,2);
            bateriaSelec = seleccionarBateria(baterias);
            break;

            case 4: //Seleccionar inversor
            mostrarInversore(inversores,2);
            inversorSelec = seleccionarInversores(inversores);
            break;

            case 5: //calcular cantidad de paneles
            do{
                std::cout<<"\nPara calcular la cantidad de paneles necesitamos saber en que zona de chile se decean usar\n";
                std::cout<<"1.I región\n";
                std::cout<<"2.II región\n";
                std::cout<<"3.III región\n";
                std::cout<<"4.IV región\n";
                std::cout<<"5.RM región\n";
                std::cout<<"6.V región\n";
                std::cout<<"7.VI región\n";
                std::cout<<"8.VII región\n";
                std::cout<<"9.VIII región\n";
                std::cout<<"10.IX región\n";
                std::cout<<"11.X región\n";
                std::cout<<"12.XI región\n";
                std::cout<<"13.XII región\n";
                std::cout<<"14.Antártica región\n";
                std::cout<<"0.Volver al menu principal\n";
                std::cout<<"Seleccione un opcion: ";
                std::cin >> opcion3;

                if(opcion3 >= 1 && opcion3 <= 14){
                    totalPaneles = calcularNpaneles(paneles, consumo,cobertura,panelSelec, opcion3);
                    lugarSelec = opcion3;
                    break;
                }

                }while(opcion3 != 0);
                break;

            case 6:  //Mostrar cantidades
            totalBaterias = calcularBaterias(baterias, consumo, cobertura,bateriaSelec);
            totalInversores = calcularInversores(paneles, consumo, lugarSelec, cobertura, panelSelec, inversorSelec, inversores);
            mostrarCantidades(paneles, baterias, inversores, panelSelec, bateriaSelec, inversorSelec, totalPaneles, totalBaterias, totalInversores);
            break;

            case 7:  //Calcular costo
            valorTotal = calcularCosto(paneles, baterias, inversores,panelSelec, bateriaSelec, inversorSelec, totalPaneles, totalBaterias, totalInversores);
            std::cout << "El costo total es: "<<valorTotal<<" $CLP\n";
            break;

            case 8: //mostrar resumen
            mostrarResumen(paneles, baterias, inversores, panelSelec, bateriaSelec, inversorSelec, totalPaneles, totalBaterias, totalInversores,valorTotal);
            break;
            
            case 0:
            std::cout << "\n.....Hasta pronto.....\n";
            break;

            default:
            std::cout << "**No existe esa opcion**\n";
        }
    }while(opcion1 != 0);


    return 0;
}