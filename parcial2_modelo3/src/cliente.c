#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cliente.h"
#include "parser.h"
#include "utn.h"

static int isValidIdCliente(int idCliente);
static int isValidNombreCliente(char* nombreCliente);
static int isValidApellidoCliente(char* apellidoCliente);
static int isValidCuitCliente(char* cuitCliente);


/** \brief Crea un espacio de memoria dinamica para un cliente
 *
 * \param void
 * \return int
 *
 */

Cliente* cliente_new(void)
{
	return (Cliente*)malloc(sizeof(Cliente));
}
/** \brief Crea un empleado pasandole los datos como parametro
 * \param int idCliente - id del usuario en formato int
 * \param char * nombreCliente - nombre del cliente en formato string
 * \param char * apellidoCliente - apellido del cliente en formato string
 * \param char * cuitcliente - Cuit del cliente en formato string
 * \return devuelve por retorno el puntero del empleado si se cargo correctamente sino devuelve null para indicar error
 */



Cliente* cliente_newParam(int idCliente, char * nombreCliente, char * apellidoCliente , char * cuitCliente)
{
	Cliente* this = cliente_new();
	if(this != NULL)
	{
		 if(!(cliente_setIdCliente(this, idCliente)) &&
			!(cliente_setNombreCliente(this, nombreCliente)) &&
			!(cliente_setApellidoCliente(this, apellidoCliente)) &&
			!(cliente_setCuitCliente(this, cuitCliente)))
		{
			return this;
		}
	}
	return NULL;
}

/**
 * \brief Lee el id de un cliente
 * \param Cliente* this, Es el puntero al array.
 * \param int * idCliente, Puntero donde devuelve el nombre del empleado.
 * \return (-1) Error / (0) Ok
 */


int cliente_getIdCliente(Cliente* this, int * idCliente)
{
	if (this!=NULL)
	{
		*idCliente = this->idCliente;
		return 0;
	}
	return -1;
}

/**
 * \brief Define el id de un cliente
 * \param Employee* this, Es el puntero al cliente.
 * \param int val -> valor a guardar
 * \return (-1) Error / (0) Ok
 */

int cliente_setIdCliente(Cliente* this, int idCliente)
{
	int output = -1;
	if(this != NULL  && isValidIdCliente(idCliente))
	{
		this->idCliente = idCliente;
		output = 0;
	}
	 return output;
}

/**
 * \brief Chequea que el id tenga el formato deseado
 * \param int idCliente, Valor a chequear
 * \return (-1) Error / (0) Ok
 */


static int isValidIdCliente(int idCliente)
{
	if(idCliente>0)
	{
	return 1;
	}
return -1;
}

/**
 * \brief Lee el nombre de un cliente
 * \param Cliente* this, Es el puntero al array.
 * \param char * nombreCliente, Puntero donde devuelve el nombre del empleado.
 * \return (-1) Error / (0) Ok
 */


int cliente_getNombreCliente(Cliente* this, char * nombreCliente)
{
	if (this!=NULL)
	{
		strncpy(nombreCliente,this->nombreCliente,(int)sizeof(this->nombreCliente));
		return 0;
	}
	return -1;
}

/**
 * \brief Define el nombre de un cliente
 * \param Employee* this, Es el puntero al empleado.
 * \param char * nombreCliente -> valor a guardar
 * \return (-1) Error / (0) Ok
 */

int cliente_setNombreCliente(Cliente* this, char* nombreCliente)
{
	int output = -1;
	if(this != NULL && isValidNombreCliente(nombreCliente))
	{
		strncpy(this->nombreCliente,nombreCliente,(int)sizeof(this->nombreCliente));
		output = 0;
	}
	return output;
}
/**
 * \brief Chequea que el nombre tenga el formato deseado
 * \param char * cuitCliente, Valor a chequear
 * \return (-1) Error / (0) Ok
 */


static int isValidNombreCliente(char* nombreCliente)
{
	int retorno = 1;
	int i ;
	for (i = 0 ; i<=strlen(nombreCliente) && nombreCliente[i] != '\0'; i++)
	{
		if	((nombreCliente[i] < 'a' || nombreCliente[i] > 'z') && (nombreCliente[i] < 'A' || nombreCliente[i] > 'Z'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;

}
/**
 * \brief Lee el apellido de un cliente
 * \param Cliente* this, Es el puntero al array.
 * \param char * apellidoCliente, Puntero donde devuelve el nombre del empleado.
 * \return (-1) Error / (0) Ok
 */


int cliente_getApellidoCliente(Cliente* this, char * apellidoCliente)
{
	if (this!=NULL)
		{
		strncpy(apellidoCliente,this->apellidoCliente,(int)sizeof(this->apellidoCliente));
		return 0;
		}
		return -1;
}

/**
 * \brief Define el apellido de un cliente
 * \param Employee* this, Es el puntero al empleado.
 * \param char * nombreCliente -> valor a guardar
 * \return (-1) Error / (0) Ok
 */

int cliente_setApellidoCliente(Cliente* this, char* apellidoCliente)
{
	int output = -1;
	if(this != NULL && isValidApellidoCliente(apellidoCliente))
	{
		strncpy(this->apellidoCliente,apellidoCliente,(int)sizeof(this->apellidoCliente));
		output = 0;
	}
	return output;
}

/**
 * \brief Chequea que el apellido tenga el formato deseado
 * \param char * cuitCliente, Valor a chequear
 * \return (-1) Error / (0) Ok
 */


static int isValidApellidoCliente(char* apellidoCliente)
{
	int retorno = 1;
	int i ;
	for (i = 0 ; i<=strlen(apellidoCliente) && apellidoCliente[i] != '\0'; i++)
	{
		if	((apellidoCliente[i] < 'a' || apellidoCliente[i] > 'z') && (apellidoCliente[i] < 'A' || apellidoCliente[i] > 'Z'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/**
 * \brief Lee el cuit de un cliente
 * \param Cliente* this, Es el puntero al array.
 * \param char * cuitCliente, Puntero donde devuelve el nombre del empleado.
 * \return (-1) Error / (0) Ok
 */


int cliente_getCuitCliente(Cliente* this, char * cuitCliente)
{
	if (this!=NULL)
	{
	strncpy(cuitCliente,this->cuitCliente,(int)sizeof(this->cuitCliente));
	return 0;
	}
	return -1;
}

/**
 * \brief Define el cuit de un cliente
 * \param Employee* this, Es el puntero al empleado.
 * \param char * nombreCliente -> valor a guardar
 * \return (-1) Error / (0) Ok
 */

int cliente_setCuitCliente(Cliente* this, char* cuitCliente)
{
	int output = -1;
	if(this != NULL && isValidCuitCliente(cuitCliente))
	{
		strncpy(this->cuitCliente,cuitCliente,(int)sizeof(this->cuitCliente));
		output = 0;
	}
	return output;
}

/**
 * \brief Chequea que el cuit tenga el formato deseado
 * \param char * cuitCliente, Valor a chequear
 * \return (-1) Error / (0) Ok
 */


static int isValidCuitCliente(char* cuitCliente)
{
	int retorno = 1;
	int contador = 0;
	int i ;
	for (i = 0 ; i<=strlen(cuitCliente) && cuitCliente[i] != '\0'; i++)
	{
		if	(cuitCliente[i]< '0' || cuitCliente[i] > '9')
		{
			if (cuitCliente[i] == '-')
			{
				contador++;
				if (contador>2)
				{
					retorno = 0;
					break;
				}
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief Funcion criterio para imprimir todos los datos de un Cliente
 * \param void*thisA -> puntero a void
 * \return (-1) Error / (0) Ok
 */


int cliente_imprimirTodos(void*thisA){
	Cliente * clienteA = thisA;
	int retorno =-1;
	int idAux;
	char nombreAux[128];
	char apellidoAux[128];
	char cuitAux[128];
	 if(!(cliente_getIdCliente(clienteA, &idAux)) &&
		!(cliente_getNombreCliente(clienteA,nombreAux)) &&
		!(cliente_getApellidoCliente(clienteA,apellidoAux)) &&
		!(cliente_getCuitCliente(clienteA, cuitAux)))
	{
		printf("\n %04d | %-15s |  %-15s | %-16s | ", idAux, nombreAux, apellidoAux, cuitAux);
		retorno = 0;
	}


	return retorno;
}

/**
 * \brief Busca si el cuit no està cargado previamente en la lista
 * \param vpArraylistClientes -> putnero al array
 * \param char * cuitCliente -> cuit a buscar en la lista
 * \return (-1) Error - No se encuentra / (0) Si lo encuntra
 */


int cliente_noSeRepiteCuit(LinkedList * pArrayListClientes,char * cuitCliente)
{
	int retorno =-1;
	char cuitClienteAux[128];
	Cliente * clienteAux = cliente_new();
	for (int i = 0; i<ll_len(pArrayListClientes);i++)
	{
		clienteAux=ll_get(pArrayListClientes, i);
		if (cliente_getCuitCliente(clienteAux, cuitClienteAux) == 0)
		{
			if (strncmp(cuitCliente,cuitClienteAux,128) == 0)
			{
				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}

/**
 * \brief Busca si el id està cargado previamente en la lista
 * \param vpArraylistClientes -> putnero al array
 * \param char * cuitCliente -> cuit a buscar en la lista
 * \return (-1) Error -  (1) si no lo encuentra / (0) si lo encuentra
 */

int cliente_idExiste (LinkedList * pArrayListClientes, int idCliente)
{
	int retorno = -1;
	int idAux;
	if (pArrayListClientes!=NULL)
	{
		retorno =1;
		for (int i = 0;i<ll_len(pArrayListClientes);i++)
		{
			Cliente * clienteAux =ll_get(pArrayListClientes, i);
			if (cliente_getIdCliente(clienteAux, &idAux) == 0 && idAux == idCliente)
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

/**
 * \brief Funcion criterio para imprimir todos los datos de un Cliente
 * \param void*thisA -> puntero a void
 * \param int idCliente -> id del cliente a imprimir.
 * \return (-1) Error / (0) Ok
 */


int cliente_printOne(void* pElemento, int idCliente)
{
	int retorno = -1;
	Cliente * clienteAux = (Cliente*)pElemento;
	int idAux ;
	char nombreAux[128];
	char apellidoAux[128];
	char cuitAux[128];
	if (cliente_getIdCliente(clienteAux, &idAux)==0 && idAux == idCliente)
	 {
		cliente_getNombreCliente(clienteAux, nombreAux);
		cliente_getApellidoCliente(clienteAux, apellidoAux);
		cliente_getCuitCliente(clienteAux, cuitAux);
		printf("\n|  ID| Nombre    |Apellido      |  Cuit   |");
		printf("\n %04d | %-10s |  %-10s | %-16s | ", idAux, nombreAux, apellidoAux, cuitAux);
		 retorno = 0;
	 }

	return retorno;
}






