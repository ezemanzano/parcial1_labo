#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
#include "ventas.h"
#include "utn.h"
#include <string.h>
#include "parser.h"
#include "controller.h"

/** \brief Carga los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_loadFromText(char* path , LinkedList* pArrayListClientes)
{
	int retorno=-1;
	FILE* pFile;
	if (pArrayListClientes!=NULL)
	{
		pFile = fopen(path,"r");
		if (pFile == NULL)
		{
			retorno=-1;
		}
		if (parser_clientesFromText(pFile, pArrayListClientes)==0)
		{
			printf("\n-Carga de datos Correcta-");
			retorno =0;
	}

	}
	return retorno;
}

/** \brief Carga los datos de las ventas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadVentasFromText(char* path , LinkedList* pArrayListVentas)
{
	int retorno=-1;
	FILE* pFile;
	if (pArrayListVentas!=NULL)
	{
		pFile = fopen(path,"r");
		if (pFile == NULL)
		{
			retorno=-1;
		}
		if (parser_ventasFromText(pFile, pArrayListVentas)==0)
		{
			printf("\n-Carga de datos Correcta-");
			retorno =0;
		}
		else
		{
		printf("errorrrrr");
		}

	}
	return retorno;
}

/** \brief Guarda los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListClientes)
{
	int retorno=-1;
	int idAux;
	char nombreAux[128];
	char apellidoAux[128];
	char cuitAux[128];
	int len = ll_len(pArrayListClientes);
	Cliente *  clienteAux=cliente_new();
	FILE* pFile;
	if (clienteAux!=NULL&&pArrayListClientes!=NULL&&len>0)
	{
		pFile = fopen(path,"w");
		fprintf(pFile,"id,nombre,apellido,cuit\n");
		for (int i= 0;i<len;i++)
		{
		 clienteAux = ll_get(pArrayListClientes, i);
		 if(cliente_getIdCliente(clienteAux,&idAux) == 0 &&
		 cliente_getNombreCliente(clienteAux, nombreAux) == 0 &&
		 cliente_getApellidoCliente(clienteAux, apellidoAux) == 0 &&
		 cliente_getCuitCliente(clienteAux , cuitAux) ==0)
		 {
			fprintf(pFile,"%d,%s,%s,%s\n",idAux,nombreAux,apellidoAux,cuitAux);
			retorno=0;
		 }

		}
		printf("\nEl archivo fue guardado exitosamente..");
	}

	fclose(pFile);
return retorno;
}


int controller_generarListaCobrados(char* path , LinkedList* pArrayListClientes , LinkedList * pArrayListVentas)
{
	int retorno=-1;
	int idAux;
	char nombreAux[128];
	char apellidoAux[128];
	char cuitAux[128];
	int cobradasAux=0;
	int len = ll_len(pArrayListClientes);
	Cliente *  clienteAux=cliente_new();
	FILE* pFile;
	if (clienteAux!=NULL&&pArrayListClientes!=NULL&&len>0)
	{
		pFile = fopen(path,"w");
		fprintf(pFile,"id,nombre,apellido,cuit,cantidadAfichesCobrados\n");
		for (int i= 0;i<len;i++)
		{
		 clienteAux = ll_get(pArrayListClientes, i);
		 if(cliente_getIdCliente(clienteAux,&idAux) == 0 &&
		 cliente_getNombreCliente(clienteAux, nombreAux) == 0 &&
		 cliente_getApellidoCliente(clienteAux, apellidoAux) == 0 &&
		 cliente_getCuitCliente(clienteAux , cuitAux) ==0)
		 {
		 ll_reduceIntbyID(pArrayListVentas,ventas_cobradasPorCliente,&cobradasAux,idAux);
		 fprintf(pFile,"%d,%s,%s,%s,%d\n",idAux,nombreAux,apellidoAux,cuitAux,cobradasAux);
		 retorno=0;
		 }

		}
		printf("\nEl archivo fue guardado exitosamente..");
	}

	fclose(pFile);
return retorno;
}


int controller_generarListaAcobrar(char* path , LinkedList* pArrayListClientes , LinkedList * pArrayListVentas)
{
	int retorno=-1;
	int idAux;
	char nombreAux[128];
	char apellidoAux[128];
	char cuitAux[128];
	int cobradasAux=0;
	int len = ll_len(pArrayListClientes);
	Cliente *  clienteAux=cliente_new();
	FILE* pFile;
	if (clienteAux!=NULL&&pArrayListClientes!=NULL&&len>0)
	{
		pFile = fopen(path,"w");
		fprintf(pFile,"id,nombre,apellido,cuit,cantidadAfichesACobrar\n");
		for (int i= 0;i<len;i++)
		{
		 clienteAux = ll_get(pArrayListClientes, i);
		 if(cliente_getIdCliente(clienteAux,&idAux) == 0 &&
		 cliente_getNombreCliente(clienteAux, nombreAux) == 0 &&
		 cliente_getApellidoCliente(clienteAux, apellidoAux) == 0 &&
		 cliente_getCuitCliente(clienteAux , cuitAux) ==0)
		 {
		 ll_reduceIntbyID(pArrayListVentas,ventas_aCobrarPorCliente,&cobradasAux,idAux);
		 fprintf(pFile,"%d,%s,%s,%s,%d\n",idAux,nombreAux,apellidoAux,cuitAux,cobradasAux);
		 retorno=0;
		 }

		}
		printf("\nEl archivo fue guardado exitosamente..");
	}

	fclose(pFile);
return retorno;
}




/** \brief Guarda los datos de las ventas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveVentasAsText(char* path , LinkedList* pArrayListVentas)
{
	int retorno=-1;
	int idAux;
	int idClienteAux;
	char nombreAux[128];
	int cantidadAux;
	int zonaAux;
	int estadoAux;
	int len = ll_len(pArrayListVentas);
	Ventas * ventasAux= ventas_new();
	FILE* pFile;
	if (ventasAux!=NULL&&pArrayListVentas!=NULL&&len>0)
	{
		pFile = fopen(path,"w");
		fprintf(pFile,"id,idcliente,cantidadAfiches,nombreArchivo,zona,estado\n");
		for (int i= 0;i<len;i++)
		{
		ventasAux = ll_get(pArrayListVentas, i);

		if(!(ventas_getIdVenta(ventasAux, &idAux))
			&&!(ventas_getIdCliente(ventasAux, &idClienteAux))
			&&!(ventas_getCantidadAfiches(ventasAux, &cantidadAux))
			&&!(ventas_getNombreDelArchivo(ventasAux, nombreAux))
			&&!(ventas_getZona(ventasAux, &zonaAux))
			&&!(ventas_getEstadoVenta(ventasAux, &estadoAux)))
			{
			fprintf(pFile,"%d,%d,%d,%s,%d,%d\n",idAux,idClienteAux,cantidadAux,nombreAux,zonaAux,estadoAux);
			retorno=0;
		 }

		}
		printf("\nEl archivo fue guardado exitosamente..");
	}

	fclose(pFile);
return retorno;
}





/** \brief Alta de clientes
 * * \param pArrayListEmployee LinkedList*
 * \return int -1 error - 0 ok
 *
 */



int controller_addCliente(LinkedList* pArrayListCliente)
{

	int retorno=-1;
	char nombreClienteAux [128];
	char apellidoClienteAux [128];
	char cuitAux[128];

 	if (utn_getNombre(nombreClienteAux,128, "\nIngrese nombre","Error",2)== 0 &&
		utn_getNombre(apellidoClienteAux,128, "\nIngrese apellido","Error",2)== 0 &&
		utn_getCuit(cuitAux,128, "\nIngrese cuit","Error",2)== 0 &&
		cliente_noSeRepiteCuit(pArrayListCliente,cuitAux)!=0) //&& cuitExiste.
 	{
 		Cliente * Aux = cliente_new();
 		if(Aux!=NULL)
 		{
 			cliente_setNombreCliente(Aux, nombreClienteAux);
 			cliente_setApellidoCliente(Aux, apellidoClienteAux);
 			cliente_setCuitCliente(Aux, cuitAux);
 			cliente_setIdCliente(Aux, controller_encontrarLastId(pArrayListCliente));
 		}
 		ll_add(pArrayListCliente,Aux);
 		printf("\nAlta de cliente correcta..");
 		retorno=0;


 	}
 	else
 	{
 		printf("Error - El cliente ya existe.");
 	}
 	return retorno;
}

/** \brief Busca el ultimo Id cargado
 * * \param pArrayListEmployee LinkedList*
 * \return int -1 error - ultimo id
 *
 */


int controller_encontrarLastId(LinkedList* pArrayListCliente){
	int retorno=-1;
	int auxId;
	int max;
	Cliente * clienteAux;
	int len = ll_len(pArrayListCliente);
	if (pArrayListCliente!=NULL)
	{
		for (int i = 0;i<len;i++)
		{
			clienteAux=ll_get(pArrayListCliente, i);
			cliente_getIdCliente(clienteAux, &auxId);
			if (i==0||auxId>max)
			{
				max = auxId;
				retorno = max+1;
			}
		}
	}
	return retorno;
}

/** \brief Busca el ultimo Id cargado
 * * \param pArrayListEmployee LinkedList*
 * \return int -1 error - ultimo id
 *
 */

int controller_encontrarLastIdVentas(LinkedList* pArrayListVentas){
	int retorno=-1;
	int auxId;
	int max;
	Ventas * ventasAux;
	int len = ll_len(pArrayListVentas);
	if (pArrayListVentas!=NULL)
	{
		for (int i = 0;i<len;i++)
		{
			ventasAux=ll_get(pArrayListVentas, i);
			ventas_getIdVenta(ventasAux,&auxId);
			if (i==0||auxId>max)
			{
				max = auxId;
				retorno = max+1;
			}
		}
	}
	return retorno;
}

/** \brief Alta de ventas
 * * \param pArrayListVentas LinkedList* puntero al array
 * \param pArrayListClientes LinkedList* puntero al array
 * \return int -1 error - 0 ok
 *
 */



int controller_addVenta(LinkedList* pArrayListVentas, LinkedList* pArrayListClientes)
{

	int retorno=-1;
	int idClienteAux;
	int cantidadAux;
	char nombreAux[128];
	int zonaAux;
	int idAux;

 	if ((utn_getNumero(&idClienteAux,"\nIngrese ID cliente", "Error", 0, 9999, 2)==0 &&
 		cliente_idExiste(pArrayListClientes, idClienteAux)==0)&&
 		utn_getNumero(&cantidadAux,"\nIngrese cantidad de afiches", "Error", 0, 9999, 2)==0 &&
		utn_getNombreArchivo(nombreAux, 128,"Ingrese nombre archivo", "Error", 2)==0 &&
		utn_getNumero(&zonaAux,"\nIngrese zona destino (0-2)", "Error", 0, 2, 2)==0)
 	{

 		Ventas * ventasAux=ventas_new();
 		if(ventasAux!=NULL)
 		{
 			idAux = controller_encontrarLastIdVentas(pArrayListVentas);
 			ventas_setIdVenta(ventasAux,idAux);
 			ventas_setIdCliente(ventasAux, idClienteAux);
 			ventas_setCantidadAfiches(ventasAux, cantidadAux);
 			ventas_setNombreDelArchivo(ventasAux, nombreAux);
 			ventas_setZona(ventasAux, zonaAux);
 			ventas_setEstadoVenta(ventasAux, 0);
 		}
 		ll_add(pArrayListVentas,ventasAux);
 		printf("\nAlta de cliente correcta..");
 		printf("\n %04d | %04d | %04d | %-30s | %01d | 0 | ", idAux, idClienteAux, cantidadAux,nombreAux,zonaAux);
 		retorno=0;
 	}
 	else
 	{
 		printf("Error - No se encontrò el id de cliente.");
 	}
 	return retorno;
}

/** \brief modificar ventas
 * * \param pArrayListVentas LinkedList* puntero al array
 * \param pArrayListClientes LinkedList* puntero al array
 * \return int -1 error - 0 ok
 *
 */


int controller_editVenta(LinkedList* pArrayListVentas, LinkedList* pArrayListClientes)
{
	int retorno=-1;
	int idCliente;
	int cantidadAux;
	char nombreAux[128];
	int zonaAux;
	int idAux;
	int option;
	Ventas * ventasAux;
	if (pArrayListClientes!= NULL && pArrayListVentas!=NULL)
	{
		ll_map(pArrayListVentas, ventas_imprimirACobrar);
		if (utn_getNumero(&idAux, "\nIngrese ID a modificar", "Error", 1, 9999, 2)==0 && ventas_idExiste(pArrayListVentas, idAux) == 0)
		{
			ventasAux = ll_get(pArrayListVentas,ll_mapAndBreak(pArrayListVentas,ventas_findbyId,idAux));
			ventas_getIdCliente(ventasAux, &idCliente);
			printf("\n Datos del Cliente");
			ll_mapAndBreak(pArrayListClientes, cliente_printOne, idCliente);
			if(ventasAux!=NULL)
			{
				do
				{
					if(utn_getNumero(&option, "\n Que desea modificar ? \n 1)Cantidad Afiches 2) Nombre Archivo 3) Zona", "Error", 1,4, 2)==0)
					{
						switch (option)
						{
						case 1:
							if(utn_getNumero(&cantidadAux,"\n Ingrese nueva cantidad", "error", 0, 1000,2)==0)
							{
								ventas_setCantidadAfiches(ventasAux, cantidadAux);
							}
							break;
						case 2:
							if (utn_getNombreArchivo(nombreAux, 128,"Ingrese nombre archivo", "Error", 2)==0)
							{
								ventas_setNombreDelArchivo(ventasAux, nombreAux);
							}
							break;
						case 3:
							if(utn_getNumero(&zonaAux,"\n Ingrese nueva zona ", "error", 0, 2,2)==0)
							{
								ventas_setZona(ventasAux, zonaAux);
							}
							break;
						}
					}

				}while(option!=4);
			}
			retorno=0;
		}
		else
		{
			printf("Error - No se encontrò el id de cliente.");
		}
	}
 	return retorno;
}

/** \brief Cambia el estado de la venta.
 * * \param pArrayListVentas LinkedList* puntero al array
 * \param pArrayListClientes LinkedList* puntero al array
 * \return int -1 error - 0 ok
 *
 */



int controller_cobrarVentas (LinkedList* pArrayListVentas,LinkedList* pArrayListClientes)
{
	ll_map(pArrayListVentas, ventas_imprimirACobrar);
	int idAux;
	int idCliente;
	int opcion;
	int retorno =-1;
	int estadoAux;
	Ventas * ventasAux;
	if (pArrayListClientes!= NULL && pArrayListVentas!=NULL)
	{
		if (utn_getNumero(&idAux, "\nIngrese ID de venta a Cobrar", "Error", 1, 9999, 2)==0 && ventas_idExiste(pArrayListVentas, idAux) == 0)
	 	{
	 		ventasAux = ll_get(pArrayListVentas,ll_mapAndBreak(pArrayListVentas,ventas_findbyId,idAux));
	 		ventas_getEstadoVenta(ventasAux, &estadoAux);
	 		if (estadoAux == 0)
	 		{
	 			ventas_getIdCliente(ventasAux, &idCliente);
				printf("\n Datos del Cliente");
				ll_mapAndBreak(pArrayListClientes, cliente_printOne, idCliente);
				if (utn_getNumero(&opcion,"Desea cobrar la venta? 0 - Si 1 - No","Error",0,1,2)==0)
				{
					if (opcion==0)
					{
						ventas_setEstadoVenta(ventasAux, 1);
						retorno = 0;
					}
				}
	 		}
	 		else
	 		{
	 			printf("\n Esa venta ya està cobrada...");
	 		}
	 	}
		else
		{
			printf("No se encontrò ese id de Venta.");
		}
	}
return retorno;
}


