/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>

- Recorrer la lista desde el inicio.
- Comparar cada nodo usando la función cmp(node->data, data_ref).
- Si cmp devuelve 0, significa que el dato es igual a data_ref → entonces elimina el nodo.
- Libera la memoria del nodo usando free.
- Ajusta los punteros para que la lista siga correctamente conectada.
- Continúa hasta el final de la lista.

prev → es el nodo anterior al actual.
current → el nodo actual que estamos examinando.
temp → auxiliar para guardar el nodo a eliminar y luego liberarlo con free.
*/

#include <stdlib.h>

// Primero necesitamos la definición de t_list
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp;
    t_list *prev;
    t_list *current;

    // PASO 1: Eliminar nodos al principio que coincidan con data_ref
    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        temp = *begin_list;           // Guarda el nodo a eliminar
        *begin_list = (*begin_list)->next;  // Avanza el inicio de la lista
        free(temp);                   // Libera el nodo
    }

    // PASO 2: Si la lista quedó vacía, terminamos
    if (!*begin_list)
        return;

    // PASO 3: Inicializar para recorrer el resto de la lista
    prev = *begin_list;               // prev apunta al primer nodo (que no coincide)
    current = prev->next;             // current apunta al segundo nodo

    // PASO 4: Recorrer el resto de la lista
    while (current)
    {
        if (cmp(current->data, data_ref) == 0)  // Si el nodo actual coincide
        {
            temp = current;           // Guarda el nodo a eliminar
            prev->next = current->next;  // Conecta el nodo anterior con el siguiente
            free(temp);               // Libera el nodo actual
            current = prev->next;     // Actualiza current al siguiente de prev
        }
        else  // Si no coincide, avanzamos ambos punteros
        {
            prev = current;           // Avanza prev
            current = current->next;  // Avanza current
        }
    }
}