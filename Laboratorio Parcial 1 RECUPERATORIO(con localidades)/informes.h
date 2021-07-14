#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "entidades.h"

int buscarYmostrarXcolor(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                         int clientesTam,int mascotasTam,int tiposYcoloresTam,int idBuscado);
int mostrarMascotasDeUnColor(eMascota mascotas[],eColor colores[],eTipo tipos[],eCliente clientes[],
                             int clientesTam,int mascotasTam,int tiposYcoloresTam);
int buscarYmostrarXtipo(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],int clientesTam,int mascotasTam,int tiposYcoloresTam,int idBuscado);
int mostrarMascotasDeUnTipo(eMascota mascotas[],eColor colores[],eTipo tipos[],eCliente clientes[],int clientesTam,int mascotasTam,int tiposYcoloresTam);
int mostrarMascotasDeUnTipo(eMascota mascotas[],eColor colores[],eTipo tipos[],eCliente clientes[],int clientesTam,int mascotasTam,int tiposYcoloresTam);
int buscarMenorEdad(eMascota mascotas[],int tam,int* menorEdad);
int informarMascotaMasJoven(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                            int clientesTam,int mascotasTam,int tiposYcoloresTam);
int mostrarMascotasXtipo(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                         int clientesTam,int mascotasTam,int tiposYcoloresTam);
int mostrarMascotasXcolorXtipo(eMascota mascotas[],eTipo tipos[],eColor colores[],
                               int mascotasTam,int tiposYcoloresTam);
int contarCantidadColores(eMascota mascotas[],int tam,int* indiceColor);
void buscarIdColor(eColor colores[],int tam,int indiceBuscado,int* idColorEncontrado);
int informarColorConMasCantidad(eMascota mascotas[],eColor colores[],int mascotasTam,int coloresTam);
int mostrarTrabajosDeXMascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eServicio servicios[],eTrabajo trabajos[],eCliente clientes[],
                              int clientesTam,int mascotasTam,int tiposYcoloresTam,int serviciosTam,int trabajosTam);
int sumaTrabajosDeXmascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],eServicio servicios[],eTrabajo trabajos[],
                           int mascotasTam,int tiposYcoloresTam,int clientesTam,int serviciosTam,int trabajosTam);
int mostrarServiciosDeXmascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],eServicio servicios[],eTrabajo trabajos[],
                               int mascotasTam,int tiposYcoloresTam,int clientesTam,int serviciosTam,int trabajosTam);
int mostrarTrabajosDeXfecha(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],eServicio servicios[],eTrabajo trabajos[],
                            int mascotasTam,int tiposYcoloresTam,int clientesTam,int serviciosTam,int trabajosTam);

#endif // INFORMES_H_INCLUDED
