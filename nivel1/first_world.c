/* Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$> */

#include <unistd.h>

int ft_isspace (char c)
{
    return (c == ' ' || c == '\t');
}

int main (int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {   
        while (ft_isspace(argv[1][i]))
            i++;
        while (argv[1][i] && !ft_isspace(argv[1][i]))
            write(1, &argv[1][i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}

/*
Utilizamos una función auxiliar para gestionar los espacios
En el main:
- Declaramos una variable “i” para iterar nuestro argv
- Comprobamos el número de argumentos
    //Aquí vamos a “acotar” la primera palabra por sus
    espacios y vamos a imprimir solo hasta el primer espacio
    - Mientras sea un espacio (si hay espacios iniciales los ignoro)
        i++
    -Mientras que argv exista y que no sea un espacio
        Escribimos la palabra
        i++
\n
Fin del programa
*/