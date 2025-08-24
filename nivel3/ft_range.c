/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

Calcular el tamaño del array
La cantidad de números que debe tener el array es:
    valor absoluto de (end - start) + 1

Esto es porque queremos incluir ambos extremos, tanto start como end.

Ejemplos:

start = 3, end = 5 → tamaño = 5 - 3 + 1 = 3

start = 5, end = 3 → tamaño = 5 - 3 + 1 = 3

2. Reservar memoria
Reservar memoria para un array de enteros con ese tamaño usando malloc

3. Llenar el array con los valores

Aquí hay dos caminos:

a) Si start <= end (rango ascendente):
Desde i = 0 hasta tamaño - 1:
    array[i] = start + i

b) Si start > end (rango descendente):
Desde i = 0 hasta tamaño - 1:
    array[i] = start - i

4. Retornar el puntero al array
Devolver el puntero que apunta al array recién creado

IMPORTANTE

Debes usar solo malloc como función permitida.

Es importante manejar bien el caso de start > end.

También asegúrate de incluir tanto el valor inicial como el final.
*/
int *ft_range(int start, int end)
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
        range[i] = start;
        if (end < start)
            start--;
        else
            start++;
        i++;
    }
    return (range);
}


opcion2

#include <stdlib.h>

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
            result[i] = start + i;
            i++;
        }
    }
    else
    {
        while(i < len)
        {
            result[i] = start - i;
            i++;
        }
    }
    return (result);
}


