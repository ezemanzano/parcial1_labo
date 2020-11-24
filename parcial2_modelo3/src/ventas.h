/*
 * ventas.h
 *
 *  Created on: Nov 22, 2020
 *      Author: ezemanzano
 */

#ifndef VENTAS_H_
#define VENTAS_H_


typedef struct
{
	int idVenta;
	int idCliente;
	int cantidadAfiches;
	char nombreDelArchivo[128];
	int zona;
	int estadoVenta;

}Ventas;

Ventas* ventas_new(void);
Ventas* ventas_newParam(int idVenta,int idCliente, int cantidadAfiches, char* nombreDelArchivo, int zona, int estadoVenta);

int ventas_setIdVenta(Ventas* this, int idVenta);
int ventas_setIdCliente(Ventas* this, int idCliente);
int ventas_setCantidadAfiches(Ventas* this, int cantidadAfiches);
int ventas_setNombreDelArchivo(Ventas* this, char* nombreDelArchivo);
int ventas_setZona(Ventas* this, int zona);
int ventas_setEstadoVenta(Ventas* this, int estadoVenta);


int ventas_getIdVenta(Ventas* this, int * idVenta);
int ventas_getIdCliente(Ventas* this, int * idCliente);
int ventas_getCantidadAfiches(Ventas* this, int * cantidadAfiches);
int  ventas_getNombreDelArchivo(Ventas* this, char * nombreDelArchivo);
int ventas_getZona(Ventas* this , int * zona);
int ventas_getEstadoVenta(Ventas* this, int *estadoVenta);


int ventas_idExiste (LinkedList * pArrayListVentas, int idVenta);
int ventas_findMaxAfiches (LinkedList * pArrayListVentas);

int ventas_imprimirTodos(void*thisA);
int ventas_imprimirACobrar(void*thisA);
int ventas_imprimirCobradas(void*thisA);
int ventas_findbyId(void*thisA,int indice);
int ventas_filtrarPorCobradas(void*thisA, int Cobradas);

int ventas_printOne(void*thisA, int idVenta);
int ventas_cobradasPorCliente(void* thisA, int idCliente);
int ventas_aCobrarPorCliente(void* thisA, int idCliente);

#endif /* VENTAS_H_ */
