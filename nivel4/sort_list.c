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

#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int printed;

    if (argc == 2)
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        int start = i;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        int end = i;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while(argv[1][i])
        {
            while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                write(1, &argv[1][i], 1);
                i++;
                printed = 1;
            }
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (argv[1][i] && printed)
                write(1, &argv[1][i], 1);
        }
        while (start < end)
        {
            if (printed)
                write(1, " ", 1);
            while(start < end)
                write(1, &argv[1][start++], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}