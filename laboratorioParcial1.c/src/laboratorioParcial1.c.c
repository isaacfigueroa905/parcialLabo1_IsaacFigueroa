/*
 ============================================================================
 Name        : c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

#define T 5
#define OCUPADO 1
#define VACIO 0



typedef struct
{
	int id;
	char descripcion[25];
	float precio;
	//int isEmpty;

}eServicio;

typedef struct
{
	int id;
	char marcaBicicleta[25] ;
	int rodadoBicicleta;
	int idServicio;
	int fecha;
	int isEmpty;

}eTrabajo;





int BuscarLibre(eTrabajo[], int);
void InicializadorTrabajos(eTrabajo [] ,int);
void MostrarServicios(eServicio[],int);
eTrabajo ingreso(eServicio[] ,int);
int main(void)
{
	setbuf(stdout,NULL);
	eTrabajo trabajito[T];
	int retornoCarga;


	int opcion;

	InicializadorTrabajos(trabajito,T);
	eServicio servicios[4]= {{20000,"limpieza",250},{20001,"parche",300},{20002,"centrado",400},{20003,"cadena",350}};

	 do
		    {
		        printf("\n\t\tMENU PRINCIPAL\n");
		        printf("\t___________________________________\n");
		        printf("\tElija una opcion:\n");
		        printf("\t1.Alta Trabajo\n");
		        printf("\t2.Modificar Trabajo\n");
		        printf("\t3.Baja Trabajo \n");
		        printf("\t4.Listar Trabajos  \n");
		        printf("\t5.Listar Servicios \n");
		        printf("\t6.Total\n");
		        printf("\t0.SALIR\n");
		        scanf("%d", &opcion);
		        printf("\n\t__________________________________\n");

		        while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6 &&opcion!=0)
		        {
		            printf("\n\t***********************************\n");
		            printf("\tError!!! ingrese una opcion valida:\n");
		            printf("\t1.Alta Trabajo\n");
		            printf("\t2.Modificar Trabajo\n");
		            printf("\t3.Baja Trabajo \n");
		            printf("\t4.Listar Trabajos  \n");
		            printf("\t5.Listar Servicios \n");
		            printf("\t6.Total\n");
		            printf("\t0.SALIR\n");


		            scanf("%d", &opcion);


		        }

		        switch(opcion)
		        {
		            case 1:
		            	printf("\n\t Alta de trabajos:\n");
		            	retornoCarga=CargarTrabajos(trabajito,T,servicios,4);
		            	if(retornoCarga!=-1)
		            	{
		            		printf("cargado exitosamente");
		            	}
		            	else
		            	{
		            		printf("no se pudo");
		            	}

		                break;

		            case 2:

		                break;
		            case 3:

		                break;

		            case 4:

		                break;

		            case 5:


		                break;

		            case 6:


		                break;

		        }
		    }while(opcion!=0);



	return EXIT_SUCCESS;
}


void InicializadorTrabajos(eTrabajo listadoTrabajos[] ,int tamT)
{
    int i;
    for(i=0; i<tamT; i++)
    {
        listadoTrabajos[i].isEmpty=VACIO;

    }
}

eTrabajo ingreso(eServicio listaServicios[],int tamS)
{
     eTrabajo unTrabajo;
     int rodado;
     int retRodado;


    printf("\n\t Carga de trabajo\n\n ");
    printf("\t ingrese Marca de bicicleta: ");
    fflush(stdin);
    scanf("%[^\n]", unTrabajo.marcaBicicleta);

    retRodado=pedirNumeroEntero(&rodado,"\n\t ingrese rodado: ","\n\t error ingrese un rodado correcto", 10,30,3);
    if(retRodado!=-1)
    {
    	unTrabajo.rodadoBicicleta=rodado;
    }

    printf("\n\t ingrese servicio a realizar: ");
    MostrarServicios( listaServicios, 4);

    printf("\n\t ingrese fecha: ");
    scanf("%d",&unTrabajo.fecha);



    unTrabajo.isEmpty=OCUPADO;


    return unTrabajo;
}


void MostrarServicios(eServicio listaServicios[],int tamS)
{
    int i;

    for(i=0;i<tamS;i++)
    {
        printf("\n\t%d %s %f \n",listaServicios[i].id,listaServicios[i].descripcion,listaServicios[i].precio);
        printf("\t_________________________________\n");
    }
}


int BuscarLibre(eTrabajo listaTrabajos[], int tamT)
{

    int index=-1;
    int i;
    for(i=0; i<tamT; i++)
    {
        if(listaTrabajos[i].isEmpty==VACIO)
        {
            index=i;
            break;
        }

    }


    return index;
}

/*
int GeneraIdTrabajo()
{
	int IdIncremental=0;

	return IdIncremental += 1;

}*/





int CargarTrabajos(eTrabajo listaTrabajos[] , int tamT, eServicio listaServicios[], int tamS)
{
  int i;


  i=BuscarLibre(listaTrabajos, tamT);

  if(i!=-1  )
  {
      listaTrabajos[i] = ingreso(listaServicios,tamS);//exito
     // listado[i].id    = GeneraId();

  }

  return i;


}

