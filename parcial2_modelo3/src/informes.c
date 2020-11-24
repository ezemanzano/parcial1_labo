/*
 * informes.c
 *
 *  Created on: Nov 24, 2020
 *      Author: ezemanzano
 */



/** \brief Busca el cliente con màs afiches cargados.-
 * * \param pArrayListVentas LinkedList* puntero al array
 * \param pArrayListClientes LinkedList* puntero al array
 * \return int -1 error - 0 ok
 *
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cliente.h"
#include "ventas.h"
#include "parser.h"
#include "utn.h"
#include "controller.h"
#include "informes.h"

/** \brief Encuentra el cliente con mas afiches y lo imprime por consola
 *
 * \param LinkedList* pArrayListClientes puntero al array de clientes
 * \param LinkedList* pArrayListVentas puntero al array de ventas
 * \return int (0) ok  / -1 ERROR
 *
 */

int informes_findClienteConMasAfiches(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes)
{
	int retorno=-1;
	Ventas * ventasAux;
	int indice;
	int idClienteAux;
	if (pArrayListClientes!=NULL && pArrayListVentas!=NULL)
	{
		indice = ventas_findMaxAfiches(pArrayListVentas);
		if (indice>=0)
		{
			ventasAux = ll_get(pArrayListVentas, indice);
			if (ventasAux!=NULL)
			{
				ll_mapAndBreak(pArrayListVentas,ventas_printOne, indice+1);
				ventas_getIdCliente(ventasAux, &idClienteAux);
				printf("\n Datos del Cliente");
				ll_mapAndBreak(pArrayListClientes, cliente_printOne, idClienteAux);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Encuentra el cliente con mas ventas cobradas y lo imprime por consola
 *
 * \param LinkedList* pArrayListClientes puntero al array de clientes
 * \param LinkedList* pArrayListVentas puntero al array de ventas
 * \return int (0) ok - (-1) ERROR
 *
 */

int informes_encontrarClienteConMasVentas (LinkedList*pArrayListVentas,LinkedList*pArrayListClientes)
{
	int retorno = -1;
	int indice;
	int idClienteAux;
	if (pArrayListClientes!=NULL && pArrayListVentas!=NULL)
	{
		indice =informes_encontrarMayorOMenor(pArrayListVentas,pArrayListClientes,0);
		Ventas * ventaAux = ll_get(pArrayListVentas, indice);
		ventas_getIdCliente(ventaAux, &idClienteAux);
		ll_mapAndBreak(pArrayListClientes,cliente_printOne,idClienteAux);
	}
return retorno;
}

/** \brief Encuentra el cliente con mas ventas cobradas y lo imprime por consola
 *
 * \param LinkedList* pArrayListClientes puntero al array de clientes
 * \param LinkedList* pArrayListVentas puntero al array de ventas
 * \return int (0) ok - (-1) ERROR
 *
 */

int informes_encontrarClienteConMenosVentas (LinkedList*pArrayListVentas,LinkedList*pArrayListClientes)
{
	int retorno = -1;
	int indice;
	int idClienteAux;
	indice =informes_encontrarMayorOMenor(pArrayListVentas,pArrayListClientes,1);
	Ventas * ventaAux = ll_get(pArrayListVentas, indice);
	ventas_getIdCliente(ventaAux, &idClienteAux);
	ll_mapAndBreak(pArrayListClientes,cliente_printOne,idClienteAux);
	return retorno;
}


/** \brief Encuentra el cliente con mas o menos ventas cobradas y devuele su indice por retorno
 *
 * \param LinkedList* pArrayListClientes puntero al array de clientes
 * \param LinkedList* pArrayListVentas puntero al array de ventas
 *\ param int mayor (0) si desea encontrar el mayor (1) si desea encontrar el menor
 * \return int (>0) ok e indice de la venta - (-1) ERROR
 *
 */

int informes_encontrarMayorOMenor(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes,int mayor){
	Ventas* ventasAux;

	int retorno =-1;
	int idClienteAux;
	int cantidadAfiches;
	int mayorAfiches;
	for (int i = 0; i<ll_len(pArrayListVentas); i++)
	{
		ventasAux = ll_get(pArrayListVentas, i);
		ventas_getIdCliente(ventasAux, &idClienteAux);
		ll_reduceIntbyID(pArrayListVentas, informes_cantidadAfichesporId, &cantidadAfiches, idClienteAux);
		if (mayor == 0)
		{
			if (i==0 ||  (cantidadAfiches!=0 && mayorAfiches < cantidadAfiches) )
			{
				mayorAfiches = cantidadAfiches;
				retorno = i;
			}
		}
		else
		{
			if (i==0 ||  (cantidadAfiches!=0 && mayorAfiches > cantidadAfiches) )
		{
			mayorAfiches = cantidadAfiches;
			retorno = i;
		}

		}
	}
	 printf("La cantidad de afiches es:%d \n Y pertence al cliente...",mayorAfiches);
	return retorno;
}

/** \brief Encuentra la cantidad de afiches por id de cliente que se le pasa por parametro
 *
 * \param void* pElemento -> puntero void a elemento para fn criterio
 * \param int id -> idCliente a buscar la cantidad de afiches
 * \return int (>0) ok y catnidad de afiches - (-1) ERROR
 *
 */


int informes_cantidadAfichesporId(void*pElemento, int id){
	int retorno=0;
	Ventas * ventasAux=pElemento;
	int cantidadAfiches;
	int idClienteAux;
	int estado;
	ventas_getEstadoVenta(ventasAux,&estado);
	if ( estado ==1 && ventas_getIdCliente(pElemento, &idClienteAux) == 0 && idClienteAux==id)
	{
		ventas_getCantidadAfiches(ventasAux, &cantidadAfiches);
		return cantidadAfiches;
	}

return retorno;
}
