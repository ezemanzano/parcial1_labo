/*
 * publicacion.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"

static int publicacion_generarNuevoId (void);

/**
 * \brief Inicializa el array de publicaciones cambiando el isEmpty a 1
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limite, es el tamaño de array
 * \return (-1) Error / (0) Ok
 *
 */
int publicacion_init(Publicacion * pArrayPubli, int limite){
	int retorno = -1;
	if (pArrayPubli != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrayPubli[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Da de alta una publicacion,mostrando los clientes disponibles
 * pidiendo al usuario el id de un cliente y los datos de la publicacion.
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array de publicaciones
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
 *
 */
int publicacion_alta (Publicacion * pArrayPubli, int limitePubli, Cliente * pArrayCliente , int limiteCliente)
{
	int retorno = -1;
	int indice;

	Publicacion bufferPublicacion;
	if (pArrayPubli != NULL && limitePubli >0)
	{
		if (publicacion_buscarLibreRef (pArrayPubli, limitePubli, &indice) == 0)
		{
		cliente_imprimir(pArrayCliente,limiteCliente);
				if (utn_getNumero(&bufferPublicacion.idCliente,"\n Ingrese id de cliente","error",0,99999,2) == 0 &&
					cliente_buscarIndicePorId(pArrayCliente, limiteCliente, bufferPublicacion.idCliente) != -1)
				{
					if  (utn_getNumero(&bufferPublicacion.rubro,"\n Ingrese Rubro (1-10)", "Error al ingresar los datos. Vuelva a intentar",MIN_RUBRO,MAX_RUBRO,2) == 0 &&
						utn_getString(bufferPublicacion.aviso, SIZE_AVISO, "\n Ingrese Aviso (max 64 caracteres)", "Error al ingresar los datos. Vuelva a intentar", 2) == 0)
					{
						pArrayPubli[indice] = bufferPublicacion;
						pArrayPubli[indice].estado = PUBLICACION_ACTIVA;
						pArrayPubli[indice].id = publicacion_generarNuevoId();
						pArrayPubli[indice].isEmpty = FALSE;
						retorno = 0;
						printf("\n---Nueva Publicacion Activa --- \n ID Publicacion-> %d ID Cliente: %d Aviso: %s Rubro: %d ",pArrayPubli[indice].id,pArrayPubli[indice].idCliente, pArrayPubli[indice].aviso,pArrayPubli[indice].rubro);
					}
				}
				else
				{
					printf("\n No se encotrò el id de cliente...");
				}
			}
		else
		{
			printf(" \n No quedan espacios libres");
		}
	}
		return retorno ;
}

/*

int publicacion_imprimirTodas (Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente) {
	int retorno = -1;
	char strEstado[10];
	if (pArrayPubli != NULL && limite >0 && pArrayCliente != NULL && limiteCliente >0){
		for (int i=0 ; i<limite ; i++)
		{
			if (pArrayPubli[i].estado == PUBLICACION_ACTIVA)
			{
				strncpy(strEstado,"ACTIVA",10);
			}
			else
			{
				strncpy(strEstado,"PAUSADA",10);
			}


			if(pArrayPubli[i].isEmpty == FALSE)
			{
				printf("\n ID Cliente: %d - Rubro: %d  - Aviso: %s - Estado: %s - ID Publicacion %d",pArrayPubli[i].idCliente, pArrayPubli[i].rubro,pArrayPubli[i].aviso,strEstado, pArrayPubli[i].id);
			}

		}

		retorno = 0;
	}
return retorno;
}
*/

/**
 * \brief Chequea si hay publicaciones dadas de alta
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \return (-1) Error / (1) Ok
 *
 */
int publicacion_sePuedeSeguir(Publicacion * pArrayPubli , int limitePubli){
	int retorno = -1;
	if (pArrayPubli != NULL && limitePubli >0)
	{
		for (int i = 0; i<limitePubli;i++)
		{
			if (pArrayPubli[i].isEmpty == FALSE)
			{
				retorno=1;
				break;
			}
		}
	}
return retorno;
}


/**
 * \brief Imprime por consola solo las publicaciones con el estado de ACTIVAS
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
 *
 */

int publicacion_imprimirActivas (Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente) {
	int retorno = -1;
	char strEstado[10];
	int flagActivas = 0;
	if (pArrayPubli != NULL && limite >0 && pArrayCliente != NULL && limiteCliente >0)
	{
		for (int i=0 ; i<limite ; i++)
		{
			if (pArrayPubli[i].estado == PUBLICACION_ACTIVA)
			{
				strncpy(strEstado,"ACTIVA",10);
			}
			else
			{
				strncpy(strEstado,"PAUSADA",10);
			}
			if(pArrayPubli[i].isEmpty == FALSE && pArrayPubli[i].estado == PUBLICACION_ACTIVA)
			{
				printf("\n ID Cliente: %d - Rubro: %d  - Aviso: %s - Estado: %s - ID Publicacion %d",pArrayPubli[i].idCliente, pArrayPubli[i].rubro,pArrayPubli[i].aviso,strEstado, pArrayPubli[i].id);
				flagActivas =1;
				retorno = 0;
			}

		}
		if (flagActivas==0)
		{
			printf("No hay publicaciones ACTIVAS");
		}
	}
return retorno;
}


/**
 * \brief Imprime por consola solo las publicaciones con el estado PAUSADAS
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
 *
 */


int publicacion_imprimirPausadas (Publicacion * pArrayPubli , int limite , Cliente * pArrayCliente , int limiteCliente) {
	int retorno = -1;
	char strEstado[10];
	int flagPausadas = 0;
	if (pArrayPubli != NULL && limite >0 && pArrayCliente != NULL && limiteCliente >0){
		for (int i=0 ; i<limite ; i++)
		{
			if (pArrayPubli[i].estado == PUBLICACION_ACTIVA)
			{
				strncpy(strEstado,"ACTIVA",10);
			}
			else
			{
				strncpy(strEstado,"PAUSADA",10);
			}
			if(pArrayPubli[i].isEmpty == FALSE && pArrayPubli[i].estado == PUBLICACION_PAUSADA)
			{
				printf("\n ID Cliente: %d - Rubro: %d  - Aviso: %s - Estado: %s - ID Publicacion %d",pArrayPubli[i].idCliente, pArrayPubli[i].rubro,pArrayPubli[i].aviso,strEstado, pArrayPubli[i].id);
				flagPausadas =1;
				retorno = 0;
			}

		}
		if (flagPausadas==0)
		{
			printf("No hay publicaciones PAUSADAS");
		}
	}
return retorno;
}


/**
 * \brief Pausa las publicaciones con el estado de ACTIVAS
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
 *
 */
int publicacion_pausar (Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente, int limiteCliente){
	int retorno = -1;
	int idBuscar;
	int indice;
	char deseaContinuar[2];
	if (pArrayPubli != NULL && limite>0)
	{
		if (publicacion_imprimirActivas(pArrayPubli, limite,pArrayCliente, limiteCliente) == 0)
		{
			if(utn_getNumero(&idBuscar,"\n Ingrese ID de Publicacion a Pausar","Error",0,9999,3)==0)
			{
			 if (publicacion_buscarIndicePorIdActivas(pArrayPubli, limite, idBuscar, &indice) == 0)
			 {
				if (utn_getNombre(deseaContinuar,2, "\n Desea Continuar?  (s/n)","Error",2)==0)
				{
				if (strcmp(deseaContinuar,"s") == 0 )
				{
					 printf("\n Publicacion Pausada correctamente... \n Corresponde al cliente-> ");
					 pArrayPubli[indice].estado = PUBLICACION_PAUSADA;
				     cliente_informacionCliente(pArrayCliente, limiteCliente,pArrayPubli[indice].idCliente);
				}
				else if (strcmp(deseaContinuar,"n") == 0)
				{
					printf("Back to main menu...");
				}

				}
				else
				{
					printf("ERROR - No ingreso s / n (case sensitive)");
				}
			 }
			 else
			 {
				 printf("Error - No se encuentra ese ID de Publicacion....");
			 }
			}
		}
	}
	return retorno;
}

/**
 * \brief reanuda las publicaciones con el estado de Pausadas
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
 *
 */

int publicacion_reanudar (Publicacion * pArrayPubli, int limite , Cliente * pArrayCliente, int limiteCliente){
	int retorno = -1;
	int idBuscar;
	int indice;
	char deseaContinuar[2];
	if (pArrayPubli != NULL && limite>0)
	{
		if (publicacion_imprimirPausadas(pArrayPubli, limite,pArrayCliente, limiteCliente) == 0)
		{
			if(utn_getNumero(&idBuscar,"\n Ingrese ID de Publicacion a Reanudar","Error",0,9999,3)==0)
			{
				 if (publicacion_buscarIndicePorIdPausadas(pArrayPubli, limite, idBuscar, &indice) == 0)
				 {
					if (utn_getNombre(deseaContinuar,2, "\n Desea Continuar?  (s/n)","Error",2)==0)
					{
					if (strcmp(deseaContinuar,"s") == 0 )
					{
						printf("\n Publicacion re activada correctamente... \n Corresponde al cliente-> ");
						pArrayPubli[indice].estado = PUBLICACION_ACTIVA;
						cliente_informacionCliente(pArrayCliente, limiteCliente,pArrayPubli[indice].idCliente);
					}
					else if (strcmp(deseaContinuar,"n") == 0)
					{
						printf("Back to main menu...");
					}

					}
					else
					{
						printf("ERROR - No ingreso s / n (case sensitive)");
					}
				 }
				 else
				 {
					 printf("Error - No se encuentra ese ID de Publicacion....");
				 }
			}
		}

	}
	return retorno;
}
/**
 * \brief Cuenta la cantidad de avisos que tiene un cliente y la devuelve como parametro
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param int idCLiente, es el id del cliente al que se quiere buscar la cantidad de avisos
 * \param int * resContador, es el puntero para devovler el resultado.
 * \return (-1) Error / (0) Ok
 */

int publicacion_cantidadPublicPorIdCliente(Publicacion * pArrayPublic, int limitePubli, int idCliente, int *resContador)
{
	int retorno = -1;
	int contador=0;
	for (int j = 0; j<limitePubli;j++)
	{
		if (pArrayPublic[j].idCliente == idCliente && pArrayPublic[j].isEmpty == FALSE && pArrayPublic[j].estado == PUBLICACION_ACTIVA)
		{
			contador++;
			retorno=0;
		}
	}
	*resContador = contador;
	return retorno;
}
/**
 * \brief Cuenta la cantidad de avisos que tiene un cliente y la devuelve como parametro
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param int idCLiente, es el id del cliente al que se quiere buscar la cantidad de avisos
 * \return (-1) Error / (0) Ok
 */

void publicacion_listarPublicacionesDeCliente( Publicacion * pArrayPublic, int limitePubli , int idCliente){
	char strEstado[10];
	if (pArrayPublic!=NULL && limitePubli>0 && idCliente>0)
	{
		for (int i = 0 ; i<limitePubli; i++)
		{
			if (pArrayPublic[i].isEmpty == FALSE && pArrayPublic[i].idCliente == idCliente)
			{

				if (pArrayPublic[i].estado == PUBLICACION_ACTIVA)
				{
					strncpy(strEstado,"ACTIVA",10);
				}
				else
				{
					strncpy(strEstado,"PAUSADA",10);
				}
				if(pArrayPublic[i].isEmpty == FALSE)
				{
					printf("\n ID Cliente: %d - Rubro: %d  - Aviso: %s - Estado: %s - ID Publicacion %d",pArrayPublic[i].idCliente, pArrayPublic[i].rubro,pArrayPublic[i].aviso,strEstado, pArrayPublic[i].id);
				}
			}
		}
	}
}

/**
 * \brief Cuenta la cantidad de avisos que tiene un cliente y la devuelve como parametro
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
 */

int publicacion_listaClientes (Cliente * pArrayCliente, int limiteClientes, Publicacion * pArrayPublic, int limitePubli){

	int retorno = -1;
	int contador=0;
	if (pArrayCliente != NULL && limiteClientes>0)
	{
		for (int i = 0; i<limiteClientes;i++)
		{
			if (pArrayCliente[i].isEmpty == FALSE)
			{
				publicacion_cantidadPublicPorIdCliente(pArrayPublic,limitePubli,pArrayCliente[i].id,&contador);
				printf("\n ID del Cliente %d -- Nombre: %s -- Apellido: %s -- Cuit del cliente: %s --  Cantidad de Publicaciones %d", pArrayCliente[i].id, pArrayCliente[i].nombre, pArrayCliente[i].apellido,pArrayCliente[i].cuit,contador);
			}
		}
	}
	return retorno;
}

/**
 * \brief Da de baja cliente y sus publicaciones.
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
 */

int publicacion_bajaClienteYPublicaciones(Publicacion * pArrayPubli, int limitePublic,Cliente * pArrayCliente, int limiteCliente){
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;
	char option[2];

	if (pArrayPubli!=NULL&& limitePublic>0&& pArrayCliente != NULL && limiteCliente>0)
	{
		cliente_imprimir(pArrayCliente, limiteCliente);
		if(utn_getNumero(&idABorrar," \n Ingrese id de cliente a borrar","Error",0,9999,3)==0)
		{
			if(cliente_buscarIndicePorIdRef(pArrayCliente, limiteCliente, idABorrar, &indiceABorrar)== 0)
			{
				publicacion_listarPublicacionesDeCliente(pArrayPubli, limitePublic, idABorrar);
				if (utn_getNombre(option,2, "\n Desea Continuar? Se borraran sus publicaciones tambien. (s/n)","Error",2)==0)
				{
					if (strcmp(option,"s") == 0 )
					{
						printf("\n Cliente y Publicaciones de BAJA.");
						pArrayCliente[indiceABorrar].isEmpty=TRUE;
						publicacion_baja(pArrayPubli, limitePublic, idABorrar);
					}
					else if (strcmp(option,"n") == 0)
					{
						printf("\n Back to main menu...");
					}
					else
					{
						printf("\n ERROR - No ingreso s / n (case sensitive)");
					}
				}

			}
			else
			{
				printf("\n No se encontro el ID. Vuelva a intentar");
			}
		}
	}
	return retorno;
}
/**
 * \brief Da de baja publicaciones correspondientes a un cliente.
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param int idCLiente, es el id del cliente al que se quiere buscar la cantidad de avisos
 * \return (-1) Error / (0) Ok
 */

int publicacion_baja (Publicacion * pArrayPubli, int limitePublic, int idCliente){
	int retorno = -1;

	if (pArrayPubli != NULL && limitePublic>0 && idCliente!=0)
	{
		for (int i = 0 ; i<limitePublic; i++)
		{
			if (pArrayPubli[i].idCliente == idCliente && pArrayPubli[i].isEmpty == FALSE)
			{
				pArrayPubli[i].isEmpty = TRUE;
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime por pantalla el cliente con mayor cantidad de avisos.
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param Cliente * pArrayCliente  Es el puntero al array de cliente
 * \param int limiteCliente, es el tamaño de array de clientes
 * \return (-1) Error / (0) Ok
 */


int publicacion_clienteConMasAvisos(Publicacion * pArrayPubli, int limitePubli,Cliente * pArrayCliente, int limiteCliente){
	int retorno = -1;
	int contador=0;
	Cliente bufferCliente;
	int contadorMax = 0;
	if (pArrayPubli!=NULL&& limitePubli>0 && pArrayCliente != NULL && limiteCliente>0)
	{
		if (cliente_sePuedeSeguir(pArrayCliente, limiteCliente)==1)
		{
		for (int i = 0; i<limiteCliente;i++)
		{
			if (pArrayCliente[i].isEmpty == FALSE)
			{
				publicacion_cantidadPublicPorIdCliente(pArrayPubli,limitePubli,pArrayCliente[i].id,&contador);
				if (contador>=contadorMax)
				{
				bufferCliente = pArrayCliente[i];
				contadorMax=contador;
				}
			}
		}
		printf("\n El cliente con mas avisos es: %s %s CON: %d avisos", bufferCliente.nombre,bufferCliente.apellido, contadorMax);
		}
		else
		{
			printf("\n No hay clientes para mostrar.");
		}
	}
return retorno;
}

/**
 * \brief Cuenta e imprime la cantidad de avisos con estado PAUSADO
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \return (-1) Error / (0) Ok
 */

int publicacion_cantidadPausados (Publicacion * pArrayPubli, int limitePubli) {
	int retorno = -1;
	int contador=0;
	if (pArrayPubli!=NULL && limitePubli>0)
	{
		if(publicacion_sePuedeSeguir(pArrayPubli, limitePubli)==1)
		{
			for (int i = 0; i<limitePubli;i++)
			{
				if (pArrayPubli[i].isEmpty == FALSE && pArrayPubli[i].estado == PUBLICACION_PAUSADA)
				{
					contador++;
					retorno=0;
				}
			}
			printf("\n Hay %d avisos Pausados",contador);
		}
		else
		{
			printf("No hay publicaciones creadas, por lo tanto no hay avisos pausados.");
		}

	}
	return retorno;
}

/**
 * \brief Imprime el rubro con mas avisos y la cantidad que este posee.
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \return (-1) Error / (0) Ok
 */

int publicacion_rubroConMasAvisos (Publicacion * pArrayPubli, int limitePubli){
	int retorno = -1;
	int contador = 0;
	int rubroMax = 0;
	int rubroAMostrar=0;
	if (publicacion_sePuedeSeguir(pArrayPubli, limitePubli)==1)
	{
		for (int i = MIN_RUBRO ; i<MAX_RUBRO; i++)
		{
			contador=0;
			for (int j = 0;j<limitePubli;j++)
			{
				if(pArrayPubli[j].rubro == i && pArrayPubli[j].isEmpty==FALSE)
				{
					contador++;
				}
			}

			if (contador > rubroMax)
			{
				rubroAMostrar = i;
				rubroMax = contador;
			}
		}
		printf("El rubro con màs avisos es el rubro  %d", (rubroAMostrar));
	}
	else
	{
		printf("\n No hay publicaciones activas.");
	}
return retorno;
}



/**
 * \brief Buscar un lugar libre en el array de publicaciones y lo devuelve por parametro
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param int * pIndice, puntero donde se devuelve el indice libre.
 * \return (-1) Error / (0) Ok
 */

int publicacion_buscarLibreRef (Publicacion * pArrayPubli, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayPubli != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArrayPubli[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}
/**
 * \brief Genera un id unico para las publicaciones-.
 * \return (-1) Error / (0) Ok
 */

static int publicacion_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

/**
 * \brief Devuelve el indice por paramtro de un id de publicaciones.
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param int idBuscar, se ingresa por parametro el id a buscar su indice
 * \param int * pIndice, puntero donde se devuelve el indice libre.
 * \return (-1) Error / (0) Ok
 */

int publicacion_buscarIndicePorId (Publicacion * pArrayPubli, int limite,
		               int idBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayPubli != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
			for ( i = 0; i<limite; i++)
			{
				if(pArrayPubli[i].isEmpty == FALSE  &&
					pArrayPubli[i].id == idBuscar)
				{
				*pIndice = i;
				retorno = 0;
				break;
				}
			}
		}
		else
		{
			printf("error");
		}
		return retorno;
}

/**
 * \brief Devuelve el indice por paramtro de un id de publicaciones chequeando si esta esta pausada.
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param int idBuscar, se ingresa por parametro el id a buscar su indice
 * \param int * pIndice, puntero donde se devuelve el indice libre.
 * \return (-1) Error / (0) Ok
 */

int publicacion_buscarIndicePorIdPausadas (Publicacion * pArrayPubli, int limite,
		               int idBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayPubli != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrayPubli[i].isEmpty == FALSE  &&
						pArrayPubli[i].id == idBuscar &&
						pArrayPubli[i].estado == PUBLICACION_PAUSADA)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
				}
			}
			else
			{
				printf("errrror");
			}
		return retorno;
}
/**
 * \brief Devuelve el indice por paramtro de un id de publicaciones chequeando si esta esta activa.
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limitePubli, es el tamaño de array
 * \param int idBuscar, se ingresa por parametro el id a buscar su indice
 * \param int * pIndice, puntero donde se devuelve el indice libre.
 * \return (-1) Error / (0) Ok
 */

int publicacion_buscarIndicePorIdActivas (Publicacion * pArrayPubli, int limite,
		               int idBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayPubli != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrayPubli[i].isEmpty == FALSE  &&
						pArrayPubli[i].id == idBuscar &&
						pArrayPubli[i].estado == PUBLICACION_ACTIVA)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
				}
			}
			else
			{
				printf("errrror");
			}
		return retorno;
}
/**
 * \brief hardcodeo de datos
 * \param Publicacion * pArrayPubli Es el puntero al array de publicaciones
 * \param int limite, es el tamaño de array
 * \param int idcliente, se pasa el dato por paramtro
 * * \param int rubro, se pasa el dato por paramtro
 * \param char* aviso, se pasa el dato por paramtro
 * \return (-1) Error / (0) Ok
 */

int publicacion_altaForzada(Publicacion * pArray, int limite ,int idCliente,int rubro,  char * aviso){

	int retorno = -1;
	int indice;
	if (publicacion_buscarLibreRef(pArray,limite, &indice) == 0)
	{
		strncpy(pArray[indice].aviso,aviso,SIZE_AVISO);
		pArray[indice].idCliente = idCliente;
		pArray[indice].rubro=rubro;
		pArray[indice].estado=PUBLICACION_ACTIVA;
		pArray[indice].id = publicacion_generarNuevoId();
		pArray[indice].isEmpty = FALSE;
		retorno=0;
	}
	return retorno;
}






