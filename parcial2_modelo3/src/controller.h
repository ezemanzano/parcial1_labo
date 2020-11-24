/*
 * controller.h
 *
 *  Created on: Nov 20, 2020
 *      Author: ezemanzano
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_encontrarLastId(LinkedList* pArrayListCliente);
int controller_addCliente(LinkedList* pArrayListCliente);
int controller_loadFromText(char* path , LinkedList* pArrayListClientes);
int controller_saveAsText(char* path , LinkedList* pArrayListClientes);
int controller_saveVentasAsText(char* path , LinkedList* pArrayListVentas);
int controller_loadVentasFromText(char* path , LinkedList* pArrayListVentas);
int controller_addVenta(LinkedList* pArrayListVentas, LinkedList* pArrayListClientes);
int controller_encontrarLastIdVentas(LinkedList* pArrayListVentas);
int controller_editVenta(LinkedList* pArrayListVentas, LinkedList* pArrayListClientes);
int controller_cobrarVentas (LinkedList* pArrayListVentas,LinkedList* pArrayListClientes);
int controller_generarListaCobrados(char* path , LinkedList* pArrayListClientes , LinkedList * pArrayListVentas);
int controller_generarListaAcobrar(char* path , LinkedList* pArrayListClientes , LinkedList * pArrayListVentas);
#endif /* CONTROLLER_H_ */
