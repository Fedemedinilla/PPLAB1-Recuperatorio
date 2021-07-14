#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "entidades.h"
#include "misFuncionesGet.h"

int tiposInit(eTipo lista[],int tam)
{
    int error=1;
    int idTipo[]={1000,1001,1002,1003,1004};
    char nombre[][20]={"Ave","Perro","Gato","Roedor","Pez"};

    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            lista[i].id=idTipo[i];
            strcpy(lista[i].nombreTipo,nombre[i]);
        }
        error=0;
    }

    return error;
}
void mostrarTipo(eTipo tipo)
{
    printf("\n   %d   %s\n     -------",tipo.id,tipo.nombreTipo);
}
int mostrarTipos(eTipo* tipos,int tam)
{
    int error=1;

    if(tipos!=NULL && tam>0)
    {
        printf("\n  |ID|   |TIPO|\n");
        for(int i=0;i<tam;i++)
        {
            mostrarTipo(tipos[i]);
        }
        error=0;
    }

    return error;
}

