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

int seleccionarPanel(){
    printf("Seleccione el panel que desea utilizar (1-10): ");
    scanf("%d", &panel_selec);
    return panel_selec;
}


int calcularNpaneles(int consumo, int panel_selec, int cobertura, struct panel paneles[]){
    if(panel_selec >= 1 && panel_selec <= 10 ){
       cobertura = cobertura /100.0;
        consumoAcubrir = consumo * cobertura;
        prodPanel = paneles[panel_selec - 1].potencia;
        prodPanelxDia = 4.0 * (paneles[panel_selec - 1].potencia / 1000.0);  // el 4 es por un promedio de horas pico de sol(max rendimiento)
        totalN = (consumoAcubrir / 30.0) / (prodPanelxDia *1.25);
        printf("Se necesitan %f paneles", totalN);

    }
        else{
        printf("Seleccione un panel primero");
    }
}

int calcularCosto(struct panel paneles[], int n_panel, int cantidad) {
    int costoTotal = 0;

  
    costoTotal = paneles[n_panel - 1].precio * cantidad;

  
    return costoTotal;
}







}
