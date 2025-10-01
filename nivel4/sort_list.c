/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
**sort_list recorre una lista enlazada y ordena sus elementos usando una función de comparación (cmp).
Si dos elementos no están en orden, intercambia sus valores (data) y vuelve al inicio.
Así, garantiza que toda la lista quede ordenada según el criterio definido por cmp.
La función devuelve el primer nodo de la lista ya ordenada.**

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};
*/


typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *start = lst;
    int swap;

    while(lst && lst->next)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = start;
        }
        else
            lst = lst->next;
    }
    return start;
}

/*
Pseudocódigo:
Función sort_list(lst, cmp):

    Mientras la lista no esté completamente ordenada:
        Inicializa un puntero actual al inicio de la lista
        
        Mientras actual y actual->next existen:
            Si cmp(actual->data, actual->next->data) == 0:
                // El orden no es correcto, así que intercambiamos los datos
                Intercambia actual->data y actual->next->data
            Mueve actual al siguiente nodo

    Retorna lst (inicio de la lista).

Paso a paso:

Creamos dos variables:
    "t_list *start" que la inicializamos a lst y otra variable de tipo int "swap" que nos va a ayudar a ordenar nuestra lista.
Mientras que el nodo actual y el nodo siguiente exista, seguimos iterando.
Llamamos a la función cmp con los valores de los nodos actuales.
- Si cmp devuelve 0, el par está fuera de orden, así que hay que intercambiar.
- Si cmp devuelve distinto de 0, están bien, no se hace nada.
Intercambiamos los valores de lst y lst->next
Después del intercambio, reiciciamos  el puntero lst al inicio de la lista para volver a revisar desde el principio
Si los elementos están ordenados, avanza al siguiente par.
Si terminamos de recorrer sin hacer ningún intercambio, la lista está ordenada
Devuelve start que está en el primer nodo
Imprime 
\n
fin del programa

Pasos (resumen):

1. Guardamos el principio de la lista
2. Mientras haya nodos para comparar
3. Usamos la función cmp para saber si los dos números están ordenados
    Si los dos números están mal ordenados (cmp devuelve 0)
4. Intercambiamos los números si están mal ordenados.
    Esto hace dos cosas:
        4.1 Cambia los valores de los nodos.
        4.2 Vuelve al principio de la lista para revisar todo otra vez,
            porque después de cambiar algo, puede que se desordene algo antes.
5. Si están bien ordenados, avanzamos al siguiente par.
6. Devuelvo la lista ordenada. 
    Devuelvo la lista desde el principio (que guardamos en start)




*/

