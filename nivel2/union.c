/*Escriba un programa que tome dos cadenas y muestre, sin dobles, 
el caracteres que aparecen en cualquiera de las cadenas.

La pantalla se mostrará en el orden en que aparecen
los caracteres en la línea de comando y
irá seguido de un \n.

Si el número de argumentos no es 2, el programa muestra \n.

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union "padre" "madre" | cat -e
padrem$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int lookup[256] = {};

    if (argc == 3)
    {
        while(argv[1][i])
        {
            if (argv[1][i] && !lookup[argv[1][i]])
            {
                write(1, &argv[1][i], 1);
                lookup[argv[1][i]] = 1;
            }
            i++;
        }
        i = 0;
        while(argv[2][i])
        {
            if (argv[2][i] && !lookup[argv[2][i]])
            {
                write(1, &argv[2][i], 1);
                lookup[argv[2][i]] = 1;
            }
            i++;
        }

    }
    write(1, "\n", 1);
    return (0);
}
