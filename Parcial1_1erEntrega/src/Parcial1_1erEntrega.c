#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "publicacion.h"

#define CLIENTE_QTY 100
#define PUBLICACION_QTY 1000

int main(void) {
	Cliente pArrayCliente[CLIENTE_QTY];
	Publicacion pArrayPublicacion[PUBLICACION_QTY];

	cliente_init(pArrayCliente,CLIENTE_QTY);
	publicacion_init(pArrayPublicacion, PUBLICACION_QTY);
/*
	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Ezequiel","Manzano","20-39626870-9");
	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Sofia","Gonzalez","20-25626870-9");
	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Martina","Dirago","20-52623270-9");
	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Alicia","Finella","20-18604225-9");
	cliente_altaForzada(pArrayCliente, CLIENTE_QTY,"Claudio","Manzano","20-17409871-9");

	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,2,3,"Vendo clio 2010");
	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,3,3,"Vendo fitito nunca taxi 2010");
	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,1,2,"Vendo heladera samsung");
	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,1,1,"QEPD EZEQUIEL MANZANO - Siempre en nuestros corazones");
	publicacion_altaForzada(pArrayPublicacion,PUBLICACION_QTY,5,5,"Se alquila casa en canning super barata 100000 usd");
*/
	utn_menuPrincipal(pArrayPublicacion, PUBLICACION_QTY, pArrayCliente, CLIENTE_QTY);

}


