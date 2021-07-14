#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascota.h"
#include "informes.h"
#include "entidades.h"
#include "misFuncionesGet.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"
#include "trabajo.h"
#include "servicio.h"

int hardcodearTrabajos(eTrabajo trabajos[],int tam,int* idTrabajosActual,int cuantosHardcodea)
{
    int hardcodeados=0;

    eTrabajo trabajosAux[5]=
    {

        {0,101,20001,{12,11,2020},0},
        {0,100,20001,{23,3,2021},0},
        {0,100,20001,{12,11,2020},0},
        {0,100,20002,{18,7,2020},0},
        {0,101,20002,{13,12,2021},0},
    };
 	if(trabajos!=NULL&& trabajosAux!=NULL&& tam>0 && idTrabajosActual!=NULL)
	{
		for(int i=0; i<cuantosHardcodea; i++)
		{
			trabajos[i]=trabajosAux[i];

			trabajos[i].id=*idTrabajosActual;
			(*idTrabajosActual)++;
			hardcodeados++;
		}
	}

    return hardcodeados;
}
int buscarIndicePrimerVacioTrabajos(eTrabajo trabajos[],int tam,int* indiceVacio)
{
    int error=1;

    if(trabajos!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(trabajos[i].isEmpty)
            {
                *indiceVacio=i;
                error=0;
                break;
            }
        }
    }

    return error;
}
int cargarNombreMascota(int idMascota,eMascota mascotas[],int mascotasTam,char mascotaNombre[])
{
    int error=1;

    if(mascotas!=NULL && mascotasTam>0)
    {
        for(int i=0;i<mascotasTam;i++)
        {
            if(mascotas[i].id==idMascota)
            {
                strcpy(mascotaNombre,mascotas[i].nombre);
                error=0;
                break;
            }
        }
    }

    return error;
}
int cargarNombreServicio(int idServicio,eServicio servicios[],int serviciosTam,char servicioNombre[])
{
    int error=1;

    if(servicios!=NULL && serviciosTam>0)
    {
        for(int i=0;i<serviciosTam;i++)
        {
            if(servicios[i].id==idServicio)
            {
                strcpy(servicioNombre,servicios[i].nombreServicio);
                error=0;
                break;
            }
        }
    }

    return error;
}
int cargarPrecioServicio(int idServicio,eServicio servicios[],int serviciosTam,float* precioServicio)
{
    int error=1;

    if(servicios!=NULL && serviciosTam>0)
    {
        for(int i=0;i<serviciosTam;i++)
        {
            if(servicios[i].id==idServicio)
            {
                *precioServicio=servicios[i].precio;
                error=0;
                break;
            }
        }
    }

    return error;
}
void mostrarTrabajo(eTrabajo trabajo,eMascota mascotas[],eServicio servicios[],int mascotasTam,int serviciosTam)
{
    char nombreMascota[20];
    char nombreServicio[20];
    float precioServicio;

    if(!cargarNombreMascota(trabajo.idMascota,mascotas,mascotasTam,nombreMascota)
       &&!cargarNombreServicio(trabajo.idServicio,servicios,serviciosTam,nombreServicio)
       &&!cargarPrecioServicio(trabajo.idServicio,servicios,serviciosTam,&precioServicio))
    {
        printf("\n %d   %s   %s   %.2f   %d/%d/%d\n",trabajo.id,nombreMascota,nombreServicio,precioServicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
    }
}
int mostrarTrabajos(eTrabajo trabajos[],eMascota mascotas[],eServicio servicios[],int trabajosTam,int mascotasTam,int serviciosTam)
{
    int error=1;
    int flag=0;

    if(trabajos!=NULL && mascotas!=NULL && trabajosTam>0)
    {
        printf("\n\n*** TRABAJOS ***\n\n|ID|   |Mascota|   |Servicio|   |Precio|   |Fecha|");
        for(int i=0;i<trabajosTam;i++)
        {
            if(trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],mascotas,servicios,mascotasTam,serviciosTam);
                error=0;
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        error=1;
    }

    return error;
}
int altaTrabajo(eMascota mascotas[],eServicio servicios[],eTrabajo trabajos[],eTipo tipos[],eColor colores[],eCliente clientes[],
                int clientesTam,int mascotastam,int serviciosTam,int trabajosTam,int tiposYcoloresTam,int* idTrabajoActual)
{
    int error=1;
    char salir='n';
    int indiceVacio;

    eTrabajo aux;

    if(mascotas!=NULL && trabajos!=NULL && trabajosTam>0 && mascotastam>0 && idTrabajoActual>0)
    {
        do
        {
            if(!buscarIndicePrimerVacioTrabajos(trabajos,trabajosTam,&indiceVacio))
            {
                if(!mostrarServicios(servicios,serviciosTam)
                   &&!getNumero(&aux.idServicio,"\nIngrese el ID del servicio: ","\nERROR Ingrese un ID valido.\n",20000,20002)
                   &&!mostrarMascotas(mascotas,tipos,colores,clientes,clientesTam,tiposYcoloresTam,mascotastam)
                   &&!getNumero(&aux.idMascota,"\nIngrese el ID de la mascota: ","\nERROR Ingrese un ID valido.\n",100,1000)
                   &&!buscarSiIdExiste(mascotas,mascotastam,aux.idMascota)
                   &&!getNumero(&aux.fecha.dia,"\nIngrese el DIA: ","\nERROR Ingrese una fecha valida.",1,31)
                   &&!getNumero(&aux.fecha.mes,"\nIngrese el MES: ","\nERROR Ingrese una fecha valida.",1,12)
                   &&!getNumero(&aux.fecha.anio,"\nIngrese el ANIO: ","\nERROR Ingrese una fecha valida.",2000,2022))
                   {
                       aux.id=*idTrabajoActual;
                       mostrarTrabajo(aux,mascotas,servicios,mascotastam,serviciosTam);
                       if(!getDosChar("\nEste es el trabajo que desea agregar?(S/N): ","\nERROR Ingrese S o N.\n",'s','n'))
                       {
                           aux.isEmpty=0;
                           trabajos[indiceVacio]=aux;
                           (*idTrabajoActual)++;
                           error=0;
                       }
                       else
                       {
                           error=1;
                           printf("\nCarga cancelada por el usuario.\n");
                       }
                   }
                if(getDosChar("\nDesea agregar otro trabajo?(S/N): ","\nERROR Ingrese S o N.\n",'s','n'))
                {
                    printf("\nVolviendo al menu principal.\n");
                    salir='s';
                }
            }
            else
            {
                printf("\nERROR No hay espacio suficiente para agregar mas Trabajos.\n");
            }
        }while(salir!='s');

    }

    return error;
}
