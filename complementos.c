#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define LLENO 1
#define VACIO 0
static int idIncrementalMascotas = 1000;
static int obtenerIDMascotas()
{
    return idIncrementalMascotas++;
}
static int idIncrementalTrabajo = 100;
static int obtenerIDTrabajo()
{
    return idIncrementalTrabajo++;
}

int BuscaLibre(eMascota mascotas[],int tam)
{
    int index;
    index = -1;
    for(int i=0;i<tam;i++)
    {
        if(mascotas[i].isEmpty == VACIO)
        {
            index=i;
            break;
        }
    }
    return index;
}
int IniciarMascotas(eMascota mascotas[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        mascotas[i].isEmpty=VACIO;
    }
    return 0;
}

int cargarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eFecha fecha[])
{
    int index;
    int todoOk = 0;

    if(mascotas != NULL && tam > 0)
    {


            index=BuscaLibre(mascotas, tam);
            if(index!=-1 )
            {
            mascotas[index].idMascota=obtenerIDMascotas();
            printf("Ingrese el nombre de la mascota: ");
            fflush(stdin);
            scanf("%s", &mascotas[index].nombreMascota);
            listarTipos(tipos, tamTipos);
            printf("ingrese el id del tipo de su mascota");
            fflush(stdin);
            scanf("%d", &mascotas[index].idTipo);
            listarColor(colores,tamColor);
            printf("ingrese el id del color de su mascota");
            scanf("%d", &mascotas[index].idColor);
            printf("ingrese la edad");
            scanf("%d", &mascotas[index].edad);
            printf("ingrese si su mascota esta vacuanda (s o n)");
            scanf("%c",&mascotas[index].vacunado);
            mascotas[index].isEmpty=LLENO;


        todoOk = 1;
    }
    }
}
int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    int opcion;
    int index;

    printf("ingrese el ID de la mascota que desea modificar:");
    scanf("%d", index);
    printf("1.nombre");
    printf("2.id tipo de mascota");
    printf("3.id de color");
    printf("4.Edad de la mascota");
    printf("5.Vacuna de la mascota( si tiene o no)");

    printf("**** Modificar mascota****");
    do
    {
      switch(opcion)
    {
    case 1:
        printf("ingrese nuevo nombre");
        scanf("s",&mascotas[index].nombreMascota);
        break;
    case 2:
        printf("ingrese nuevo id de la mascota");
        scanf("%d",&mascotas[index].idTipo);
        break;
    case 3:
        printf("ingrese nuevo id del color");
        scanf("%d", &mascotas[index].idColor);
        break;
        case 4:
        printf("ingrese la edad");
        scanf("%d", &mascotas[index].edad);
        break;
        case 5:
        printf("ingrese si posee  vacuna o no (s o n)");
        scanf("%c",mascotas[index].vacunado);
        break;
    }

    }while(opcion!=6);
}



int BuscarMascotaXId(eMascota mascotas[], int tam,int id)
{
    int index;
    index = -1;
    for(int i=0;i<tam;i++)
    {
        if(mascotas[i].idMascota == id&&mascotas[i].isEmpty==LLENO)
        {
            index=i;
            break;
        }
    }
    return index;
}
int CancelarMascota(eMascota mascotas[], int tam,int id)
{
    int retorno;
    int opcion;
    char seguir;
    retorno = -1;
    seguir ='s';

    while(seguir=='s')
    {
        printf("Seguro que desea cancelar la reserva de la mascota?\n1. SI\n2. NO\n");
        opcion=PedirEntero("Elija una opcion: \n");
        switch(opcion)
        {
            case 1:
                for(int i=0;i<tam;i++)
                {
                    if(mascotas[i].idMascota == id&&mascotas[i].isEmpty==LLENO)
                    {
                        mascotas[i].isEmpty=VACIO;
                        retorno = 1;
                        break;
                    }
                }
                seguir = 'n';
            break;
            case 2:
                    printf("saliendo..\n");
                    seguir = 'n';
            break;
            default:
                    printf("opcion incorrecta!\n");
            break;
        }
    }
    return retorno;
}

void listarTipos(eTipo tipos[],int tam)
{
    printf("ID      TIPO");
    for(int i=0;i<tam;i++)
    {
       printf("%d   %s",tipos[i].idTipo,tipos[i].descripcion);

    }
}



    void listarColor(eColor colores[],int tam)
    {
        printf("ID      Color");
        for(int i=0;i<tam;i++)
        {
            printf("%d   %s",colores[i].idTipo,
                            colores[i].nombreColor);

        }
    }
void listadoMascota(eMascota mascotas[], int tamMascotas, eColor colores[],int tamColor, eTipo tipos[],int tamTipos);
{
        int indexTipo;
        int indexColor;
        indexColor=listarColorMascota(mascotas,colores,tamColor);
        indexTipo=listarTiposMascotas(mascotas,tipos,tamTipos);
        printf("ID      Mascota     EDAD    COLOR   TIPO    VACUNACION(S/N)");
        for(int i=0;i<tam;i++)
        {

           printf("%d   %s  %d %s  %s  %c ",mascotas[i].idMascota,
                  mascotas[i].nombreMascota,
                  mascotas[i].edad,
                  colores[indexColor].nombreColor,
                  tipos[indexTipo].descripcion,
                  mascotas[i].vacunado);
        }
}
int ListarColorMascota(eMascota mascotas,eColor colores[],int tamColor)
{
    int index;
    for(int i=0;i<tamColor;i++)
    {
        if(mascotas.idColor==colores[i].idTipo)
        {
            index=i;
            break;
        }
    }
    return index;
}
int ListarTipoMascota(eMascota mascotas,eTipo tipos[],int tamTipos)
{
    int index;
    for(int i=0;i<tamTipos;i++)
    {
        if(mascotas.idTipo==tipos[i].idTipo)
        {
            index=i;
            break;
        }
    }
    return index;
}
int ordenarMascotasTipoYNombre(eMascota mascotas[], int tam)
{
    int todoOk = 0;
    eMascota auxiliar;
    if(mascotas != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(strcmp(mascotas[i].nombreMascota,mascotas[j].nombreMascota)>0)
                {
                    auxiliar=mascotas[i];
                    mascotas[i]=mascotas[j];
                    mascotas[i]=auxiliar;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarTrabajo(eTrabajo trabajos[], eMascota mascotas[], int tam, eServicio servicios[], int tamServicios)
{

    int todoOk = 0;

    if(trabajos != NULL && tam > 0)
    {
        for(int i=0;i<tam;i++)
        {
            trabajos[i].idTrabajo=obtenerIDTrabajo();
            printf("elija Mascota");
            scanf("%d",&trabajos[i].idMascota);
            printf("elija servicio");
            scanf("%d",&trabajos[i].idServicio);
            trabajos[i].fecha=pedirFecha(trabajos,tam);


        }
        todoOk = 1;
    }
}

eFecha pedirFecha(eTrabajo trabajos[],int tam)
{
    eFecha fechas;
    eFecha aux;

    printf("\n   Introduzca d%ca: ", 161 );
    scanf("%d", &aux.dia );
    printf("\n   Introduzca mes: " );
    scanf("%d", &aux.mes );
    printf("\n   Introduzca a%co: ", 164 );
    scanf("%d", &aux.anio );

    if (aux.mes >= 1 && aux.mes <= 12 )
    {
        switch (aux.mes)
        {
            case  1:
            case  3:
            case  5:
            case  7:
            case  8:
            case 10:
            case 12:
            	if(aux.dia >= 1 && aux.dia <= 31)
            	{
            		printf("\n   FECHA CORRECTA" );
            		fechas.dia = aux.dia;
            		fechas.mes = aux.mes;
            		fechas.anio = aux.anio;
            	}
            	else
            	{
            		printf("\n   FECHA INCORRECTA" );
            	}
            	break;
            case  4:
            case  6:
            case  9:
            case 11:
            	if (aux.dia >= 1 && aux.dia <= 30 )
            	{
            		printf("\n   FECHA CORRECTA" );
            		fechas.dia = aux.dia;
            		fechas.mes = aux.mes;
            		fechas.anio = aux.anio;
            	}
            	else
            	{
            		printf("\n   FECHA INCORRECTA" );
            	}
            	break;

            case  2:
            	if((aux.anio % 4 == 0 && aux.anio % 100 != 0) || (aux.anio % 400 == 0))
            	{
            		if (aux.dia >= 1 && aux.dia <= 29 )
            		{
            			printf("\n   FECHA CORRECTA" );
            		fechas.dia = aux.dia;
            		fechas.mes = aux.mes;
            		fechas.anio = aux.anio;
            		}
            		else
            		{
            			printf("\n   FECHA INCORRECTA" );
            		}
            	}
            	else
            	{
					if (aux.dia >= 1 && aux.dia <= 28 )
					{
						printf("\n   FECHA CORRECTA" );
            		fechas.dia = aux.dia;
            		fechas.mes = aux.mes;
            		fechas.anio = aux.anio;
					}
					else
					{
						printf("\n   FECHA INCORRECTA" );
					}
				}
        }
    }
return fechas;
}


