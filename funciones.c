#include <stdio.h>
#include <string.h>
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