/*
 * cliente.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */
#include "cliente.h"

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "publicacion.h"
static int cliente_generarNuevoId (void);

/**
 * \brief Inicializa el array de clientes
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
  * \return (-1) Error / (0) Ok
 *
 */

int cliente_init(Cliente * pArrays, int limite){
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrays[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief Da de alta un clinete pidiendole los datos al usuario.-
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
  */

int cliente_alta (Cliente * pArrays, int limite)
{
	int retorno = -1;
	int indice;

	Cliente bufferCliente;
	if (pArrays != NULL && limite >0)
	{
		if (cliente_buscarLibreRef (pArrays, limite, &indice) == 0)
		{
				if (utn_getNombre(bufferCliente.nombre,SIZE_NOMBRE , "\n Nombre?", "\n ERROR",2) == 0 &&
					utn_getNombre(bufferCliente.apellido, SIZE_NOMBRE, " \n Apellido?","\n ERROR",3) == 0 &&
					utn_getCuit(bufferCliente.cuit, SIZE_CUIT,"\n Cuit?","\n ERROR",3) == 0 )
				{
						pArrays[indice] = bufferCliente;
						pArrays[indice].id = cliente_generarNuevoId();
						pArrays[indice].isEmpty = FALSE;
						retorno = 0;
						printf("\n SUCCESS - Nuevo cliente OK");
				} else
					{
						printf("horror");
					}
			} else
			{
				printf(" \n No quedan espacios libres");
			}
		}
		return retorno ;
}

/**
 * \brief Imprime los clientes con su respectivos datos
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
  */
int cliente_imprimir (Cliente * pArrays , int limite) {
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
			printf("\nNombre: %s - Apellido: %s - Cuit %s - ID %d",pArrays[i].nombre,pArrays[i].apellido, pArrays[i].cuit, pArrays[i].id);
			}
		}
		retorno = 0;
	}
return retorno;
}
/**
 * \brief Modifica un clinete pidiendole los datos al usuario.-
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
  */

int cliente_modificar (Cliente * pArrays, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar = -1;
	Cliente bufferCliente;

	if (pArrays != NULL && limite>0)
	{
		cliente_imprimir(pArrays, limite);

		if(utn_getNumero(&idBuscar,"\n --- Ingrese ID del cliente a modificar ----:","\n ERROR!",0,9999,2)==0)
		{


			if(cliente_buscarIndicePorIdRef(pArrays, limite,idBuscar,&indiceAModificar) == 0)
			{
				bufferCliente = pArrays[indiceAModificar]; // IMPORTANTE!

				if (utn_getNombre(bufferCliente.nombre, SIZE_NOMBRE ,"\n Nuevo nombre?", "\n ERROR",2) == 0 &&
					utn_getNombre(bufferCliente.apellido, SIZE_NOMBRE, " \n Ingrese nuevo apellido","ERROR",3) == 0 &&
					utn_getCuit(bufferCliente.cuit, SIZE_CUIT, "nuevo Cuit?", "\n ERROR", 2)==0)
					{
						pArrays[indiceAModificar] = bufferCliente; // COPIAMOS AL ARRAY
						printf("\n Cliente Modificado.");
						retorno = 0;
					}
				}
			else
			{
				printf("\n No se encontrò un cliente con ese id. Vuelva a intentar");
			}
			}
		}
	return retorno;
}

/**
 * \brief Busca una posicion vacìa en el array de clientes.
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
  */

int cliente_buscarLibre (Cliente * pArrays, int limite){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0){
			for ( i = 0; i<limite; i++) {
				if(pArrays[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int cliente_buscarLibreRef (Cliente * pArrays, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArrays[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}

static int cliente_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int cliente_buscarIndicePorIdRef (Cliente * pArrays, int limite,int idBuscar, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE &&
					   pArrays[i].id == idBuscar)
					{
					*pIndice= i;
					retorno = 0;
					break;
					}
				}
		}
		else
		{
			printf("\n ERROR");
		}
	return retorno;
}

/**
 * \brief Busca el indice del cliente en el array de clientes en base al ID
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
* \param int idBuscar, es el id de cliente a buscarle el indice.
 * \return (-1) Error / (0) Ok
  */

int cliente_buscarIndicePorId (Cliente * pArrays, int limite,int idBuscar){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].isEmpty == FALSE &&
					   pArrays[i].id == idBuscar)
					{
					retorno = i;
					break;
					}
				}
		}
		else
		{
			printf("\n ERROR");
		}
	return retorno;
}

/**
 * \brief Imprime la informacion del cliente
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \param int idCliente -> se da por parametro el id del cliente a imprimir
 * \return (-1) Error / (0) Ok
 *
 */


int cliente_informacionCliente(Cliente * pArrayCliente, int limiteCliente, int idCliente){

	int retorno = 0;
	int indice;
	if (pArrayCliente!= NULL && limiteCliente>0 && idCliente>0)
	{
		cliente_buscarIndicePorIdRef (pArrayCliente, limiteCliente,idCliente,&indice);
		printf("\n Nombre: %s - Apellido: %s - Cuit: %s ",pArrayCliente[indice].nombre,pArrayCliente[indice].apellido,pArrayCliente[indice].cuit);
	}
	else
	{
		printf("\n ERROR");
	}

	return retorno;
}
/**
 * \brief Hardcode de un clinete
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limite, es el tamaño de array de clientes
 * \param char * nombre, nombre a guardar
 * \param char * apellido, apellido a guardar
 * \param char * cuit, cuit a guardar
 * \return (-1) Error / (0) Ok
  */

int cliente_altaForzada(Cliente * pArray, int limite , char * nombre, char * apellido, char * cuit){

	int retorno = -1;
	int indice;
	if (cliente_buscarLibreRef(pArray,limite, &indice) == 0)
	{
		strncpy(pArray[indice].nombre,nombre,SIZE_NOMBRE);
		strncpy(pArray[indice].apellido,apellido,SIZE_NOMBRE);
		strncpy(pArray[indice].cuit,cuit,SIZE_NOMBRE);
		pArray[indice].id = cliente_generarNuevoId();
		pArray[indice].isEmpty = FALSE;
		retorno = 0;
	}
	else
	{
		printf("\n Error - No quedan libres");
	}
	return retorno;
}

/**
 * \brief Chequea si hay algun cliente de alta para poder continuar
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (1) Si lo hay
 *
 */

int cliente_sePuedeSeguir(Cliente * pArrayCliente, int limiteCliente){
	int retorno = -1;
	if (pArrayCliente!=NULL && limiteCliente>0)
	{
		for (int i = 0; i<limiteCliente;i++)
		{
			if (pArrayCliente[i].isEmpty == FALSE)
			{
				retorno=1;
				break;
			}
		}
	}
return retorno;
}

