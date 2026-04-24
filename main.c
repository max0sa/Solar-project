#include "calculadora.h"

int opcion1;
int opcion2;
int panel_selec;
double consumo;
double cobertura;
double consumoAcubrir;
double prodPanel;
double prodPanelxDia;
double totalN;

int main(){

    struct panel paneles[10] ={
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

 
//lo siguiente corresponde a el mennu de la calculadora //
    printf("Bienvenido a Solar Proyect");

    do{   /* abro un ciclo para poder utilizarlo en el menu principal cada vez que se inicie
         el programa o salga de un "submenu" aparecera */
        printf("\n___________MENU___________\n");
        printf("1.Tipos de paneles solares\n");            // le doy al usuario alternativas enumeradas
        printf("2.ingresar consumo electrico\n");          // para poder que pueda navegar
        printf("3.calcular cantidad de paneles\n");
        printf("4.estimar costo\n");
        printf("5.ver resumen\n");
        printf("0.SALIR\n"); // use un ciclo con la condicion (opcion1 != 0) por lo que al escoger 0 deja de iterar
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion1);

        switch (opcion1) { // empiezo a utilizar casos que depende de la alternativa numerada antes
            case 1: // por ejemplo: si se escoge 1 hara lo siguiente o como un if (opcion1 == 1)
            do{  // abro un submenu que funciona igual que el menu principal
                printf("\n----------categorias----------\n");
                printf("1.Monocristalinos  *solo vista*\n");
                printf("2.Policristalinos  *solo vista*\n");
                printf("3.Elegir tipo de panel\n");
                printf("0.Volver al menu principal\n"); // misma condicion que el menu principal deja de iterar al usar 0
                printf("Seleccione un opcion: ");
                scanf("%d", &opcion2);

                switch (opcion2) { // otro submenu 
                    case 1: // por ejemplo: si se escoge 1 hara lo siguiente o como un if (opcion1 == 1)
                    mostrarPaneles(paneles, 10, opcion2);
                    break;

                    case 2: // por ejemplo: si se escoge 2 hara lo siguiente o como un if (opcion1 == 2)
                    mostrarPaneles(paneles, 10, opcion2);
                    break;
                    case 3:
                    mostrarPaneles(paneles, 10, opcion2);
                    printf("Seleccione un panel del repertorio: ");
                    scanf("%d", &panel_selec);
                    break;

                    case 0:
                    printf(".....Hasta pronto.....\n"); 
                    break;
                    
                    default:
                    printf("No existe esa opcion\n");

                }

            }while(opcion2 != 0);

            break;

            case 2: // ingresar consumo eléctrico
            
            printf("Ingrese su consumo mensual (kW): ");
            scanf("%lf", &consumo);
            printf("Ingrese que porcentaje de su consumo desea cubrir: ");
            scanf("%lf", &cobertura);
            
            break;

            case 3://calcular numero de paneles
            totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles);
            break;

            case 4:
                printf("hola \n");
                double costo = calcularCosto(paneles, panel_selec, totalN);
                break;

            case 0:
                printf(".....Hasta pronto.....\n");
                break;

            default:
                printf("No existe esa opcion\n");
        }
    } while (opcion1 != 0);

    return 0;}