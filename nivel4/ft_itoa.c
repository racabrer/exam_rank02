/*

Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);

--------------------------------------------------------------------------------

Crea una función que:
Reciba un número entero (int).
Devuelva ese número convertido en texto (char *), como por ejemplo:
42 → "42"
-123 → "-123"
El texto debe terminar con '\0'.
La memoria debe ser reservada con malloc.

                            paso a paso
    ----------------------------------------------------------------
    Contar cuántos caracteres necesitas:
    Usa un bucle que divida nbr por 10 hasta que llegue a 0.
    Si nbr es 0, el resultado debe ser "0" (1 carácter + nulo). 
    Reservar memoria con malloc.
    Convertir el número a texto:
        Tomar cada dígito: digit = abs(nbr % 10) + '0'.
        Guardarlo en la posición correcta.
        Agregar el signo negativo si corresponde.
    Terminar con '\0'.

*/
#include <stdlib.h>

int count_len (int nbr)
{
    int len = 0;
    long n = nbr;

    if (n <= 0)
        len++;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int nbr)
{
    int len;
    char *str;
    long n;

    len = count_len(nbr);
    str = malloc (sizeof (char) * (len + 1));
    if (!str)
        return (NULL);
    n = nbr;

    str[len] = '\0';
    if (n < 0)
    {
        str[0] = '-';
    }
    else
    {
        if (n == 0)
            str[0] = '0';
    }

    while (n > 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}


/*
#include <limits.h> 
#include <stdio.h>


int main(void)
{
    int test_values[] = {0, 42, -42, 12345, -98765, INT_MAX, INT_MIN};
    int count = sizeof(test_values) / sizeof(test_values[0]);
    int i = 0;
    char *str;

    while (i < count)
    {
        str = ft_itoa(test_values[i]);
        if (str)
        {
            printf("ft_itoa(%d) = \"%s\"\n", test_values[i], str);
            free(str);
        }
        else
        {
            printf("Memory allocation failed for %d\n", test_values[i]);
        }
        i++;
    }

    return 0;
}

*/