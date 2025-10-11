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

EXPLICACIÓN POR FUNCIONES:
    count len:
    len: contador que almacenará la cantidad de caracteres
    n: se guarda nbr como long para evitar errores al manejar INT_MIN
    Cuando convertimos un número con itoa, necesitamos saber el número de caracteres que tiene 
    eso incluye los signos si los tiene.
    Si n es menor o iigual a cero entonces es o cero, que en ese caso es un caracter
    o negativo que en ese caso hay que añadir el signo menos 
    mientras que n sea distinto a cero dividimos n entre 10 y aumentamos len.
    Devolvemos len. 

    ft_itoa:

    


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
        n = -n;
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

/*
    ITOA
    integer to ascii

    Creamos una función auxiliar que nos va a servir para calcular el tamaño del número que vamos a convertir
    int count_len (int nbr)
    count_len:
        - Declaramos dos variables:
        int len -> para calcular el tamaño 
        long (n), que la igualamos al parámetro nbr (esto lo hacemos para los máximos y los mínimos)
 
        - Si n es menor o igual que cero, avanzamos en len (len ++)
        - Mientras que n sea distinto de cero,
            - dividimos entre 10 (descartando el último dígito).
            ->Cada división reduce un dígito, y aumentamos len en 1. (Contamos cuántos dígitos tiene nbr)
        - Devolvemos len que es el tamaño del número.

    char	*ft_itoa(int nbr)

    Declaramos  3 variables:
        int len 
        long n
        char *str
        - Llamamos a la función count_len y calculamos el tamaño de nbr.
        - Reservamos espacio con malloc para str
            con el tamaño de un char * len+1 (char porque la función devuelve char *)
            (+ 1 es porque necesitamos dejar espacio para '\0')
        - Hacemos la comprobación de malloc

        - igualamos n a nbr (porque n es de tipo long y necesita poder gestionar los max y min)
        - Añadimos el '\0' al final de la cadena str[len] -> str[len] = '\0'
        - Si n es menor a cero:
            - si es negativo lo convertimos en positivo en la posición 0 de str -> str[0]
            (n = -n)
        - Si n es igual a cero
        - Se escribe cero en la primera posición str[0]
        - Mientras n sea mayor a cero
            - Convertimos los dígitos del número a caracteres, desde el final hacia el principio
            - (n % 10) obtenemos el último dígito + '0' (o + 48) convertimos a Ascii
            - n /= 10 eliminamos el último dígito del número
        - Repetimos hasta que no queden más dígitos 
        - Devuelve str
*/