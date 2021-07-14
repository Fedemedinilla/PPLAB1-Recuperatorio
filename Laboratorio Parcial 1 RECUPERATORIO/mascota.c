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

int mascotasInit(eMascota* lista,int tam)
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
int inicializaciones(eTipo tipos[],eColor colores[],eServicio servicios[],eMascota mascotas[],int tam,int serviciosTam,int mascotasTam)
{
    int error=0;

    if(tipos!=NULL && colores!=NULL && tam>0)
    {
        while(1)
        {
            if(tiposInit(tipos,tam))
            {
                error=1;
                printf("\n\n*** ERROR al inicializar los TIPOS ***\n\n");
                break;
            }
            if(coloresInit(colores,tam))
            {
                error=1;
                printf("\n\n*** ERROR al inicializar los COLORES ***\n\n");
                break;
            }
            if(serviciosInit(servicios,serviciosTam))
            {
                error=1;
                printf("\n\n*** ERROR al inicializar los SERVICIOS ***\n\n");
            }
            if(mascotasInit(mascotas,mascotasTam))
            {
                error=1;
                printf("\n\n*** ERROR al inicializar las MASCOTAS ***\n\n");
                break;
            }
            break;
        }
    }

    return error;
}
int hardcodearMascotas(eMascota mascotas[],int tam,int* idActual,int cuantosHardcodea)
{
    int hardcodeados=0;

	eMascota mascotasAux[5]=
	{
			{0,"Roberta",1002,5002,3,200,0},
			{0,"Carlos",1002,5003,4,201,0},
			{0,"NombreOriginal",1003,5004,5,202,0},
			{0,"Starwars",1004,5001,2,203,0},
			{0,"Martin",1004,5003,4,204,0},
	};
	if(mascotas!=NULL&& mascotasAux!=NULL&& tam>0 && idActual!=NULL)
	{
		for(int i=0; i<cuantosHardcodea; i++)
		{
			mascotas[i]=mascotasAux[i];

			mascotas[i].id=*idActual;
			(*idActual)++;
			hardcodeados++;
		}
	}

	return hardcodeados;
}
int buscarIndicePrimerVacio(eMascota mascotas[],int tam,int* indiceVacio)
{
    int error=1;

    if(mascotas!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(mascotas[i].isEmpty)
            {
                *indiceVacio=i;
                error=0;
                break;
            }
        }
    }

    return error;
}
int cargarNombreTipo(int idTipo,eTipo tipos[],int tam,char tipoNombre[])
{
    int error=1;

    if(idTipo>=1000 && idTipo<=1004 && tipos!=NULL && tam>0 && tipoNombre!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(tipos[i].id==idTipo)
            {
                strcpy(tipoNombre,tipos[i].nombreTipo);
                error=0;
                break;
            }
        }
    }

    return error;
}
int cargarNombreColor(int idColor,eColor colores[],int tam,char colorNombre[])
{
    int error=1;

    if(idColor>=5000 && idColor<=5004 && colores!=NULL && tam>0 && colorNombre!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(colores[i].id==idColor)
            {
                strcpy(colorNombre,colores[i].nombreColor);
                error=0;
                break;
            }
        }
    }

    return error;
}
void mostrarMascota(eMascota mascota,eTipo tipos[],eColor colores[],eCliente clientes[],int clientesTam,int tiposYcoloresTam)
{
    char nombreTipo[20];
    char nombreColor[20];
    char nombreCliente[20];

    if(!cargarNombreTipo(mascota.idTipo,tipos,tiposYcoloresTam,nombreTipo)
    &&!cargarNombreColor(mascota.idColor,colores,tiposYcoloresTam,nombreColor)
    &&!cargarNombreCliente(mascota.idCliente,clientes,clientesTam,nombreCliente))
    {
        printf("\n   %d   %s   %s   %s   %d   %s\n  ------------------------------------",mascota.id,mascota.nombre,nombreTipo,nombreColor,mascota.edad,nombreCliente);
    }
}
int mostrarMascotas(eMascota lista[],eTipo tipos[],eColor colores[],eCliente clientes[],int clientesTam,int tiposYcoloresTam,int tam)
{
    int error=1;
    int flag=0;

    if(lista!=NULL && tam>0)
    {
        printf("\n\n---- LISTA DE MASCOTAS ----\n\n");
        printf("\n|ID|   |Nombre|   |Tipo|   |Color|   |Edad|   |Cliente|\n");
        for(int i=0;i<tam;i++)
        {
            if(lista[i].isEmpty==0)
            {
                mostrarMascota(lista[i],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
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
int buscarId(eMascota mascotas[],int tam,int idBuscado,int* indiceBuscado)
{
    int error=1;

    if(mascotas!=NULL && tam>0 && idBuscado>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(mascotas[i].id==idBuscado)
            {
                *indiceBuscado=i;
                error=0;
                break;
            }
        }
    }

    return error;
}
int buscarSiIdExiste(eMascota mascotas[],int tam,int idBuscado)
{
    int error=1;

    if(mascotas!=NULL && tam>0 && idBuscado>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(mascotas[i].id==idBuscado)
            {
                error=0;
                break;
            }
        }
    }

    return error;
}
int altaMascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                int clientesTam,int mascotasTam,int tiposYcoloresTam,int* idActual)
{
    int error=1;
    char salir='n';
    int indiceVacio;

    eMascota aux;

    if(mascotas!=NULL && tipos!=NULL && colores!=NULL && mascotasTam>=0
    && tiposYcoloresTam>0 && *idActual>=100)
    {
        do
        {
            if(!buscarIndicePrimerVacio(mascotas,mascotasTam,&indiceVacio))
            {
                if(!getNombre(aux.nombre,"\nIngrese el NOMBRE: ","\nERROR Ingrese un nombre valido.",25)
                   &&!mostrarTipos(tipos,tiposYcoloresTam)
                   &&!getNumero(&aux.idTipo,"\nIngrese el ID del TIPO: ","\nERROR Ingrese un ID valido.",1000,1004)
                   &&!mostrarColores(colores,tiposYcoloresTam)
                   &&!getNumero(&aux.idColor,"\nIngrese el ID del COLOR: ","\nERROR Ingrese un ID valido.",5000,5004)
                   &&!getNumero(&aux.edad,"\nIngrese la EDAD: ","\nERROR Ingrese una edad valida.",1,99)
                   &&!mostrarClientes(clientes,clientesTam)
                   &&!getNumero(&aux.idCliente,"\nIngrese el ID del cliente: \n","\nERROR Ingrese un ID valido.\n",200,204))
                {
                    aux.id=*idActual;
                    mostrarMascota(aux,tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                    if(!getDosChar("\nEsta es la mascota que desea agregar?(S/N): ","\nERROR Ingrese S o N.\n",'s','n'))
                    {
                        aux.isEmpty=0;
                        mascotas[indiceVacio]=aux;
                        (*idActual)++;
                    }
                    else
                    {
                        error=1;
                        printf("\nCarga cancelada por el usuario.\n");
                    }
                }
                if(getDosChar("\nDesea agregar otra mascota?(S/N): ","\nERROR Ingrese S o N.\n",'s','n'))
                {
                    printf("\nVolviendo al menu principal.\n");
                    salir='s';
                }
            }
            else
            {
                printf("\nERROR No hay espacio para cargar mas mascotas.\n");
            }
        }while(salir!='s');
    }

    return error;
}
int modificarMascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                     int clientesTam,int tiposYcoloresTam,int tam)
{
    int error=1;

    int idParaModificar;
    int indiceParaModificar;

    char salir='n';

    if(mascotas!=NULL && tam>0)
    {
        do
        {
            if(!mostrarMascotas(mascotas,tipos,colores,clientes,clientesTam,tiposYcoloresTam,tam))
            {
                if(!getNumero(&idParaModificar,"\nIngrese el ID de la mascota que quiere modificar: ","\nERROR ID invalido.\n",100,1000)
                   &&!buscarId(mascotas,tam,idParaModificar,&indiceParaModificar))
                {
                    mostrarMascota(mascotas[indiceParaModificar],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                    if(!getDosChar("\nEsta es la mascota que desea modificar?: ","\nERROR Ingrese S o N.",'s','n'))
                    {
                        menuModificaciones(&mascotas[indiceParaModificar],tipos,colores,clientes,clientesTam,tiposYcoloresTam,tam,idParaModificar,indiceParaModificar);
                        if(!getDosChar("\nDesea modificar otra mas?(S/N): ","\nERROR Ingrese S o N.\n",'n','s'))
                        {
                            printf("\nVOLVIENDO al menu principal.\n");
                            break;
                        }
                    }
                }
                else
                {
                    printf("\nERROR El ID no existe.\n");
                }
            }
            else
            {
                printf("\nERROR No hay mascotas para modificar.");
            }
        }while(salir!='s');

    }

    return error;
}
void menuModificaciones(eMascota* mascota,eTipo tipos[],eColor colores[],eCliente clientes[],
                        int clientesTam,int tiposYcoloresTam,int tam,int idParaModificar,int indiceParaModificar)
{
    int menuOpcion;
    char salir='n';
    eMascota aux;

    aux=*mascota;
    do
    {
        printf("\n\n**** EDITANDO A: ****\n\n");
        mostrarMascota(aux,tipos,colores,clientes,clientesTam,tiposYcoloresTam);
        if(!getNumero(&menuOpcion,
            "\n**** MENU DE MODIFICACIONES ****\n"
            "\n1) Modificar el NOMBRE."
            "\n2) Modificar el TIPO."
            "\n3) Modificar el COLOR."
            "\n4) Modificar la EDAD."
            "\n5) GUARDAR cambios."
            "\n6) SALIR.\n"
            "\nIngrese una opcion: ",
            "\nERROR Ingrese una opcion valida\n",1,6))
        {
            switch(menuOpcion)
            {
            case 1:
                if(!getNombre(aux.nombre,"\nIngrese el nuevo NOMBRE: ","\nERROR Ingrese un nombre valido.",25))
                {
                    printf("\nNOMBRE cambiado con exito.(Los cambios no tomaran efecto hasta que no GUARDE los cambios)\n");
                }
                break;
            case 2:
                if(!mostrarTipos(tipos,tiposYcoloresTam)
                   &&!getNumero(&aux.idTipo,"\nIngrese el ID del tipo nuevo: ","\nERROR Ingrese un ID valido.",1000,1004))
                {
                    printf("\nTIPO cambiado con exito.(Los cambios no tomaran efecto hasta que no GUARDE los cambios)\n");
                }
                break;
            case 3:
                if(!mostrarColores(colores,tiposYcoloresTam)
                   &&!getNumero(&aux.idColor,"\nIngrese el ID del color nuevo: ","\nERROR Ingrese un ID valido.",5000,5004))
                {
                    printf("\nCOLOR cambiado con exito.(Los cambios no tomaran efecto hasta que no GUARDE los cambios)\n");
                }
                break;
            case 4:
                if(!getNumero(&aux.edad,"\nIngrese la nueva EDAD: ","\nERROR Ingrese una edad valida.",1,100))
                {
                    printf("\nEDAD cambiada con exito.(Los cambios no tomaran efecto hasta que no GUARDE los cambios)\n");
                }
                break;
            case 5:
                if(!getDosChar("\nDesea guardar los cambios realizados?(S/N): ","\nERROR Ingrese S o N.",'s','n'))
                {
                    mostrarMascota(*mascota,tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                    *mascota=aux;
                    mostrarMascota(*mascota,tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                    printf("\nLos cambios se han guardado con exito!\n");
                }
                break;
            case 6:
                if(!getDosChar("\nDesea salir del menu de MODIFICACIONES?(S/N): ","\nERROR Ingrese S o N\n",'s','n'))
                {
                    salir='s';
                }
                break;
            }
        }
    }while(salir!='s');
}
int bajaMascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                int clientesTam,int tiposYcoloresTam,int tam)
{
    int error=1;
    int idParaBorrar;
    int indiceParaBorrar;
    char salir='n';

    if(mascotas!=NULL && tam>0)
    {
        do
        {
            if(!mostrarMascotas(mascotas,tipos,colores,clientes,clientesTam,tiposYcoloresTam,tam))
            {
                if(!getNumero(&idParaBorrar,"\nIngrese el ID de la mascota que quiere dar de BAJA: ","\nERROR Ingrese un ID VALIDO.",100,1000)
                   &&!buscarId(mascotas,tam,idParaBorrar,&indiceParaBorrar))
                {
                    mostrarMascota(mascotas[indiceParaBorrar],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                    if(!getDosChar("\nEsta es la mascota que desea dar de baja?(S/N): ","\nERROR Ingrese S o N.",'s','n'))
                    {
                        mascotas[indiceParaBorrar].isEmpty=1;
                        error=0;
                        if(!getDosChar("\nDesea dar de baja a otro?(S/N): ","\nERROR Ingrese S o N.",'s','n'))
                        {
                            salir='n';
                        }
                        else
                        {
                            salir='s';
                        }
                    }
                    else
                    {
                        printf("\nBaja cancelada por el usuario.\n");
                        if(!getDosChar("\nDesea dar de baja a otro?(S/N): ","\nERROR Ingrese S o N.",'s','n'))
                        {
                            salir='n';
                        }
                        else
                        {
                            salir='s';
                        }
                    }
                }
                else
                {
                    printf("\n\nERROR El ID no existe.\n\n");
                }
            }
            else
            {
                printf("\nERROR No hay mascotas cargadas.\n");
                salir='s';
                error=1;
            }
        }while(salir!='s');
    }

    return error;
}
