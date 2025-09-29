/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c :

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/


typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
    int i = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        i++;
    }
    return i;
}


/*
    Esta función calcula el tamaño de una lista enlazada, avanza por la lista desde el primer nodo
    hasta que next llega a NULL. Tenemos un contador (i) que en cada iteración aumenta en 1, cuando llega al final, 
    devuelve el tamaño de la lista.

    paso a paso:
    Declaramos una variable i (que será nuestro contador) y la inicializamos a cero
    Mientras que exista begin_list 
        igualamos begin_list a next. Es decir recorremos los nodos uno a uno
        Aumentamos el contador (i++).
    Devolvemos el contador, que es el tamaño de la lista
*/