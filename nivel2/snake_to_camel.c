/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
*/

#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        while(argv[1][i])
        {
            if (argv[1][i] == '_')
            {
                i++;
                argv[1][i] -= 32;
            }
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
/*
    OTRA VERSIÓN QUE TAMBIÉN PASA GRADEME 

    int main (int argc, char **argv)
    {
        int i; 
        i = 0;

        if(argc == 2)
        {
            while(argv[1][i])
            {
                while (argv[1][i] >= 65 && argv[1][i] <= 90)
                    argv[1][i] += 32;
                while(argv[1][i] == '_')
                {
                    i++;
                    argv[1][i] -= 32;
                }
                write(1, &argv[1][i], 1);
                i++;
            }
        }
        write(1, "\n", 1);
        return(0);
    }
*/

/*
    Tenemos que pasar una cadena que está en formato "snake_case" a formato "lowerCamelCase"
    Declaramos una variable i, que es el iterador con el que vamos a recorrer la cadena
    Comprobamos el número de argumentos 
    Mientras que haya alguna letra en mayúscula, la pasamos a minúscula
    Mientras argv[1][i] sea igual a '_' 
        Avanzamos una posición en i y convertimos la letra a mayúscula.
    Escribimos argv
    Avanzamos en i (i++)
    Salto de línea
    Fin del programa
*/