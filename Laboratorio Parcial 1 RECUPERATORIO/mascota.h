#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

#include "entidades.h"

int inicializaciones(eTipo tipos[],eColor colores[],eServicio servicios[],eMascota mascotas[],int tam,int serviciosTam,int mascotasTam);
int mascotasInit(eMascota lista[],int tam);
int altaMascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                int clientesTam,int mascotasTam,int tiposYcoloresTam,int* idActual);
void menuModificaciones(eMascota* mascota,eTipo tipos[],eColor colores[],eCliente clientes[],
                        int clientesTam,int tiposYcoloresTam,int tam,int idParaModificar,int indiceParaModificar);
int buscarIndicePrimerVacio(eMascota mascotas[],int tam,int* indiceVacio);
int cargarNombreTipo(int idTipo,eTipo tipos[],int tam,char tipoNombre[]);
int cargarNombreColor(int idColor,eColor colores[],int tam,char colorNombre[]);
void mostrarMascota(eMascota mascota,eTipo tipos[],eColor colores[],eCliente clientes[],int clientesTam,int tiposYcoloresTam);
int mostrarMascotas(eMascota lista[],eTipo tipos[],eColor colores[],eCliente clientes[],int clientesTam,int tiposYcoloresTam,int tam);
int buscarId(eMascota mascotas[],int tam,int idBuscado,int* indiceBuscado);
int bajaMascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                int clientesTam,int tiposYcoloresTam,int tam);
int modificarMascota(eMascota mascotas[],eTipo tipos[],eColor colores[],eCliente clientes[],
                     int clientesTam,int tiposYcoloresTam,int tam);
int hardcodearMascotas(eMascota mascotas[],int tam,int* idActual,int cuantosHardcodea);

#endif // MASCOTA_H_INCLUDED
