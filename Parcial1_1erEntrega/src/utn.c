/*
 * utn.c
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"



static int myGets (char* cadena, int longitud);
static int getInt (int* pResultado);
static int getFlt (float* pResultado);
static int esNumerica (char* cadena);
static int esNombre (char*cadena, int limite);
static int esCuit(char*cadena, int limite);
static int esString (char*cadena, int limite);
static void utn_subMenu(Publicacion * pArrayPublicacion , int limitePubli , Cliente * pArrayCliente , int limiteCliente);

static int myGets(char* cadena, int longitud){
	int retorno = -1; //ERROR
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strlen(bufferString) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 1; //EXITO
			}

		}

	}
	return retorno;
}
static int getInt (int* pResultado){
	int retorno = -1 ;
	char buffer[4096];
	if (myGets(buffer,sizeof(buffer)) == 1  && esNumerica(buffer)== 1){
		retorno = 0;
		*pResultado = atoi(buffer);
	}
	return retorno;
}
static int getFlt (float* pResultado){
	int retorno = -1 ;
	char buffer[4096];
	if (myGets(buffer,sizeof(buffer)) == 1  && esNumerica(buffer)== 1){
		retorno = 0;
		*pResultado = atof(buffer);
	}
	return retorno;
}

static int esNumerica(char*cadena){
	int retorno = 1 ;
	int i = 0;
	for (;cadena[i] != '\0';i++) {
		if (cadena[i] > '9' || cadena[i] < '0')
		{
				retorno = 0;
				break;
			}
	}
	return retorno;
}


int utn_getNumero (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos){

	int retorno = -1;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
		*pResultado = bufferInt;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}

int utn_getFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int intentos){

	int retorno = -1;
	float bufferFloat;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		if (getFlt(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
		{
		*pResultado = bufferFloat;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}


int utn_getNombre (char * pResultado, int len, char *mensaje, char* mensajeError, int intentos){
	int retorno = -1 ;
	char buffer[4096];
	if (pResultado != NULL && len>0 && mensaje != NULL && mensajeError != NULL  && intentos>=0) {
		do {
			printf("%s\n", mensaje);
			if ( myGets(buffer,sizeof(buffer)) && esNombre(buffer,len) )
			{
				retorno = 0;
				strncpy(pResultado,buffer,len);
				break;
			}
			else
			{
			printf("%s \n", mensajeError);
			intentos--;
			}
		} while (intentos >= 0 );

		}



	return retorno;
}

static int esNombre (char*cadena, int limite) {
	int retorno = 1;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++){
		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno = 0;
			break;
		}}
	return retorno;
}

int utn_getCuit (char * pResultado, int len, char *mensaje, char* mensajeError, int intentos){
	int retorno = -1 ;
	char buffer[4096];
	if (pResultado != NULL && len>0 && mensaje != NULL && mensajeError != NULL  && intentos>=0) {
		do {
			printf("%s\n", mensaje);
			if ( myGets(buffer,sizeof(buffer)) && esCuit(buffer,len) )
			{
				retorno = 0;
				strncpy(pResultado,buffer,len);
				break;
			}
			else
			{
			printf("%s \n", mensajeError);
			intentos--;
			}
		} while (intentos >= 0 );

		}



	return retorno;
}

static int esCuit(char*cadena, int limite) {
	int retorno = 1;
	int contador = 0;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++)
	{
		if	(cadena[i]< '0' || cadena[i] > '9')
		{
			if (cadena[i] == '-')
			{
				contador++;
				if (contador>2)
				{
					retorno = 0;
					break;
				}

			}
			else
			{
				retorno = 0;
				break;
			}


		}
	}
	return retorno;
}

int utn_getString (char * pResultado, int len, char *mensaje, char* mensajeError, int intentos){
	int retorno = -1 ;
	char buffer[4096];
	if (pResultado != NULL && len>0 && mensaje != NULL && mensajeError != NULL  && intentos>=0) {
		do {
			printf("%s\n", mensaje);
			if ( myGets(buffer,sizeof(buffer)) && esString(buffer,len) )
			{
				retorno = 0;
				strncpy(pResultado,buffer,len);
				break;
			}
			else
			{
			printf("%s \n", mensajeError);
			intentos--;
			}
		} while (intentos >= 0 );

		}



	return retorno;
}

static int esString (char*cadena, int limite) {
	int retorno = 1;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++){
		if	((cadena[i] < 'a' || cadena[i] > 'z') &&
			(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] <'0' || cadena[i]>'9')&&
			cadena[i]!=' ')
		{
			retorno = 0;
			break;
		}}
	return retorno;
}

void utn_menuPrincipal (Publicacion * pArrayPublicacion , int limitePubli , Cliente * pArrayCliente , int limiteCliente){

	int opcion;
	do {
		if (utn_getNumero(&opcion,"\n -----Menu ----- \n 1) Alta Clinte \n 2) Modificar Cliente\n 3) Baja Cliente "
				"\n 4) Alta Publicacion \n 5) Pausar Publicacion \n 6) Renuadar Publicacion "
				"\n 7) Imprimir Clientes... \n 8) Informes \n 9) Salir \n ", "Error", 1, 9, 2) == 0)
		{
			switch(opcion)
			{
			case 1:
				cliente_alta(pArrayCliente, limiteCliente);
				break;
			case 2:
				if (cliente_sePuedeSeguir(pArrayCliente, limiteCliente) ==1)
				{
					cliente_modificar(pArrayCliente,limiteCliente);
				}
				else
				{
					printf("No hay clientes para modificar, por favor ingrese uno.");
				}
				break;
			case 3:
				if (cliente_sePuedeSeguir(pArrayCliente, limiteCliente) ==1)
				{
					publicacion_bajaClienteYPublicaciones(pArrayPublicacion, limitePubli, pArrayCliente, limiteCliente);
				}
				else
				{
					printf("No hay clientes para dar de baja, por favor ingrese uno.");
				}
				break;
			case 4 :
				if (cliente_sePuedeSeguir(pArrayCliente, limiteCliente) == 1)
				{
					publicacion_alta(pArrayPublicacion, limitePubli, pArrayCliente, limiteCliente);
				}
				else
				{
					printf("No hay clientes para asignarle una publicacion, por favor ingrese uno.");
				}
				break;
			case 5:
				publicacion_pausar(pArrayPublicacion, limitePubli, pArrayCliente, limiteCliente);
				break;
			case 6:
				publicacion_reanudar(pArrayPublicacion, limitePubli, pArrayCliente, limiteCliente);
				break;
			case 7:
				if (cliente_sePuedeSeguir(pArrayCliente, limiteCliente) ==1)
				{
					publicacion_listaClientes(pArrayCliente,limiteCliente,pArrayPublicacion,limitePubli);
				}
				else
				{
					printf("No hay clientes para mostrar, por favor ingrese uno.");
				}
				break;
			case 8:
				utn_subMenu(pArrayPublicacion, limitePubli, pArrayCliente, limiteCliente);
				break;
			}

		}

	}while (opcion!=9);


}




static void utn_subMenu(Publicacion * pArrayPublicacion , int limitePubli , Cliente * pArrayCliente , int limiteCliente){
	int opcion;
	do{
		utn_getNumero(&opcion, "\n 1) Cliente con mas avisos"
								"\n 2) Cantidad de avisos pausados"
								"\n 3) Rubro con mas avisos"
								"\n 4) Volver al menu anterior", "\n Error", 1, 4, 2);
		switch (opcion)
		{
		case 1:
			publicacion_clienteConMasAvisos(pArrayPublicacion, limitePubli, pArrayCliente, limiteCliente);
			break;
		case 2:
			publicacion_cantidadPausados(pArrayPublicacion, limitePubli);
			break;
		case 3:
			publicacion_rubroConMasAvisos(pArrayPublicacion, limitePubli);
			break;

		}
	} while(opcion!=4);

}

