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
            "----- PRUEBAS -----\n"
            "21) MOSTRAR clientes.\n\n"
            "Ingrese una opcion(1-20): ",
            "\nERROR Ingrese una opcion valida.\n",1,21))
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
                mostrarMascotasDeUnColor(mascotasLista,coloresLista,tiposLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM);
                break;
            case 12:
                mostrarMascotasDeUnTipo(mascotasLista,coloresLista,tiposLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM);
                break;
            case 13:
                informarMascotaMasJoven(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM);
                break;
            case 14:
                mostrarMascotasXtipo(mascotasLista,tiposLista,coloresLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM);
                break;
            case 15:
                mostrarMascotasXcolorXtipo(mascotasLista,tiposLista,coloresLista,MASCOTASTAM,TIPOSTAM);
                break;
            case 16:
                informarColorConMasCantidad(mascotasLista,coloresLista,MASCOTASTAM,COLORESTAM);
                break;
            case 17:
                mostrarTrabajosDeXMascota(mascotasLista,tiposLista,coloresLista,serviciosLista,trabajosLista,clientesLista,CLIENTESTAM,MASCOTASTAM,TIPOSTAM,SERVICIOSTAM,TRABAJOSTAM);
                break;
            case 18:
                sumaTrabajosDeXmascota(mascotasLista,tiposLista,coloresLista,clientesLista,serviciosLista,trabajosLista,MASCOTASTAM,TIPOSTAM,CLIENTESTAM,SERVICIOSTAM,TRABAJOSTAM);
                break;
            case 19:
                mostrarServiciosDeXmascota(mascotasLista,tiposLista,coloresLista,clientesLista,serviciosLista,trabajosLista,MASCOTASTAM,TIPOSTAM,CLIENTESTAM,SERVICIOSTAM,TRABAJOSTAM);
                break;
            case 20:
                mostrarTrabajosDeXfecha(mascotasLista,tiposLista,coloresLista,clientesLista,serviciosLista,trabajosLista,MASCOTASTAM,TIPOSTAM,CLIENTESTAM,SERVICIOSTAM,TRABAJOSTAM);
                break;
            case 21:
                mostrarClientes(clientesLista,CLIENTESTAM);
                break;
            }
        }
    }while(salir!='s');

    return 0;
}
