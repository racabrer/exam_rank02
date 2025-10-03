/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/
#include <unistd.h>
#include <stdio.h>

char    *ft_strrev(char *str)
{
    int i;
    int len;
    int temp;

    i = 0;
    len = 0;

    while (str[len])
        len++;
    while(i < len - 1)
    {
        temp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = temp;
        i++;
        len--;
    }
    return (str);
}

int	main(void)
{
	char s[] = "Hello World";
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}

/*
Invierte un string en el lugar (modifica directamente la cadena original)
-Declaramos tres variables:
    i-> iterador
    len->calcula el tamaño del string
    temp-> variable temporal para hacer el intercambio de caracteres
-Inicializamos i y len a cero

PROCESO DE INVERTIR LA CADENA
-Mientras que i sea menor que len -1 (-1 es por ‘\0’) . 
Lo que vamos a hacer es intercambiar los caracteres desde los extremos hacia el centro.
(Str[i] es el carácter desde el que vamos a comenzar
str[len - 1] es el carácter desde el final)
-guardamos temporalmente el carácter ubicado en la posición i de la cadena str dentro de la variable temp
-copiamos el carácter del final de la cadena en la posición de inicio
-completamos el intercambio entre los dos caracteres. Usamos temp para 
    poner el carácter original de str[i] en la posición final.
i++
len--
Devuelve str que ya está invertida -> return (str)
*/