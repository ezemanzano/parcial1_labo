/*
 * cliente.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ezemanzano
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define SIZE_NOMBRE 50
#define SIZE_CUIT 20
#define TRUE 1
#define FALSE 0

typedef struct {
	char nombre[SIZE_NOMBRE];
	char apellido[SIZE_NOMBRE];
	char cuit[SIZE_CUIT];
	int isEmpty;
	int id;
	} Cliente;

	int cliente_init(Cliente * pArrayClientes, int limite);

	int cliente_alta (Cliente * pArrayClientes, int limite);
	int cliente_imprimir (Cliente * pArrayClientes , int limite);
	int cliente_baja (Cliente * pArrays, int limite, int * idClienteBaja);
	int cliente_modificar (Cliente * pArrayClientes, int limite);

	int cliente_imprimirPorIndice (Cliente * pArrays , int limite, int indice);
	int cliente_imprimirPrecioPorIndice (Cliente * pArrays , int limite, int indice) ;
	int cliente_informacionCliente(Cliente * pArrayCliente, int limiteCliente, int idCliente);

	int cliente_buscarLibre (Cliente * pArrayClientes, int limite);
	int cliente_buscarLibreRef (Cliente * pArrayClientes, int limite, int * pIndice);
	int cliente_buscarIndicePorIdRef (Cliente * pArrays, int limite,int idBuscar,int * pIndice);
	int cliente_buscarIndicePorId (Cliente * pArrays, int limite,int idBuscar);

	int cliente_altaForzada(Cliente * pArray, int limite , char * nombre, char * apellido, char * cuit);
	int cliente_sePuedeSeguir(Cliente * pArrayCliente, int limiteCliente);
	int cliente_noSeRepiteCuit(Cliente * pArrayCliente, int limiteCliente, char * cuitIngresado);

#endif /* CLIENTE_H_ */
