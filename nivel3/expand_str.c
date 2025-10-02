/*
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

#include <unistd.h>

int ft_isspace(char c)
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
        while (argv[1][i])
        {
            if (ft_isspace(argv[1][i]))
                space = 1;
            else
            {
                if (space)
                    write (1, " ", 1);
                space = 0;
                write(1, &argv[1][i], 1);                
            }
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}
/*

    Utilizamos una función auxiliar para gestionar los espacios.

    Esta función devuelve un string en el que hay tres espacios entre palabras.
    - Declaramos dos variables i (iterador), space (flag) y las inicializamos a cero.
    - Comprobamos el número de argumentos.
        - Si hay espacios iniciales, los ignoramos
    - Mientras argv[1]
        - si hay un espacio, ponemos en 1 la flag space
        - sino
            -si la flag space está activa
                - imprime un espacio
            -Reinicia la flag space
            -escribe argv
        avanza en i (i++)
    \n
    Fin del programa return (0);     
*/