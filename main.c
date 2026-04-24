#include "calculadora.h"

int opcion1;
int opcion2;
int opcion3;
int panel_selec;
double consumo;
double cobertura;
double consumoAcubrir;
double prodPanel;
double prodPanelxDia;
double totalN;
int costoTotal;

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
        printf("2.Ingresar consumo electrico\n");          // para poder que pueda navegar
        printf("3.Calcular cantidad de paneles\n");
        printf("4.Estimar costo\n");
        printf("5.Ver resumen\n");
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
                    seleccionarPanel(paneles);
                    break;

                    case 0:
                    printf("\n-Volviendo al menu principal-\n"); /* al terminar el ciclo al estar dentro del ciclo 
                                                      del menu principal volvera a iterarse el menu principal */
                    break;
                    
                    default:
                    printf("\n**No existe esa opcion**\n");

                }

            }while(opcion2 != 0);

            break;

            case 2: // ingresar consumo eléctrico
            
            do{
                printf("\nIngrese su consumo mensual (kW): ");
                scanf("%lf", &consumo);
                if (consumo <= 0){
                    printf("\n**no se pueden ingresar consumos negativos o nulos**\n");
                }
            } while (consumo <= 0);

            do{
                printf("\nIngrese que porcentaje de su consumo desea cubrir: ");
                scanf("%lf", &cobertura);
                if (cobertura < 10 || cobertura > 100){
                    printf("\n**la cobertura debe ser entre 10-100**\n");
                }
            } while (cobertura < 10 || cobertura > 100);
            break;

            case 3://calcular numero de paneles
            do{
                printf("\nPara calcular la cantidad de paneles necesitamos saber en que zona de chile se decean usar\n");
                printf("1.I región\n");
                printf("2.II región\n");
                printf("3.III región\n");
                printf("4.IV región\n");
                printf("5.RM región\n");
                printf("6.V región\n");
                printf("7.VI región\n");
                printf("8.VII región\n");
                printf("9.VIII región\n");
                printf("10.IX región\n");
                printf("11.X región\n");
                printf("12.XI región\n");
                printf("13.XII región\n");
                printf("14.Antártica región\n");
                printf("0.Volver al menu principal\n");
                printf("Seleccione un opcion: ");
                scanf("%d", &opcion3);

                switch (opcion3){
                    case 1:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 2:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 3:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 4:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 5:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 6:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 7:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 8:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 9:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 10:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 11:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 12:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 13:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 14:
                    totalN = calcularNpaneles(consumo, panel_selec, cobertura, paneles, opcion3);
                    break;
                    case 0:
                    printf("-Volviendo al menu principal-\n");
                    break;
                    default:
                    printf("\n**No existe esa opcion**\n");

                }

            } while (opcion3 != 0);
            
            break;

            case 4:
            costoTotal = calcularCosto(paneles, panel_selec, totalN);
            break;

            case 5:
            mostrarResumen(paneles, panel_selec, totalN, costoTotal);
            break;
            
            case 0:
                printf("\n.....Hasta pronto.....\n");
                break;

            default:
                printf("**No existe esa opcion**\n");
        }
    } while (opcion1 != 0);

    return 0;
}