#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
#include "ventas.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile -> puntero al file
 * \param pArrayListEnvios LinkedList* -> puntero al array
 * \return int
 *
 */


int parser_clientesFromText(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	int r;
	char var[64],var2[128],var3[128],var4[128];
	if (pArrayListEnvios!=NULL && pFile!=NULL)
	{
		do
		{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",var,var2,var3,var4);
		if (r==4)
			{
				Cliente * clienteAux= cliente_new();
				if (clienteAux!=NULL)
				{
				clienteAux=cliente_newParam(atoi(var),var2,var3,var4);
				if (clienteAux!=NULL)
				{
				ll_add(pArrayListEnvios, clienteAux);
				retorno=0;
				}

				}
				else
				{
					printf("error\n");
					retorno=-1;
				}

			}

		} while (!feof(pFile));
	fclose(pFile);
	}
	else
	{
		printf("\n No se encontro el archivo");
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile -> puntero al file
 * \param pArrayListVentas LinkedList* -> puntero al array
 * \return int
 *
 */


int parser_ventasFromText(FILE* pFile , LinkedList* pArrayListVentas)
{
	int retorno = -1;
	int r;

	char var[64],var2[128],var3[128],var4[128],var5[128],var6[128];
	if (pArrayListVentas!=NULL && pFile!=NULL)
	{
		do
		{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]",var,var2,var3,var4,var5,var6);
		if (r==6)
			{
				Ventas * ventasAux= ventas_new();
				if (ventasAux!=NULL)
				{
					ventasAux = ventas_newParam(atoi(var),atoi(var2), atoi(var3),var4 , atoi(var5),atoi(var6));
				    if (ventasAux!=NULL)
				    {
					ll_add(pArrayListVentas, ventasAux);
					retorno=0;
					}

				}
				else
				{
					printf("error\n");
					retorno=-1;
				}

			}

		} while (!feof(pFile));
	fclose(pFile);
	}
	else
	{
		printf("\n No se encontro el archivo");
	}

	return retorno;
}







