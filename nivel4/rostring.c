/*
Nombre de la asignación: rostring
Archivos esperados: rostring.c
Funciones permitidas: write, malloc, free
--------------------------------------------------------------------------------

Escriba un programa que tome una cadena y la muestre después de rotarla una palabra a la izquierda.

De esta manera, la primera palabra se convierte en la última y las demás permanecen en el mismo orden.

Una "palabra" se define como una parte de una cadena delimitada por espacios/tabuladores o por el inicio/fin de la cadena.

Las palabras se separarán solo por un espacio en la salida.

Si hay menos de un argumento, el programa muestra \n.

Ejemplo:

$>./rostring "abc " | cat -e
abc$
$>
$>./rostring |
la lumiere soit et la lumiere fut Que
$>
$>./rostring " AkjhZ zLKIJz , 23y"
zLKIJz , 23 y AkjhZ
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' '|| c == '\t');
}

int main (int argc, char **argv)
{
    int i = 0;
    int printed = 0;
    int start = 0;
    int end = 0;

    if (argc > 1)
    {
        while(ft_isspace(argv[1][i]))
            i++;
        start = i;
        while(argv[1][i] && !ft_isspace(argv[1][i]))
            i++;
        end = i;
        while(argv[1][i] && ft_isspace(argv[1][i]))
            i++;
        while(argv[1][i])
        {
            while(argv[1][i] && !ft_isspace(argv[1][i]))
            {
                write(1, &argv[1][i], 1);
                i++;
                printed = 1;
            }
            while(argv[1][i] && ft_isspace(argv[1][i]))
                i++;
            if (argv[1][i])
                write(1, " ", 1);
        }
        if (printed)
            write(1, " ", 1);

        while (start < end)
        {
            write(1, &argv[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
    return(0);
}


























