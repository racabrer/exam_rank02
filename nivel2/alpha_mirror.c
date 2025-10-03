/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/

#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        while(argv[1][i])
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
                argv[1][i] = 90 - argv[1][i] + 65;
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
                argv[1][i] = 122 - argv[1][i] + 97;
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}


/*
    Esta función cambia cada carácter de una cadena por su opuesto.
    Creamos una variable i para iterar y la inicializo a cero.
    Mientras argv[1]
    Si es mayúscula -> argv[1][i] = 90 - argv[1][i] + 65;
        - Esto es porque a el valor ascii de Z le restamos el valor actual de argv[1][i] y le sumamos el valor de A
            ej: 90 - 66 + 65 = 89 -> Y
    Si el minúscula hago lo mismo pero con los valores que corresponden a la minúscula
    Imprime 
    Avanza en i
    \n
    Fin del programa.
    
    */