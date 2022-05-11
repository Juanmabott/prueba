#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 50
#define LLENO 1
#define VACIO 0


typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;
typedef struct
{
    int idTipo;
    char descripcion[20];
}eTipo;
typedef struct
{

    int idTipo;
    char nombreColor[20];
}eColor;
typedef struct
{

    int idMascota;
    char nombreMascota[51];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int isEmpty;
    eFecha fecha;

}eMascota;
typedef struct
{
    int idServicio;
    char descripcion[25];
    float precio;

}eServicio;
typedef struct
{
    int idTrabajo;
    int idMascota;
    int idServicio;
    eFecha fecha;

}eTrabajo;

eFecha pedirFecha(eTrabajo trabajos[],int tam);
void listarTipos(eTipo tipos[],int tam);
void listarColor(eColor colores[],int tam);
int cargarTrabajo(eTrabajo trabajos[], eMascota mascotas[], int tam, eServicio servicios[], int tamServicios);
void listadoMascota(eMascota mascotas[], int tamMascotas, eColor colores[],int tamColor, eTipo tipos[],int tamTipos);
int cargarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eFecha fecha[]);
int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor);

int cargarTrabajo(eTrabajo trabajos[], eMascota mascotas[], int tam, eServicio servicios[], int tamServicios);
#endif // FUNCIONES_H_INCLUDED
