/*
 * inputs.c
 *
 *  Created on: 13 may. 2021
 *      Author: Isaac
 */

#include "inputs.h"
#include <stdio.h>

 int pedirNumeroEntero(int* pResultado, char mensaje[], char mensajeError[], int minimo,int maximo,int reintentos)
{
    int retorno=-1;
    int bufferInt;

    do
    {
        printf("%s", mensaje);
        scanf("%d",&bufferInt);
        if(bufferInt<=maximo&&bufferInt>=minimo)
        {
            *pResultado=bufferInt;
            retorno=0;
            break;
        }
        printf("%s",mensajeError);
        reintentos --;


    }while(reintentos==0);

    return retorno;


}

