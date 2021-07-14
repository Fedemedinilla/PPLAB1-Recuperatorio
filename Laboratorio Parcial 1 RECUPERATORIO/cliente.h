#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "entidades.h"

int clientesInit(eCliente* lista,int tam);
int hardcodearClientes(eCliente clientes[],int tam,int* idActual,int cuantosHardcodea);
void mostrarCliente(eCliente cliente);
int mostrarClientes(eCliente clientes[],int tam);
int cargarNombreCliente(int idCliente,eCliente clientes[],int tam,char clienteNombre[]);

#endif // CLIENTE_H_INCLUDED
