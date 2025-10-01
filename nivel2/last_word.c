/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i])
        i++;
    return (i);
}

int main (int argc, char **argv)
{
    int i;
    int len;
    int end;

    if (argc == 2)
    {
        len = ft_strlen(argv[1]) - 1;
        i = len;
        while (ft_isspace(argv[1][i]))
            i--;
        end = i;
        while(!ft_isspace(argv[1][i]))
            i--;
        i++;
        while (i <= end)
            write(1, &argv[1][i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}

/*
    Creamos dos funciones auxiliares, una para gestionar los espacios y otra para calcular el tamaño del string
    En la función principal:
    - Creamos tres variables, una para iterar el string, otra para guardar el tamaño y otra para "acotar" el final de la cadena
    - Comprobamos el número de argumentos 
    - Calculamos el tamaño de la cadena -1. -1 por el '\0'
    - Igualamos el valor de i a len
    - Estamos en la última posición. Mientras que sea un espacio, retrocede en i.
    - End = i (ahora estamos en la última posición real, en el último carácter)
    - Mientras que no sea un espacio
        - Retrocedemos en i (i--)
    - Avanzamos en i (i++)
        - Estamos en el primer carácter de la última palabra
    - Mientras que i sea menor o igual al final de la palabra
        imprime
    \n
    fin
*/