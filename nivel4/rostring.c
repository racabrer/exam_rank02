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

/*
#include <unistd.h>

int main (int ac, char **av)
{
    int i = 0;
    int printed = 0;

    if (ac == 2)
    {
        // Saltar espacios iniciales
        while (av[1][i] == 32 || av[1][i] == 9)
            i++;
        int start = i;

        // Buscar el fin de la primera palabra
        while (av[1][i] && av[1][i] != 32 && av[1][i] != 9)
            i++;
        int end = i;

        // Saltar espacios después de la primera palabra
        while (av[1][i] == 32 || av[1][i] == 9)
            i++;

        // Imprimir las demás palabras
        while (av[1][i])
        {
            while (av[1][i] && av[1][i] != 32 && av[1][i] != 9)
            {
                write(1, &av[1][i], 1);
                i++;
                printed = 1;
            }

            // Saltar espacios entre palabras
            while (av[1][i] == 32 || av[1][i] == 9)
                i++;

            if (av[1][i] && printed)
                write(1, " ", 1);
        }

        // Solo imprimir espacio si ya hubo otra palabra antes
        if (start < end)
        {
            if (printed)
                write(1, " ", 1);
            while (start < end)
                write(1, &av[1][start++], 1);
        }
    }
    write(1, "\n", 1);
    return 0;
}

*/

#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int printed;

    if (argc == 2)
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        int start = i;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        int end = i;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while(argv[1][i])
        {
            while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                write(1, &argv[1][i], 1);
                i++;
                printed = 1;
            }
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (argv[1][i] && printed)
                write(1, &argv[1][i], 1);
        }
        while (start < end)
        {
            if (printed)
                write(1, " ", 1);
            while(start < end)
                write(1, &argv[1][start++], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}




























