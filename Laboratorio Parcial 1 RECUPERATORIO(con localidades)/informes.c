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

int buscarYmostrarXcolor(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                         int clientesTam,int mascotasTam,int tiposYcoloresTam,int idBuscado)
{
    int error=1;
    char colorNombre[20];

    if(colores!=NULL && tipos!=NULL && mascotas!=NULL && mascotasTam>0 && tiposYcoloresTam>0 && idBuscado>4999 && idBuscado<5005)
    {
        cargarNombreColor(idBuscado,colores,tiposYcoloresTam,colorNombre);
        printf("\n---- TODAS LAS MASCOTA DEL COLOR |%s| ----\n",colorNombre);
        for(int i=0;i<mascotasTam;i++)
        {
            if(mascotas[i].idColor==idBuscado)
            {
                mostrarMascota(mascotas[i],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                error=0;
            }
        }
    }

    return error;
}
int mostrarMascotasDeUnColor(eMascota mascotas[],eColor colores[],eTipo tipos[],eCliente clientes[],
                             int clientesTam,int mascotasTam,int tiposYcoloresTam)
{
    int error=1;
    int idColorElegido;

    if(mascotas!=NULL && tipos!=NULL && colores!=NULL && mascotasTam>0 && tiposYcoloresTam>0)
    {
        if(!mostrarColores(colores,tiposYcoloresTam)
           &&!getNumero(&idColorElegido,"\nIngrese el ID del color que quiere buscar: ","\nERROR Ingrese un ID valido.\n",5000,5004))
        {
            if(!buscarYmostrarXcolor(mascotas,tipos,colores,clientes,clientesTam,mascotasTam,tiposYcoloresTam,idColorElegido))
            {
                printf("\nMascotas del color elegido mostradas con exito!\n");
                error=0;
            }
            else
            {
                printf("\nNo hay mascotas con de ese COLOR.\n");
            }
        }
    }

    return error;
}

int buscarYmostrarXtipo(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],int clientesTam,int mascotasTam,int tiposYcoloresTam,int idBuscado)
{
    int error=1;
    char tipoNombre[20];

    if(tipos!=NULL && colores!=NULL && mascotas!=NULL && mascotasTam>0 && tiposYcoloresTam>0 && idBuscado>999 && idBuscado<1005)
    {
        cargarNombreTipo(idBuscado,tipos,tiposYcoloresTam,tipoNombre);
        printf("\n---- TODAS LAS MASCOTA DEL TIPO |%s| ----\n",tipoNombre);
        for(int i=0;i<mascotasTam;i++)
        {
            if(mascotas[i].idTipo==idBuscado)
            {
                mostrarMascota(mascotas[i],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                error=0;
            }
        }
    }

    return error;
}
int mostrarMascotasDeUnTipo(eMascota mascotas[],eColor colores[],eTipo tipos[],eCliente clientes[],int clientesTam,int mascotasTam,int tiposYcoloresTam)
{
    int error=1;
    int idTipoElegido;

    if(mascotas!=NULL && colores!=NULL && tipos!=NULL && mascotasTam>0 && tiposYcoloresTam>0)
    {
        if(!mostrarTipos(tipos,tiposYcoloresTam)
           &&!getNumero(&idTipoElegido,"\nIngrese el ID del tipo que quiere buscar: ","\nERROR Ingrese un ID valido.\n",1000,1004))
        {
            if(!buscarYmostrarXtipo(mascotas,tipos,colores,clientes,clientesTam,mascotasTam,tiposYcoloresTam,idTipoElegido))
            {
                printf("\nMascotas del tipo elegido mostradas con exito!\n");
                error=0;
            }
            else
            {
                printf("\nNo hay mascotas con de ese TIPO.\n");
            }
        }
    }

    return error;
}
int buscarMenorEdad(eMascota mascotas[],int tam,int* menorEdad)
{
    int error=0;
    int flag=1;

    for(int i=0;i<tam;i++)
    {
        if(flag==1 && mascotas[i].isEmpty==0)
        {
            *menorEdad=mascotas[i].edad;
            flag=0;
        }
        else
        {
            if(*menorEdad>mascotas[i].edad && mascotas[i].isEmpty==0)
            {
                *menorEdad=mascotas[i].edad;
            }
        }
    }
    if(flag==1)
    {
        error=1;
    }

    return error;
}
int informarMascotaMasJoven(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                            int clientesTam,int mascotasTam,int tiposYcoloresTam)
{
     int error=1;
     int menorEdad;

     if(mascotas!=NULL && tipos!=NULL && colores!=NULL && mascotasTam>0 && tiposYcoloresTam>0)
     {
        printf("\n---- MASCOTAS DE MENOR EDAD ----\n");
        if(!buscarMenorEdad(mascotas,mascotasTam,&menorEdad))
        {
            for(int i=0;i<mascotasTam;i++)
            {
                if(mascotas[i].edad==menorEdad)
                {
                    mostrarMascota(mascotas[i],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                    error=0;
                }
            }
        }
     }

     return error;
}
int mostrarMascotasXtipo(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                         int clientesTam,int mascotasTam,int tiposYcoloresTam)
{
    int error=1;
    int flag=1;

    if(mascotas!=NULL && tipos!=NULL && colores!=NULL && mascotasTam>0 && tiposYcoloresTam>0)
    {
        for(int i=0;i<tiposYcoloresTam;i++)
        {
            printf("\n\n---- MASCOTAS DEL TIPO |%s| ----\n\n",tipos[i].nombreTipo);
            for(int j=0;j<mascotasTam;j++)
            {
                if(mascotas[j].idTipo==tipos[i].id && mascotas[j].isEmpty==0)
                {
                    mostrarMascota(mascotas[j],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                    flag=0;
                }
            }
            if(flag==1)
            {
                printf("\nERROR No hay mascotas de este tipo.\n");
            }
            flag=1;
        }
        error=0;
    }

    return error;
}
int contarMascotasXcolorXtipo(eMascota mascotas[],int mascotasTam,int idColorElegido,int idTipoElegido)
{
    int cantidad=0;

    for(int i=0;i<mascotasTam;i++)
    {
        if(mascotas[i].idColor==idColorElegido && mascotas[i].idTipo==idTipoElegido)
        {
            cantidad++;
        }
    }

    return cantidad;
}
int mostrarMascotasXcolorXtipo(eMascota mascotas[],eTipo tipos[],eColor colores[],
                               int mascotasTam,int tiposYcoloresTam)
{
    int error=1;
    int idColorElegido;
    char nombreColor[20];
    int idTipoElegido;
    char nombreTipo[20];
    int resultado=0;

    if(mascotas!=NULL && tipos!=NULL && colores!=NULL)
    {
        if(!mostrarColores(colores,tiposYcoloresTam)
           &&!getNumero(&idColorElegido,"\nIngrese el ID del color: ","\nERROR Ingrese un ID valido.\n",5000,5004)
           &&!mostrarTipos(tipos,tiposYcoloresTam)
           &&!getNumero(&idTipoElegido,"\nIngrese el ID del tipo: ","\nERROR Ingrese un ID valido.\n",1000,1004))
           {
               cargarNombreColor(idColorElegido,colores,tiposYcoloresTam,nombreColor);
               cargarNombreTipo(idTipoElegido,tipos,tiposYcoloresTam,nombreTipo);

               resultado=contarMascotasXcolorXtipo(mascotas,mascotasTam,idColorElegido,idTipoElegido);
               printf("\nHay un total de %d mascotas de color |%s| y del tipo |%s|.\n",resultado,nombreColor,nombreTipo);
               error=0;
           }
    }

    return error;
}
int contarCantidadColores(eMascota mascotas[],int tam,int* indiceColor)
{
    int error=0;
    int flag=1;

    int arrayContadores[]={0,0,0,0,0};
    int mayorCantidad=0;

    for(int i=0;i<tam;i++)
    {
        if(flag==1 && mascotas[i].isEmpty==0)
        {
            switch(mascotas[i].idColor)
            {
            case 5000:
                arrayContadores[0]++;
                break;
            case 5001:
                arrayContadores[1]++;
                break;
            case 5002:
                arrayContadores[2]++;
                break;
            case 5003:
                arrayContadores[3]++;
                break;
            case 5004:
                arrayContadores[4]++;
                break;
            }
            flag=0;
        }
        else
        {
            switch(mascotas[i].idColor)
            {
            case 5000:
                arrayContadores[0]++;
                break;
            case 5001:
                arrayContadores[1]++;
                break;
            case 5002:
                arrayContadores[2]++;
                break;
            case 5003:
                arrayContadores[3]++;
                break;
            case 5004:
                arrayContadores[4]++;
                break;
            }
        }
    }
    if(flag==1)
    {
        error=1;
    }

    for(int j=0;j<5;j++)
    {
        if(arrayContadores[j]>mayorCantidad)
        {
            mayorCantidad=arrayContadores[j];
            *indiceColor=j;
        }
    }

    return error;
}
void buscarIdColor(eColor colores[],int tam,int indiceBuscado,int* idColorEncontrado)
{
    for(int i=0;i<tam;i++)
    {
        if(i==indiceBuscado)
        {
            *idColorEncontrado=colores[i].id;
            break;
        }
    }
}
int informarColorConMasCantidad(eMascota mascotas[],eColor colores[],int mascotasTam,int coloresTam)
{
    int error=1;
    int indiceColor;
    int idColorBuscado;
    char nombreColor[20];

    if(mascotas!=NULL && colores!=NULL)
    {
        if(!contarCantidadColores(mascotas,mascotasTam,&indiceColor))
        {
            buscarIdColor(colores,coloresTam,indiceColor,&idColorBuscado);
            cargarNombreColor(idColorBuscado,colores,coloresTam,nombreColor);
            printf("\nEl color con mas mascotas es el |%s|.\n",nombreColor);
            error=0;
        }
        else
        {
            printf("\nERROR No hay mascotas cargadas.\n");
        }
    }

    return error;
}
int mostrarTrabajosDeXMascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eServicio servicios[],eTrabajo trabajos[],eCliente clientes[],
                              int clientesTam,int mascotasTam,int tiposYcoloresTam,int serviciosTam,int trabajosTam)
{
    int error=1;
    int idMascotaPedido;
    int indiceMascotaBuscado;
    char mascotaNombre[20];

    if(mascotas!=NULL && tipos!=NULL && colores!=NULL && servicios!=NULL && trabajos!=NULL && mascotasTam>0 && trabajosTam>0)
    {
        if(!mostrarMascotas(mascotas,tipos,colores,clientes,clientesTam,tiposYcoloresTam,mascotasTam)
           &&!getNumero(&idMascotaPedido,"\nIngrese el ID de la mascota de la cual quiere informar los TRABAJOS realizados: ","\nERROR Ingrese un ID valido.\n",100,1000)
           &&!buscarSiIdExiste(mascotas,mascotasTam,idMascotaPedido))
           {
               buscarId(mascotas,mascotasTam,idMascotaPedido,&indiceMascotaBuscado);
               cargarNombreMascota(idMascotaPedido,mascotas,mascotasTam,mascotaNombre);
               printf("\n---- MOSTRANDO LOS TRABAJOS REALIZADOS DE: |%s| ----",mascotaNombre);
               mostrarMascota(mascotas[indiceMascotaBuscado],tipos,colores,clientes,clientesTam,tiposYcoloresTam);

               for(int i=0;i<mascotasTam;i++)
               {
                   if(trabajos[i].idMascota==idMascotaPedido)
                   {
                       mostrarTrabajo(trabajos[i],mascotas,servicios,mascotasTam,serviciosTam);
                   }
               }
               error=0;
           }
           else
           {
               printf("\nERROR El ID no existe.\n");
           }
    }

    return error;
}
int sumaTrabajosDeXmascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],eServicio servicios[],eTrabajo trabajos[],
                           int mascotasTam,int tiposYcoloresTam,int clientesTam,int serviciosTam,int trabajosTam)
{
    int error=1;
    float acumulador=0;
    int idMascotaElegido;
    int indiceEncontrado;

    eMascota auxMascota;
    eTrabajo auxTrabajo;
    eServicio auxServicio;

    if(mascotas!=NULL && tipos!=NULL && colores!=NULL && clientes!=NULL && servicios!=NULL && trabajos!=NULL)
    {
        if(!mostrarMascotas(mascotas,tipos,colores,clientes,clientesTam,tiposYcoloresTam,mascotasTam)
           &&!getNumero(&idMascotaElegido,"\nIngrese el ID de la mascota: \n","\nERROR Ingrese un ID valido.",100,1000)
           &&!buscarSiIdExiste(mascotas,mascotasTam,idMascotaElegido))
        {
            if(!buscarId(mascotas,mascotasTam,idMascotaElegido,&indiceEncontrado))
            {
                auxMascota=mascotas[indiceEncontrado];
                mostrarMascota(auxMascota,tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                for(int i=0;i<trabajosTam;i++)
                {
                    auxTrabajo=trabajos[i];
                    if(auxTrabajo.idMascota==idMascotaElegido && auxTrabajo.isEmpty==0)
                    {
                        mostrarTrabajo(auxTrabajo,mascotas,servicios,mascotasTam,serviciosTam);
                        for(int j=0;j<serviciosTam;j++)
                        {
                            auxServicio=servicios[j];
                            if(auxTrabajo.idServicio==servicios[j].id)
                            {
                                acumulador+=auxServicio.precio;
                            }
                        }
                        error=0;
                    }
                }
                if(error==1)
                {
                    printf("\nEsta mascota no tiene trabajos realizados.\n");
                }
                else
                {
                    printf("\n*** El importe final a pagar para |%s| seria de: |%.2f| ***\n",auxMascota.nombre,acumulador);
                }

            }
        }
    }
    return error;
}
int mostrarServiciosDeXmascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],eServicio servicios[],eTrabajo trabajos[],
                               int mascotasTam,int tiposYcoloresTam,int clientesTam,int serviciosTam,int trabajosTam)
{
    int error=1;
    int idServicioPedido;
    char nombreServicio[20];

    eMascota aux;
    if(mascotas!=NULL && tipos!=NULL && colores!=NULL && clientes!=NULL && servicios!=NULL)
    {
        if(!mostrarServicios(servicios,serviciosTam)
           &&!getNumero(&idServicioPedido,"\nIngrese el ID del servicio: ","\nERROR Ingrese un ID valido.\n",20000,20004))
           {
               cargarNombreServicio(idServicioPedido,servicios,serviciosTam,nombreServicio);
               printf("\n---- Mostrando los servicios de |%s| realizados ----\n",nombreServicio);
               for(int i=0;i<mascotasTam;i++)
               {
                   aux=mascotas[i];
                   if(trabajos[i].idServicio==idServicioPedido)
                   {
                       printf("\nFecha: %d/%d/%d",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
                       mostrarMascota(aux,tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                       error=0;
                   }
               }
           }
           if(error==1)
           {
               printf("\nNo hay mascotas a las que se les hizo ese servicio.\n");
           }
    }

    return error;
}
int mostrarTrabajosDeXfecha(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],eServicio servicios[],eTrabajo trabajos[],
                            int mascotasTam,int tiposYcoloresTam,int clientesTam,int serviciosTam,int trabajosTam)
{
    int error=1;
    int dia;
    int mes;
    int anio;

    eTrabajo auxTrabajo;

    if(mascotas!=NULL && tipos!=NULL && colores!=NULL && clientes!=NULL && servicios!=NULL)
    {
        if(!getNumero(&dia,"\nIngrese el DIA(12): ","\nERROR Ingrese una fecha VALIDA.\n",1,31)
           &&!getNumero(&mes,"\nIngrese el MES(11): ","\nERROR Ingrese una fecha VALIDA.\n",1,12)
           &&!getNumero(&anio,"\nIngrese el ANIO(2020): ","\nERROR Ingrese una fecha VALIDA.\n",1,3000))
        {
            printf("\n--- TRABAJOS REALIZADOS EN LA FECHA: %d/%d/%d ---\n",dia,mes,anio);
            for(int i=0;i<trabajosTam;i++)
            {
                auxTrabajo=trabajos[i];
                if(auxTrabajo.fecha.dia==dia)
                {
                    if(auxTrabajo.fecha.mes==mes)
                    {
                        if(auxTrabajo.fecha.anio==anio)
                        {
                            mostrarTrabajo(auxTrabajo,mascotas,servicios,mascotasTam,serviciosTam);
                            error=0;
                        }
                    }
                }
            }
        }
        if(error==1)
        {
            printf("\nNo hay trabajos realizados en esa fecha.\n");
        }
    }

    return error;
}
int informarLocalidadConMasClientes(eCliente clientes[],int tam)
{
    int error=1;
    int flag=1;
    int indiceMayor;
    int arrayContadores[]={0,0,0,0};
    int mayorCantidad=0;

    for(int i=0;i<tam;i++)
    {
        if(flag==1 && clientes[i].isEmpty==0)
        {
            if(!strcmp(clientes[i].localidad,"Caballito"))
            {
                arrayContadores[0]++;
                flag=0;
            }
            else if(!strcmp(clientes[i].localidad,"Olivos"))
            {
                arrayContadores[1]++;
                flag=0;
            }
            else if(!strcmp(clientes[i].localidad,"Avellaneda"))
            {
                arrayContadores[2]++;
                flag=0;
            }
            else if(!strcmp(clientes[i].localidad,"Almagro"))
            {
                arrayContadores[3]++;
                flag=0;
            }

        }
        else if(clientes[i].isEmpty==0)
        {
            if(!strcmp(clientes[i].localidad,"Caballito"))
            {
                arrayContadores[0]++;
            }
            else if(!strcmp(clientes[i].localidad,"Olivos"))
            {
                arrayContadores[1]++;
            }
            else if(!strcmp(clientes[i].localidad,"Avellaneda"))
            {
                arrayContadores[2]++;
            }
            else if(!strcmp(clientes[i].localidad,"Almagro"))
            {
                arrayContadores[3]++;
            }
        }
    }
    if(flag==1)
    {
        error=1;
    }

    for(int j=0;j<4;j++)
    {
        if(arrayContadores[j]>mayorCantidad)
        {
            mayorCantidad=arrayContadores[j];
            indiceMayor=j;
        }
    }
    switch(indiceMayor)
    {
    case 0:
        printf("\n La localidad con mas clientes es Caballito!\n");
        error=0;
        break;
    case 1:
        printf("\n La localidad con mas clientes es Olivos!\n");
        error=0;
        break;
    case 2:
        printf("\n La localidad con mas clientes es Avellaneda!\n");
        error=0;
        break;
    case 3:
        printf("\n La localidad con mas clientes es Almagro!\n");
        error=0;
        break;
    }

    return error;
}
int informarEdadTotalMascotas(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],int clientesTam,int tiposYcoloresTam,int tam)
{
	int error=1;
	int acumulador=0;

	if(mascotas!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(mascotas[i].isEmpty==0)
			{
				acumulador=mascotas[i].edad+acumulador;
			}
		}
		mostrarMascotas(mascotas,tipos,colores,clientes,clientesTam,tiposYcoloresTam,tam);
		printf("\nEl total de edad de las mascotas es %d\n",acumulador);
		error=0;
	}

	return error;
}
int mostrarClientesDeXlocalidad(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],int clientesTam,int tiposYcoloresTam,int tam)
{
    int error=1;
    int opcionElegida;

    if(mascotas!=NULL)
    {
        if(!getNumero(&opcionElegida,
            "\n1) Caballito.\n"
            "2) Almagro.\n"
            "3) Olivos.\n"
            "4) Avellaneda.\n\n"
            "Ingrese una localidad: ",
            "\nERROR Ingrese una opcion valida.\n",1,4))
        {
            switch(opcionElegida)
            {
            case 1:
               printf("\n---- Mostrando los clientes de Caballito ----\n");
               for(int i=0;i<clientesTam;i++)
               {
                   if(!strcmp(clientes[i].localidad,"Caballito"))
                   {
                       mostrarCliente(clientes[i]);
                   }
               }
               break;
            case 2:
               printf("\n---- Mostrando los clientes de Almagro ----\n");
               for(int i=0;i<clientesTam;i++)
               {
                   if(!strcmp(clientes[i].localidad,"Almagro"))
                   {
                       mostrarCliente(clientes[i]);
                   }
               }
               break;
            case 3:
               printf("\n---- Mostrando los clientes de Olivos ----\n");
               for(int i=0;i<clientesTam;i++)
               {
                   if(!strcmp(clientes[i].localidad,"Olivos"))
                   {
                       mostrarCliente(clientes[i]);
                   }
               }
               break;
            case 4:
               printf("\n---- Mostrando los clientes de Avellaneda ----\n");
               for(int i=0;i<clientesTam;i++)
               {
                   if(!strcmp(clientes[i].localidad,"Avellaneda"))
                   {
                       mostrarCliente(clientes[i]);
                   }
               }
               break;
            }
            error=0;
        }
    }

    return error;
}
int mostrarMascotasDeXlocalidad(eMascota mascotas[],eCliente clientes[],eTipo tipos[],eColor colores[],int clientesTam, int mascotasTam,int tiposYcoloresTam)
{
    int error=1;
    int opcionElegida;

    if(mascotas!=NULL)
    {
        if(!getNumero(&opcionElegida,
            "\n1) Caballito.\n"
            "2) Almagro.\n"
            "3) Olivos.\n"
            "4) Avellaneda.\n\n"
            "Ingrese una localidad: ",
            "\nERROR Ingrese una opcion valida.\n",1,4))
        {
            switch(opcionElegida)
            {
            case 1:
               printf("\n---- Mostrando las mascotas de Caballito ----\n");
               for(int i=0;i<mascotasTam;i++)
               {
                   if(!strcmp(clientes[i].localidad,"Caballito"))
                   {
                       mostrarMascota(mascotas[i],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                   }
               }
               break;
            case 2:
               printf("\n---- Mostrando las mascotas de Almagro ----\n");
               for(int i=0;i<mascotasTam;i++)
               {
                   if(!strcmp(clientes[i].localidad,"Almagro"))
                   {
                       mostrarMascota(mascotas[i],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                   }
               }
               break;
            case 3:
               printf("\n---- Mostrando las mascotas de Olivos ----\n");
               for(int i=0;i<mascotasTam;i++)
               {
                   if(!strcmp(clientes[i].localidad,"Olivos"))
                   {
                       mostrarMascota(mascotas[i],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                   }
               }
               break;
            case 4:
               printf("\n---- Mostrando las mascotas de Avellaneda ----\n");
               for(int i=0;i<mascotasTam;i++)
               {
                   if(!strcmp(clientes[i].localidad,"Avellaneda"))
                   {
                       mostrarMascota(mascotas[i],tipos,colores,clientes,clientesTam,tiposYcoloresTam);
                   }
               }
               break;
            }
            error=0;
        }
    }

    return error;
}
int mascotasConClienteFemenino(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                            int mascotasTam,int tiposYcoloresTam,int clientesTam)
{
    int error=1;
    int flag=1;

    if(mascotas!=NULL && tipos!=NULL && colores!=NULL && clientes!=NULL)
    {
    	for(int i=0;i<mascotasTam;i++)
    	{
    		for(int j=0;j<clientesTam;j++)
    		{
    			if(mascotas[i].idCliente==clientes[j].id)
    			{
    				if(clientes[j].sexo=='f')
    				{
    					mostrarMascota(mascotas[i], tipos, colores, clientes, clientesTam, tiposYcoloresTam);
    					error=0;
    					flag=0;
    				}

    			}
    		}
    	}
    	if(flag==1)
    	{
    		printf("\nERROR No hay clientes femeninos\n");
    	}

    }

    return error;
}
