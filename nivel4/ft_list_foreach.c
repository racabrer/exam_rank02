/*
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

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


void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)  // Mientras el nodo actual no sea NULL
    {
        (*f)(begin_list->data);        // Aplica la función al dato del nodo actual
        begin_list = begin_list->next; // Avanza al siguiente nodo
    }
}

/*
Esta función recorre una lista enlazada y aplique una función f a cada elemento de la lista
Aplicamos la función f a cada nodo de la lista
*/