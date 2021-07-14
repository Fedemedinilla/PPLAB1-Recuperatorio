#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;///1000+
    char nombreTipo[21];
}eTipo;

typedef struct
{
    int id;///5000 - 5004
    char nombreColor[21];
}eColor;

typedef struct
{
    int id;///20000 - 20004
    char nombreServicio[26];
    float precio;
}eServicio;

typedef struct
{
    int id;
    char nombre[21];
    int idTipo;
    int idColor;
    int edad;
    int idCliente;///200+
    int isEmpty;
}eMascota;

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

typedef struct
{
    int id;
    char nombreCliente[20];
    char sexo;
    int isEmpty;
}eCliente;

///TIPOS
int tiposInit(eTipo lista[],int tam);
void mostrarTipo(eTipo tipo);
int mostrarTipos(eTipo* tipos,int tam);
///COLORES
int coloresInit(eColor lista[],int tam);
void mostrarColor(eColor color);
int mostrarColores(eColor * colores,int tam);
///MASCOTAS

///SERVICIOS
int serviciosInit(eServicio lista[],int tam);
void mostrarServicio(eServicio servicio);
int mostrarServicios(eServicio* servicios,int tam);

///TRABAJOS
int altaTrabajo(eMascota mascotas[],eServicio servicios[],eTrabajo trabajos[],eTipo tipos[],eColor colores[],eCliente clientes[],
                int clientesTam,int mascotastam,int serviciosTam,int trabajosTam,int tiposYcoloresTam,int* idTrabajoActual);
int mostrarTrabajos(eTrabajo trabajos[],eMascota mascotas[],eServicio servicios[],int trabajosTam,int mascotasTam,int serviciosTam);
int buscarSiIdExiste(eMascota mascotas[],int tam,int idBuscado);
#endif // ENTIDADES_H_INCLUDED
