#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "entidades.h"
#include "misFuncionesGet.h"

int serviciosInit(eServicio lista[],int tam)
{
    int error=1;
    int idServicio[]={20000,20001,20002};
    char nombre[][20]={"Corte","Desparacitado","Castrado"};
    float precio[]={250,300,400};

    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            lista[i].id=idServicio[i];
            strcpy(lista[i].nombreServicio,nombre[i]);
            lista[i].precio=precio[i];
        }
        error=0;
    }

    return error;
}
void mostrarServicio(eServicio servicio)
{
    printf("\n   %d   %s   %.2f\n     -----------",servicio.id,servicio.nombreServicio,servicio.precio);
}
int mostrarServicios(eServicio* servicios,int tam)
{
    int error=1;

    if(servicios!=NULL && tam>0)
    {
        printf("\n  |ID|   |SERVICIO|   |PRECIO|\n");
        for(int i=0;i<tam;i++)
        {
            mostrarServicio(servicios[i]);
        }
        error=0;
    }

    return error;
}

