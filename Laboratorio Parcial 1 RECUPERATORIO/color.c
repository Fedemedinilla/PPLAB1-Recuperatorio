#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "entidades.h"
#include "misFuncionesGet.h"

int coloresInit(eColor lista[],int tam)
{
    int error=1;
    int idColor[]={5000,5001,5002,5003,5004};
    char nombre[][20]={"Negro","Blanco","Gris","Rojo","Azul"};

    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            lista[i].id=idColor[i];
            strcpy(lista[i].nombreColor,nombre[i]);
        }
        error=0;
    }

    return error;
}
void mostrarColor(eColor color)
{
    printf("\n   %d   %s\n     -------",color.id,color.nombreColor);
}
int mostrarColores(eColor* colores,int tam)
{
    int error=1;

    if(colores!=NULL && tam>0)
    {
        printf("\n  |ID|   |COLOR|\n");
        for(int i=0;i<tam;i++)
        {
            mostrarColor(colores[i]);
        }
        error=0;
    }

    return error;
}
