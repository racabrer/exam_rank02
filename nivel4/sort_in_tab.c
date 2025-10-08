/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.

Compara pares de elementos del array.
Si están en el orden incorrecto, los intercambia.
Repite el proceso hasta que el array esté ordenado.

*/

void sort_int_tab(int *tab, unsigned int size)
{
    int tmp;
    unsigned int i;
    unsigned int j;

    i = 0;
    while (i < size - 1)
    {
        j = i;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

/*
La función sort_int_tab tiene como objetivo ordenar un array de enteros (tab)
de tamaño size en orden ascendente.
Utilizando el algoritmo de ordenación por burbuja.

La función recibe dos parámetros: 
1. tab : un puntero a un arreglo de enteros
2. size: un número entero sin signos que indica cuántos elementos tiene el array

El objetivo es ordenar el tab de manera ascendente sin utilizar ningún espacio adicional.
ALGORITMO:
Se comparan elementos del array por pares y se intercambian si están en el orden correcto.
Se repite este proceso hasta que el array está completamente ordenado.

PASO A PASO:

Creamos 3 variables: 
   Temp -> Una variable temporal para hacer los cambios
   i y j -> iteradores para recorrer el array

    Primer bucle (i)
        while(i < size - 1). Recorre desde el principio hasta el penúltimo elemento.
    Segundo bucle (j)
        El segundo ciclo (while(j < size)) compara el elemento tab[i] con los elementos posteriores
        al array.
        -> Compara y realiza el intercambio
            - Si tab[i] > tab[j], intercambia ambos con temp.
        Intercambio:
            - Guarda el valor de tab[i] en temp.
            - Asigna el valor de tab[j] a tab[i]
            - Finalmente, coloca el valor almacenado en temp en tab[j].
        Avanzamos en j
        Avanzamos en i
    El proceso continúa hasta que todos los elementos han sido comparados.
*/