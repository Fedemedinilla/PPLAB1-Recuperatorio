#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mascota.h"
#include "informes.h"
#include "entidades.h"
#include "misFuncionesGet.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"
#include "trabajo.h"
#include "servicio.h"

int clientesInit(eCliente* lista,int tam)
{
    int error=1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            lista[i].isEmpty=1;
        }
        error=0;
    }

    return error;
}
int hardcodearClientes(eCliente clientes[],int tam,int* idActual,int cuantosHardcodea)
{
    int hardcodeados=0;

	eCliente clientesAux[5]=
	{
			{0,"Ramiro",'m',0},
			{0,"Roberto",'m',0},
			{0,"Camila",'f',0},
			{0,"Delorean",'m',0},
			{0,"Fernando",'m',0},
	};
	if(clientes!=NULL&& clientesAux!=NULL&& tam>0 && idActual!=NULL)
	{
		for(int i=0; i<cuantosHardcodea; i++)
		{
			clientes[i]=clientesAux[i];

			clientes[i].id=*idActual;
			(*idActual)++;
			hardcodeados++;
		}
	}

	return hardcodeados;
}
void mostrarCliente(eCliente cliente)
{
    printf("\n|%d|  %7s  %c",cliente.id,cliente.nombreCliente,cliente.sexo);
}
int mostrarClientes(eCliente clientes[],int tam)
{
    int error=1;
    int flag=1;

    if(clientes!=NULL && tam>0)
    {
        printf("\n\n---- LISTA DE CLIENTES ----\n\n");
        printf("\n|ID|    |Nombre|   |Sexo|\n");
        for(int i=0;i<tam;i++)
        {
            if(clientes[i].isEmpty==0)
            {
               mostrarCliente(clientes[i]);
               flag=0;
               error=0;
            }
        }
    }
    if(flag==1)
    {
        error=1;
    }

    return error;
}
int cargarNombreCliente(int idCliente,eCliente clientes[],int tam,char clienteNombre[])
{
    int error=1;

    if(idCliente>=200 && clientes!=NULL && tam>0 && clienteNombre!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(clientes[i].id==idCliente)
            {
                strcpy(clienteNombre,clientes[i].nombreCliente);
                error=0;
                break;
            }
        }
    }

    return error;
}
