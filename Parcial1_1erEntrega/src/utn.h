/*
 * utn.h
 *
 *  Created on: Sep 10, 2020
 *      Author: ezemanzano
 */

#ifndef UTN_H_
#define UTN_H_
#include "cliente.h"
#include "publicacion.h"
int utn_getNumero (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos);
int utn_getNombre (char * pResultado, int len, char * mensaje, char * mensajeError, int intentos);
int utn_getFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int intentos);
int utn_getCuit (char * pResultado, int len, char *mensaje, char* mensajeError, int intentos);
int utn_getString (char * pResultado, int len, char *mensaje, char* mensajeError, int intentos);
void utn_menuPrincipal (Publicacion * pArrayPublicacion , int limitePubli , Cliente * pArrayCliente , int limiteCliente);
//void utn_subMenu(Publicacion * pArrayPublicacion , int limitePubli , Cliente * pArrayCliente , int limiteCliente);

#endif /* UTN_H_ */
