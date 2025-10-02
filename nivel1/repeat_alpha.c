/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int j;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            j = 0;
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                j = 0;
                while (j < argv[1][i] - 64)
                {
                    write (1, &argv[1][i], 1);
                    j++;
                }
            }
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                j = 0; 
                while (j < argv[1][i] - 96)
                {
                    write(1, &argv[1][i], 1);
                    j++;
                }
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

/*
    Esta función repite cada carácter según el número que le corresponde en el orden del abecedario 
    "a" -> a, "b" -> bb, "c" -> ccc y así sucesivamente.

    Declaramos dos variables, una para iterar los argumentos 
    y otra para calcular cuántas veces tenemos que repetir el carácter
    Comprobamos el número de argumentos
    Recorremos argv 
        Hacemos dos bucles if, uno para las mayúsculas y otro para las minúsculas.
        El proceso es el mismo para ambos, solo cambian los números ascii
        mayúsculas -> 65 - 90 minúsculas -> 97 - 122
        Si argv está entre a (o A) y z (o Z)
            Reinicia j a 0 ** ESTE PASO ES ESENCIAL **
            Mientras que j sea menor que argv[1][i] - 64 (o 89)
                write(1, &argv[1][i], 1)
                Avanza en j (j++)
        Sino
            Escribe argv
        i++
    \n
    Fin del programa
*/