/*
    Assignment name : max
    Expected files : max.c 
    Allowed functions: 
 -------------------------------------------------------------------------------- 
    Write the following function: int max(int* tab, unsigned int len); The first parameter
    is an array of int, the second is the number of elements in the array.

    The function returns the largest number found in the array. If the array is empty, 
    the function returns 0.
*/

int		max(int* tab, unsigned int len)
{
    int i;
    int max;

    i = 0;
    if (len == 0)
        return (0);
    max = tab[0];
    while(i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}

/*
#include <stdio.h>

int main(void)
{
    int nums[] = {5, 2, 9, -3, 10, 4};
    int result = max(nums, 6); // Llamamos a la función y guardamos el resultado

    printf("El número máximo es: %d\n", result); // Mostramos el resultado
    return 0;
}
*/
