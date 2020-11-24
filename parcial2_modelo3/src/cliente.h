/*
 * cliente.h
 *
 *  Created on: Nov 20, 2020
 *      Author: ezemanzano
 */


typedef struct
{
	int idCliente;
	char nombreCliente[128];
	char apellidoCliente[128];
	char cuitCliente[128];

}Cliente;

Cliente* cliente_new(void);
Cliente* cliente_newParam(int idCliente, char * nombreCliente, char * apellidoCliente , char * cuitCliente);
int cliente_getIdCliente(Cliente* this, int * idCliente);
int cliente_setIdCliente(Cliente* this, int idCliente);
int cliente_getNombreCliente(Cliente* this, char * nombreCliente);
int cliente_setNombreCliente(Cliente* this, char* nombreCliente);
int cliente_getApellidoCliente(Cliente* this, char * apellidoCliente);
int cliente_setApellidoCliente(Cliente* this, char* apellidoCliente);
int cliente_getCuitCliente(Cliente* this, char * cuitCliente);
int cliente_setCuitCliente(Cliente* this, char* cuitCliente);

// fn internas

int cliente_noSeRepiteCuit(LinkedList * pArrayListClientes,char * cuitCliente);
int cliente_idExiste (LinkedList * pArrayListClientes, int idCliente);

//fn criterio

int cliente_imprimirTodos(void*thisA);
int cliente_printOne(void* pElemento, int idCliente);
