/*
 ============================================================================
 Name        : parcial2_modelo3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

int main(void) {
	int opcion;
	int subMenu;
	LinkedList * pArrayListClientes = ll_newLinkedList();
	LinkedList * pArrayListVentas=ll_newLinkedList();
	LinkedList * pArrayListVentasCobradas = ll_newLinkedList();
	LinkedList * pArrayListVentasACobrar = ll_newLinkedList();
	printf("Cargando Clientes...");
	controller_loadFromText("clientes.csv", pArrayListClientes);
	ll_map(pArrayListClientes, cliente_imprimirTodos);
	printf("\nCargando Ventas...");
	controller_loadVentasFromText("ventas.csv", pArrayListVentas);
	ll_map(pArrayListVentas,ventas_imprimirTodos);
	do
	{
		utn_getNumero(&opcion, "\nMenu\n1)Alta Cliente \n"
				"2) Alta Venta\n"
				"3) Modificar Venta \n"
				"4) Cobrar Venta\n"
				"5) Generar cobradas.csv \n"
				"6) Generar a_cobrar.csv \n"
				"7) Informes", "Error", 1, 8, 2);
		switch (opcion)
		{
		case 1:
			if (controller_addCliente(pArrayListClientes) ==0)
			{
				ll_map(pArrayListClientes, cliente_imprimirTodos);
				controller_saveAsText("clientes.csv", pArrayListClientes);
			}
			break;
		case 2:
			if (controller_addVenta(pArrayListVentas, pArrayListClientes)==0)
			{
				ll_map(pArrayListVentas,ventas_imprimirTodos);
				controller_saveVentasAsText("ventas.csv", pArrayListVentas);
			}
			break;
		case 3:
			if (controller_editVenta(pArrayListVentas,pArrayListClientes)==0)
			{
				ll_map(pArrayListVentas,ventas_imprimirTodos);
				controller_saveVentasAsText("ventas.csv", pArrayListVentas);
			}
		break;

		case 4:
			if (controller_cobrarVentas(pArrayListVentas, pArrayListClientes)==0)
			{
			ll_map(pArrayListVentas,ventas_imprimirTodos);
			controller_saveVentasAsText("ventas.csv", pArrayListVentas);
			}
		break;
		case 5:
			pArrayListVentasCobradas=ll_clone(pArrayListVentas);
			ll_filterByInt(pArrayListVentasCobradas,ventas_filtrarPorCobradas,1);
			ll_map(pArrayListVentasCobradas,ventas_imprimirTodos);
			controller_generarListaAcobrar("cobradas.csv", pArrayListClientes,pArrayListVentasCobradas);
			break;
		case 6:
			pArrayListVentasACobrar=ll_clone(pArrayListVentas);
			ll_filterByInt(pArrayListVentasACobrar,ventas_filtrarPorCobradas,0);
			ll_map(pArrayListVentasACobrar,ventas_imprimirTodos);
			controller_generarListaCobrados("a_cobrar.csv", pArrayListClientes,pArrayListVentasACobrar);
			break;
		case 7:
			do
			{
				if(utn_getNumero(&subMenu, "\n 1)Cliente con mas afiches vendidos\n "
						"2)Cliente con menos afiches vendidos \n"
						" 3)Venta con mas afiches vendidos\n", "error", 1, 4, 2) == 0)
				{
					switch (subMenu) {
						case 1:
							informes_encontrarClienteConMasVentas(pArrayListVentas,pArrayListClientes);
							break;
						case 2:
							informes_encontrarClienteConMenosVentas(pArrayListVentas, pArrayListClientes);
							break;
						case 3:
							informes_findClienteConMasAfiches(pArrayListVentas,pArrayListClientes);
							break;
					}
				}

			}while (subMenu!=4);
		break;
		}

	}while(opcion!=8);

}
