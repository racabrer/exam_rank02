/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>

Paso a paso:

Creamos una auxiliar para saltar espacios
Declaramos dos variables, un contador y una flag. Ambas las inicializo a cero
Saltamos los espacios al principio
Recorremos el array
    Si es un espacio, marcamos la flag en 1
    Else 
        -> Primer if (space)
            write " "
        -> Dentro del else pero fuera del if
            space = 0
            escribimos el carácter actual
        i++;
    \n
    return 0;
*/

#include <unistd.h>

int ft_isspace (char c)
{
    return (c == ' ' || c == '\t');
}

int main (int argc, char **argv)
{
    int i = 0;
    int space = 0;

    if (argc == 2)
    {
        while(ft_isspace(argv[1][i]))
            i++;
        while(argv[1][i])
        {
            if (ft_isspace(argv[1][i]))
                space = 1;
            else
            {
                if (space)
                    write(1, " ", 1);
                space = 0;
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}