# include "calculadora.h"


void mostrarPaneles(struct panel paneles[], int n, int tipo){

    if (tipo == 1){
        printf("\n------------------Monocristalinos------------------\n");
        for (int i = 0; i < n; i++){
            if(strcmp(paneles[i].tipo_panel, "monocristalino") == 0){
                printf("\nPanel solar %d watts %s %s\n", paneles[i].potencia, paneles[i].nombre, paneles[i].tecnologia);
                printf("___________________________________________________\n");
            }
        } 
    }
    if (tipo == 2){
        printf("\n------------------policristalinos------------------\n");
        for (int i = 0; i < n; i++){
            if(strcmp(paneles[i].tipo_panel, "policristalino") == 0){
                printf("\nPanel solar %d watts %s %s\n", paneles[i].potencia, paneles[i].nombre, paneles[i].tecnologia);
                printf("___________________________________________________\n");
            }
        }
    }
    if (tipo == 3){
        printf("----------------------------repertorio----------------------------");
        for (int i = 0; i < n; i++){
            printf("\n%d. Panel solar %d watts %s %s (%s)\n", i+1, paneles[i].potencia, paneles[i].nombre, paneles[i].tecnologia, paneles[i].tipo_panel);
            printf("_________________________________________________________________\n");
        }
    }
}

int seleccionarPanel(struct panel paneles[]){
    printf("Seleccione el panel que desea utilizar (1-10): ");
    scanf("%d", &panel_selec);
    if (panel_selec >= 1 && panel_selec <= 10){
        printf("Usted a escogido la opcion %d ", panel_selec);
    }
    else{
        printf("Eleccion no valida por favor usar una de las opciones disponibles");
    }

}


int calcularNpaneles(int consumo, int panel_selec, double cobertura, struct panel paneles[],int lugar){
    double horas_pico [14] = {4.554, 4.828, 4.346, 4.258, 3.570, 3.520, 3.676,3.672, 3.475, 3.076, 2.626,2.603, 2.107,1.563}; // horas pico de sol segun la región
    if(panel_selec >= 1 && panel_selec <= 10 ){
       
        cobertura = cobertura / 100.0;
        consumoAcubrir = consumo * cobertura;
        prodPanel = paneles[panel_selec - 1].potencia;
        prodPanelxDia = horas_pico[lugar - 1] * (paneles[panel_selec - 1].potencia / 1000.0);  
        totalN = (consumoAcubrir / 30.0) / (prodPanelxDia *1.25);
        totalN = ceil(totalN);
        printf("Se necesitan %.0f paneles\n", totalN);

       if (lugar < 1 || lugar > 14){
        printf("zona invalida por favor selecionar una de las zonas disponibles\n");
       }

    }
    else{
        printf("Seleccione un panel primero");
    }
}

int calcularCosto(struct panel paneles[], int n_panel, int cantidad) {
    costoTotal = paneles[n_panel - 1].precio * cantidad;

}
