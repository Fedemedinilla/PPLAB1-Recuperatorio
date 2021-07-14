#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "entidades.h"

int hardcodearTrabajos(eTrabajo trabajos[],int tam,int* idTrabajosActual,int cuantosHardcodea);
int buscarIndicePrimerVacioTrabajos(eTrabajo trabajos[],int tam,int* indiceVacio);
int cargarNombreMascota(int idMascota,eMascota mascotas[],int mascotasTam,char mascotaNombre[]);
int cargarNombreServicio(int idServicio,eServicio servicios[],int serviciosTam,char servicioNombre[]);
int cargarPrecioServicio(int idServicio,eServicio servicios[],int serviciosTam,float* precioServicio);
void mostrarTrabajo(eTrabajo trabajo,eMascota mascotas[],eServicio servicios[],int mascotasTam,int serviciosTam);
int mostrarTrabajos(eTrabajo trabajos[],eMascota mascotas[],eServicio servicios[],int trabajosTam,int mascotasTam,int serviciosTam);
int altaTrabajo(eMascota mascotas[],eServicio servicios[],eTrabajo trabajos[],eTipo tipos[],eColor colores[],eCliente clientes[],
                int clientesTam,int mascotastam,int serviciosTam,int trabajosTam,int tiposYcoloresTam,int* idTrabajoActual);

#endif // TRABAJO_H_INCLUDED
