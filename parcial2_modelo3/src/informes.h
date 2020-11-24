/*
 * informes.h
 *
 *  Created on: Nov 24, 2020
 *      Author: ezemanzano
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int informes_findClienteConMasAfiches(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes);
int informes_encontrarMayorOMenor(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes,int mayor);
int informes_encontrarClienteConMasVentas (LinkedList*pArrayListVentas,LinkedList*pArrayListClientes);
int informes_encontrarClienteConMenosVentas (LinkedList*pArrayListVentas,LinkedList*pArrayListClientes);
int informes_cantidadAfichesporId(void*pElemento, int id);

#endif /* INFORMES_H_ */
