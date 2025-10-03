/*
/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.

** ft_rrange(int start, int end)
** Crea un array dinámico de enteros.
** Llena ese array con valores consecutivos desde end hasta start, incluyendo ambos.
** Si end > start, los números disminuyen.
** Si end < start, los números aumentan.
** Devuelve un puntero al primer elemento del array.
*/

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int size;
    int *range;
    int i = 0;

    if (start > end)
        size = start - end + 1;
    else
        size = end - start + 1;
    
    range = malloc(sizeof(int) * size);
    if (!range)
        return (NULL);
    
    while (i < size)
    {
        range[i] = end;
        if (end < start)
            end++;
        else
            end--;
        i++;
    }
    return (range);
}

opcion2

int     *ft_range(int start, int end)
{
    int len;
    int *result;
    int i = 0;

    if (start <= end)
        len = (end - start) + 1;
    else
        len = (start - end) + 1;
    result = malloc(sizeof(int) * len);
    if (!result)
        return (NULL);
    if (start <= end)
    {
        while(i < len)
        {
            result[i] = end - i;
            i++;
        }
    }
    else
    {
        while(i < len)
        {
            result[i] = end + i;
            i++;
        }
    }
    return (result);
}


/*
La función rrange genera un array de enteros desde start hasta end
en orden DECRECIENTE si start > end
o en orden CRECIENTE si start <= end
Declaramos tres variables:
    Size ->tamaño del rango
    *Range-> rango del array
    i -> iterador
-Comprobamos si el orden es ascendente o descendente y calculamos el tamaño del rango
 en función de si start > end o si  start < end
- Asignamos espacio a range con malloc y hacemos su comprobación
Mientras que i sea menor que el tamaño del rango
    -asignamos el valor actual de end en la posición i del array (range[i] = end)
    - Si end < start ---> incrementa end
    - sino ---à decrementa end
    i ++
Devuelve el rango.
(esta es la explicación de la primera de las opciones de ft_rrange)
*/