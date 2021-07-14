#include <stdio.h>
#include <stdlib.h>
#include "misFuncionesGet.h"
#include "entidades.h"
#include "informes.h"

#include "mascota.h"
#include "informes.h"
#include "entidades.h"
#include "misFuncionesGet.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"
#include "trabajo.h"
#include "servicio.h"

#define MASCOTASTAM 10
#define TIPOSTAM 5
#define COLORESTAM 5
#define SERVICIOSTAM 3
#define TRABAJOSTAM 10
#define CLIENTESTAM 20

int main()
{
    eMascota mascotasLista[MASCOTASTAM];
    eTipo tiposLista[TIPOSTAM];
    eColor coloresLista[COLORESTAM];
    eServicio serviciosLista[SERVICIOSTAM];
    eTrabajo trabajosLista[TRABAJOSTAM];

    eCliente clientesLista[CLIENTESTAM];

    int menuOpcion;
    char salir='n';
    int idActual=100;
    int idTrabajosActual=1;
    int idClienteActual=200;

    if(!inicializaciones(tiposLista,coloresLista,serviciosLista,mascotasLista,TIPOSTAM,SERVICIOSTAM,MASCOTASTAM))
    {
        printf("\n*** Las inicializaciones se completaron con exito! ***\n\n");
    }
    else
    {
        printf("\n*** ERROR una o varias inicializaciones fallaron. ***\n\n");
    }

    clientesInit(clientesLista,CLIENTESTAM);

    if(hardcodearMascotas(mascotasLista,MASCOTASTAM,&idActual,5)==5
       &&hardcodearTrabajos(trabajosLista,TRABAJOSTAM,&idTrabajosActual,5)==5
       &&hardcodearClientes(clientesLista,CLIENTESTAM,&idClienteActual,5)==5)
    {
        printf("\nMascotas, trabajos y clientes hardcodeados con exito.\n");
    }
    else
    {
        printf("\nERROR al hardcodear las mascotas, los trabajos y los clientes.\n");
    }

    do
    {
        if(!getNumero(&menuOpcion,
            "\n*** ABM PRIMER PARCIAL LABORATORIO ***\n\n"
            "1) ALTA mascota.\n"
            "2) MODIFICAR mascota.\n"
            "3) BAJA mascota.\n"
            "4) LISTAR mascotas.\n"
            "5) LISTAR tipos.\n"
            "6) LISTAR colores.\n"
            "7) LISTAR servicios.\n"
            "8) ALTA trabajos.\n"
            "9) LISTAR trabajos.\n"
            "10) SALIR.\n"
            "----- INFORMES -----\n"
            "11) MOSTRAR mascotas de un COLOR.\n"
            "12) MOSTRAR mascotas de un TIPO.\n"
            "13) INFORMAR las mascotas de menor edad\n"
            "14) MOSTRAR mascotas separadas por TIPO.\n"
            "15) MOSTRAR mascotas de un TIPO y un COLOR.\n"
            "16) MOSTRAR el COLOR con mas mascotas.\n"
            "----- BONUS TRACK -----\n"
            "17) MOSTRAR trabajos de una mascota.\n"
            "18) INFORMAR la suma de los trabajos de una mascota.\n"
            "19) MOSTRAR las mascotas a las que se realizo X servicio.\n"
            "20) MOSTRAR trabajos de determinada fecha.\n\n"
            "----- RECUPERATORIO PARA PROMOCIONAR -----\n"
            "21) MOSTRAR clientes.\n"
            "22) INFORMAR localidad con + clientes.\n"
            "23) INFORMAR edad total\n"
            "24) INFORMAR clientes x localidad.\n"
            "25) INFORMAR mascotas x localidad.\n"
            "26) INFORMAR mascotas con clientes FEMENINOS\n\n"
            "Ingrese una opcion(1-20): ",
            "\nERROR Ingrese una opcion valida.\n",1,26))
        {

            switch(menuOpcion)
            {
            case 1:
                if(!altaMascota(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM,&idActual))
                {
                    printf("\n\n**** Mascotas cargadas con exito! ****\n\n");
                }
                else
                {
                    printf("\n\nERROR al cargar las mascotas.\n\n");
                }
                break;
            case 2:
                modificarMascota(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,TIPOSTAM,MASCOTASTAM);
                break;
            case 3:
                if(!bajaMascota(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,TIPOSTAM,MASCOTASTAM))
                {
                    printf("\nMascotas dadas de baja con exito!\n");
                }
                else
                {
                    printf("\nERROR al dar de baja.\n");
                }
                break;
            case 4:
                if(!mostrarMascotas(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,TIPOSTAM,MASCOTASTAM))
                {
                    printf("\n\n*** Mascotas mostradas con exito! ***\n\n");
                }
                else
                {
                    printf("\n\nERROR al mostrar las mascotas.\n\n");
                }
                break;
            case 5:
                mostrarTipos(tiposLista,TIPOSTAM);
                break;
            case 6:
                mostrarColores(coloresLista,COLORESTAM);
                break;
            case 7:
                mostrarServicios(serviciosLista,SERVICIOSTAM);
                break;
            case 8:
                altaTrabajo(mascotasLista,serviciosLista,trabajosLista,tiposLista,coloresLista,clientesLista,
                            CLIENTESTAM,MASCOTASTAM,SERVICIOSTAM,TRABAJOSTAM,TIPOSTAM,&idTrabajosActual);
                break;
            case 9:
                mostrarTrabajos(trabajosLista,mascotasLista,serviciosLista,TRABAJOSTAM,MASCOTASTAM,SERVICIOSTAM);
                break;
            case 10:
                if(!getDosChar("\nDesea salir del programa?(S/N): ","\nERROR Ingrese S o N.\n",'s','n'))
                {
                    salir='s';
                }
                break;
            case 11:
                if(!mostrarMascotasDeUnColor(mascotasLista,coloresLista,tiposLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM))
                {
                	printf("\n\n*** mostrar Mascotas De Un Color con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al mostrar Mascotas De Un Color.\n\n");
				}
                break;
            case 12:
                if(!mostrarMascotasDeUnTipo(mascotasLista,coloresLista,tiposLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM))
                {
                	printf("\n\n*** mostrar Mascotas De Un Tipo con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al mostrar Mascotas De Un Tipo.\n\n");
				}
                break;
            case 13:
                if(!informarMascotaMasJoven(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM))
                {
                	printf("\n\n*** informar Mascota Mas Joven con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al informar Mascota Mas Joven.\n\n");
				}
                break;
            case 14:
                if(!mostrarMascotasXtipo(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM))
                {
                	printf("\n\n*** mostrar Mascotas X tipo con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al mostrar Mascotas X tipo.\n\n");
				}
                break;
            case 15:
                if(!mostrarMascotasXcolorXtipo(mascotasLista,tiposLista,coloresLista,MASCOTASTAM,TIPOSTAM))
                {
                	printf("\n\n*** mostrar Mascotas X color y tipo con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al mostrar Mascotas X color y tipo.\n\n");
				}
                break;
            case 16:
                if(!informarColorConMasCantidad(mascotasLista,coloresLista,MASCOTASTAM,COLORESTAM))
                {
                	printf("\n\n*** informar Color Con Mas Cantidad con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al informar Color Con Mas Cantidad.\n\n");
				}
                break;
            case 17:
                if(!mostrarTrabajosDeXMascota(mascotasLista,tiposLista,coloresLista,serviciosLista,trabajosLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM,SERVICIOSTAM,TRABAJOSTAM))
                {
                	printf("\n\n*** mostrar Trabajos X Mascota con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al mostrar Trabajos X Mascota.\n\n");
				}
                break;
            case 18:
                if(!sumaTrabajosDeXmascota(mascotasLista,tiposLista,coloresLista,clientesLista,serviciosLista,trabajosLista,MASCOTASTAM,TIPOSTAM,CLIENTESTAM,SERVICIOSTAM,TRABAJOSTAM))
                {
                	printf("\n\n*** suma Trabajos X Mascota con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al suma Trabajos X Mascota.\n\n");
				}
                break;
            case 19:
                if(!mostrarServiciosDeXmascota(mascotasLista,tiposLista,coloresLista,clientesLista,serviciosLista,trabajosLista,MASCOTASTAM,TIPOSTAM,CLIENTESTAM,SERVICIOSTAM,TRABAJOSTAM))
                {
                	printf("\n\n*** mostrar Servicios X mascota con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al mostrar Servicios X mascota.\n\n");
				}
                break;
            case 20:
                if(!mostrarTrabajosDeXfecha(mascotasLista,tiposLista,coloresLista,clientesLista,serviciosLista,trabajosLista,MASCOTASTAM,TIPOSTAM,CLIENTESTAM,SERVICIOSTAM,TRABAJOSTAM))
                {
                	printf("\n\n*** mostrar Trabajos X fecha con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al mostrar Trabajos X fecha.\n\n");
				}
                break;
            case 21:
                if(!mostrarClientes(clientesLista,CLIENTESTAM))
                {
                	printf("\n\n*** mostrar Clientes con exito! ***\n\n");
				}
				else
				{
					printf("\n\nERROR al mostrar Clientes.\n\n");
				}
                break;
            case 22:
                informarLocalidadConMasClientes(clientesLista,CLIENTESTAM);
                break;
            case 23:
                if(!informarEdadTotalMascotas(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,TIPOSTAM,MASCOTASTAM))
                {
                    printf("\nInforme realizado con exito!\n");
                }
                else
                {
                    printf("\nERROR al devolver el informe.\n");
                }
                break;
            case 24:
                if(!mostrarClientesDeXlocalidad(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,TIPOSTAM,MASCOTASTAM))
                {
                    printf("\nInforme realizado con exito!\n");
                }
                else
                {
                    printf("\nERROR al devolver el informe.\n");
                }
                break;
            case 25:
                if(!mostrarMascotasDeXlocalidad(mascotasLista,clientesLista,tiposLista,coloresLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM))
                {
                    printf("\nInforme realizado con exito!\n");
                }
                else
                {
                    printf("\nERROR al devolver el informe.\n");
                }
                break;
            case 26:
                if(!mascotasConClienteFemenino(mascotasLista,tiposLista,coloresLista,clientesLista,MASCOTASTAM,TIPOSTAM,CLIENTESTAM))
                {
                    printf("\nInforme realizado con exito!\n");
                }
                else
                {
                    printf("\nERROR al devolver el informe.\n");
                }
                break;
            }
        }
    }while(salir!='s');

    return 0;
}
