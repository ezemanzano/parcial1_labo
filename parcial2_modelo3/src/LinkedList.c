#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this=(LinkedList*)malloc(sizeof(LinkedList));
	if (this!=NULL)
	{
		this->pFirstNode=NULL;
		this->size=0;
	}
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int retorno=-1;
	if (this!=NULL)
	{
		retorno=this->size;
	}
return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int len = ll_len(this);
	Node* nodeAux=NULL;
	if (this!=NULL && nodeIndex>=0 && nodeIndex<len)
	{
		nodeAux=this->pFirstNode;
		for(int i = 0;i<nodeIndex;i++)
		{
			nodeAux=nodeAux->pNextNode;
		}

	}
	return nodeAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node * pNode = (Node*)malloc(sizeof(Node));
    Node * lastNode;
    if (this!=NULL && pNode!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
    	pNode->pElement=pElement;
		if (nodeIndex==0)
		{
			pNode->pNextNode = this->pFirstNode;
			this->pFirstNode=pNode;
		}
		else
		{
			lastNode=getNode(this, nodeIndex-1);
			pNode->pNextNode=lastNode->pNextNode;
			lastNode->pNextNode=pNode;
		}
		this->size++;
		returnAux=0;
    }
    return returnAux;
}
/*else if (nodeIndex==len)
    			{
    				lastNode=getNode(this, nodeIndex-1);
    				lastNode->pNextNode = pNode;
    				pNode->pNextNode=NULL;
    				this->size++;
    				returnAux=0;
    			}*/

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *pElemen
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 *///nodeAux=NULL;
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    if (this!=NULL && len>=0)
    {
     	addNode(this,len,pElement);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correc//nodeAux=NULL;tamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node * nodeAux;
    int len = ll_len(this);
    if (this!=NULL && index<len && index>=0)
    {
    	nodeAux=getNode(this, index);
    	if (nodeAux!=NULL)
    	{
    		return nodeAux->pElement;
    	}

    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node * nodeAux;
    if (this!=NULL&& index<len && index>=0)
    {
    	nodeAux=getNode(this, index);
    	if (nodeAux!=NULL)
    	{
    		nodeAux->pElement=pElement;
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* nodeAux=NULL;
    Node* nodePrev=NULL;
    if (this!=NULL&& index<len && index>=0)
    {
    	nodeAux=getNode(this, index);
    	if (nodeAux!=NULL)
    	{
    		if (index==0)
			{
				this->pFirstNode=nodeAux->pNextNode;
			}
			else
			{
				nodePrev=getNode(this,(index-1));
				if (nodePrev!=NULL)
				{
				nodePrev->pNextNode=nodeAux->pNextNode;
				}
			}
    	}
    	free(nodeAux);
    	this->size--;
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len ;
    if(this!=NULL)
    {
    	len=ll_len(this);
    	if (len>0)
    	{
    		for(int i =len-1;i>=0;i--)
			{
    			ll_remove(this,i);
			}
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	ll_clear(this);
     	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    void * elementAux=NULL;
    if(this!=NULL)
    {
    	len = ll_len(this);
    	if(len>0)
    	{
    		for(int i = 0; i<len;i++)
			{
    			elementAux=ll_get(this, i);
				if (elementAux==pElement)
				{
					return i;
					break;
				}
			}
    	}

    }

    return returnAux;
}


/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;
    if (this!=NULL)
    {
    	returnAux=1;
    	len=ll_len(this);
    	if(len>0)
    	{
    		returnAux =0;
    	}

    }
    return returnAux;
}
// ***********se puede hacer con pfirstnode==null*******


/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len ;
    if (this!=NULL)
    {
    	len = ll_len(this);
    	if (index>=0 && index<=len)
    	{
    		if(addNode(this,index,pElement)==0)
    		{
    			returnAux=0;
       		}
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

       	if (this != NULL && index >= 0 && index < ll_len(this))
       	{
       		returnAux=ll_get(this, index);
			ll_remove(this, index);
    	 }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{

    int returnAux = -1;
    if (this!=NULL)
    {
    	if (ll_indexOf(this, pElement)!=-1)
		{
			returnAux=1;
		}
		else
		{
			returnAux=0;
		}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
  int returnAux = -1;
  Node * nodeAux;
  int len= ll_len(this);
  int len2 = ll_len(this2);
  int lenAux= len2;

  if(this != NULL && this2 != NULL)
  {
	  returnAux = 0;
	  if (len>=len2)
	  {
		  for(int i = 0; i < len; i++)
		  {
			 nodeAux = ll_get(this2,i);
			 if(ll_contains(this,nodeAux)==1)
			 {
				 lenAux--;
			 }
		  }
		  if (lenAux==0)
		  {
			  returnAux=1;
		  }
	  }
  }
return returnAux;

}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* elementAux;
    if (this!=NULL && from>=0 && to<=ll_len(this) && from<=to)
    {
    	cloneArray=ll_newLinkedList();
    	for (int i = from;i<=to;i++)
    	{
    		elementAux=ll_get(this, i);
    		if(elementAux!=NULL)
    		{
    			ll_add(cloneArray,elementAux);
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if (this!=NULL)
    {
    	cloneArray=ll_newLinkedList();
    	if (cloneArray!=NULL)
    	{
    		cloneArray=ll_subList(this, 0, ll_len(this));
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{

	    int returnAux =-1;
	    void* elementX;
	    void* elementY;
	    int flagSwap = 1;

	    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
	    {
	        while(flagSwap)
	        {
	            flagSwap = 0;
	            for (int i = 0; i < (this->size-1); i++)
	            {
	                elementX = ll_get(this, i);
	                elementY = ll_get(this, i+1);
	                if(elementX != NULL && elementY != NULL &&
	                	((pFunc(elementX,elementY)<0 && order ==0 )||
						(pFunc(elementX,elementY)>0 && order ==1 )))
	                {
	                    ll_set(this, i, elementY);
	                    ll_set(this, i+1, elementX);
	                    flagSwap = 1;
	                }
	            }
	        }
	        returnAux = 0;
	    }
	    return returnAux;
	}

/** \brief Elimina los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */


int ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	int returnAux=-1;
	Node * nodoAux;
	if (this!=NULL && pFunc!=NULL)
	{
		for (int i = 0 ;i<ll_len(this);i++)
		{
			nodoAux=ll_get(this, i);
			if (pFunc(nodoAux)==1)
			{
				ll_remove(this, i);
				i--;
				returnAux=0;
			}
		}
	}
	return returnAux;
}

/** \brief Recorre los elementos de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux =-1;
    int len = ll_len(this);
    void* pElemento;
    if(this!=NULL)
    {
    	for (int i = 0;i<len;i++)
    	{
    		pElemento=ll_get(this, i);
    		pFunc(pElemento);
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Reduce la lista a un Entero
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int * prResutlado -> puntero donde devuelve el valor final
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

int ll_reduceInt(LinkedList* this, int (*pFunc)(void*), int * pResultado)
{
    int returnAux =-1;
    int len = ll_len(this);
    void* pElemento;
    int resultado=0;
    if(this!=NULL)
    {

    	for (int i = 0;i<len;i++)
    	{
    		pElemento=ll_get(this, i);
    		resultado= resultado+pFunc(pElemento);
    		*pResultado=resultado;
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Reduce la lista a un Entero
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int * prResutlado -> puntero donde devuelve el valor final
 * \param int idCliente -> idcliente al cual se le quiere hacer el rduce
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

int ll_reduceIntbyID(LinkedList* this, int (*pFunc)(void*,int), int * pResultado, int idCliente)
{
    int returnAux =-1;
    int len = ll_len(this);
    void* pElemento;
    int resultado=0;
    if(this!=NULL)
    {

    	for (int i = 0;i<len;i++)
    	{
    		pElemento=ll_get(this, i);
    		resultado= resultado+pFunc(pElemento,idCliente);
    		*pResultado=resultado;
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Reduce la lista a un Float
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param float * prResutlado -> puntero donde devuelve el valor final
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

float ll_reduceFloat(LinkedList* this, float (*pFunc)(void*), float * pResultado)
{
    float returnAux =-1;
    int len = ll_len(this);
    float resultado=0;
    void* pElemento;
    if(this!=NULL)
    {
    	returnAux=0;
    	for (int i = 0;i<len;i++)
    	{
    		pElemento=ll_get(this, i);
    		resultado = resultado + pFunc(pElemento);
    		returnAux=0;
    		*pResultado = resultado;
    	}

    }
    return returnAux;
}


/** \brief Reduce la lista a un Float
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param float * prResutlado -> puntero donde devuelve el valor final
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

int ll_filterByInt(LinkedList* this, int (*pFunc)(void*,int),int Cobradas)
{
	int returnAux=-1;
	Node * nodoAux;
	if (this!=NULL && pFunc!=NULL)
	{
		for (int i = 0 ;i<ll_len(this);i++)
		{
			nodoAux=ll_get(this, i);
			if (pFunc(nodoAux,Cobradas)==1)
			{
				ll_remove(this, i);
				i--;
				returnAux=0;
			}
		}
	}
	return returnAux;
}



/** \brief Recorre los elementos de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param int indice -> indice a buscar donde el map se detendrà al encontrarlo en la lista
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */


int ll_mapAndBreak(LinkedList* this, int (*pFunc)(void*,int),int indice)
{
    int returnAux =-1;
    int len = ll_len(this);
    void* pElemento;

    if(this!=NULL)
    {
        for (int i = 0;i<len;i++)
        {
            pElemento=ll_get(this, i);
            if(pFunc(pElemento,indice)==1)
            {
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}


