#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"





int main(void) {
    eMascota mascotas[TAM];
    eTipo tipos[]= {{1000,"Ave"},{1001,"Perro"},{1002,"Roedor"},{1003,"Gato"},{1004,"Pez"}};
    eServicio servicios[]= {{20000,"Corte",450},{20001,"Desparasitado",800},{20002,"Castrado",600}};
    eColor colores[]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Rojo"},{5003,"Gris"},{5004,"Azul"}};
    eTrabajo trabajos[TAM];
    int index;

	setbuf(stdout,NULL);


		int retorno;
		int opcion;
		for(int i=0; i<TAM; i++)
		{
			mascotas[i].isEmpty = VACIO;
		}



		do
		{
			printf("1. ALTA MASCOTA\n");
			printf("2. MODIFICAR MASCOTA\n");
			printf("3. BAJA MASCOTA\n");
			printf("4. LISTAR MASCOTA\n");
			printf("5. LISTAR TIPOS\n");
			printf("6. LISTAR COLORES\n");
			printf("7. LISTAR SERVICIOS\n");
			printf("8. ALTA TRABAJO\n");
			printf("9. LISTAR TRABAJOS\n");


			printf("10. SALIR\n");
			printf("Elija una opcion: ");
			scanf("%d", &opcion);
			switch(opcion)
			{
				case 1:
					altaMascota();
                    break;

				case 2:
					modificarMascota(mascotas,TAM,tipos,6,colores,5);
                    break;

				case 3:
				    printf("seleccione id de la mascota a cancelar");
				    fflush(stdin);
				    scanf("%d",&index);

					if((index = CancelarMascota(mascotas,TAM,index))!=-1)
                    {
                        printf("mascota cancelada con exito...\n");

                    }
                    else
                    {
                        printf("NO se ha encontrado la mascota..\n");
                    }
                    break;

				case 4:
					listadoMascota(mascotas,TAM,colores,5,tipos,6);
                    break;

				case 5:
					Listartipos(tipos,6);
                    break;

				case 6:
					listarcolores(colores,5);
                    break;
				case 7:

                    break;
                case 8:
                    cargarTrabajo(trabajos,mascotas,TAM,servicios,3);
                    break;
                case 9:
                    listarTrabajos();
                    break;
                case 10:
                    printf("saliendo...");
                default:
                    printf("opcion invalida ingrese una opcion del 1 al 10");
                    scanf("%d", &opcion);
                    break;




			}




		}while(opcion!=10);


	return 0;
}
