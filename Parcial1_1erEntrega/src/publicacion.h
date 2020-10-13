/*
 * publicacion.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ezemanzano
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#define SIZE_AVISO 64
#define TRUE 1
#define FALSE 0
#define PUBLICACION_ACTIVA 1
#define PUBLICACION_PAUSADA 0
#define MIN_RUBRO 1
#define MAX_RUBRO 10
#include "cliente.h"

	typedef struct {
		int idCliente;
		int rubro;
		char aviso[SIZE_AVISO];
		int estado;
		int isEmpty;
		int id;
		} Publicacion;

	int publicacion_init(Publicacion * pArrayPublicacions, int limite);
	int publicacion_sePuedeSeguir(Publicacion * pArrayPubli , int limitePubli);

	int publicacion_alta (Publicacion * pArrayPublicacions, int limite, Cliente * pArrayCliente , int limiteCliente);
	int publicacion_baja (Publicacion * pArrayPubli, int limite, int idCliente);
	int publicacion_bajaClienteYPublicaciones(Publicacion * pArrayPubli, int limitePublic,Cliente * pArrayCliente, int limiteCliente);

	int publicacion_imprimirTodas(Publicacion * pArrayPublicacions , int limite , Cliente * pArrayCliente , int limiteCliente);
	int publicacion_imprimirActivas (Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente);
	int publicacion_imprimirPausadas(Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente);


	int publicacion_pausar (Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente, int limiteCliente);
	int publicacion_reanudar (Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente, int limiteCliente);

	void publicacion_listarPublicacionesDeCliente( Publicacion * pArrayPublic, int limitePubli , int idCliente);
	int publicacion_clienteConMasAvisos(Publicacion * pArrayPubli, int limitePubli,Cliente * pArrayCliente, int limiteCliente);
	int publicacion_cantidadPausados (Publicacion * pArrayPubli, int limitePubli);
	int publicacion_rubroConMasAvisos (Publicacion * pArrayPubli, int limitePubli);
	int publicacion_cantidadPublicPorIdCliente(Publicacion * pArrayPublic, int limitePubli, int idCliente, int *resContador);
	int publicacion_listaClientes (Cliente * pArrayCliente, int limiteClientes, Publicacion * pArrayPublic, int limitePubli);
	int publicacion_informacionCliente(Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente, int limiteCliente, int idCliente);

	int publicacion_buscarLibre (Publicacion * pArrayPublicacions, int limite);
	int publicacion_buscarLibreRef (Publicacion * pArrayPublicacions, int limite, int * pIndice);
	int publicacion_buscarIndicePorId (Publicacion * pArrays, int limite,int idBuscar,int * pIndice);
	int publicacion_buscarIndicePorIdPausadas (Publicacion * pArrayPubli, int limite,int idBuscar,int * pIndice);
	int publicacion_buscarIndicePorIdActivas(Publicacion * pArrayPubli, int limite,int idBuscar,int * pIndice);

	int publicacion_altaForzada(Publicacion * pArray, int limite ,int idCliente,int rubro,  char * aviso);

#endif /* PUBLICACION_H_ */
