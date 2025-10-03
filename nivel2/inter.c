/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
    int i = 0;
    int lookup[256] = {};

    if (argc == 3)
    {
        while(argv[1][i])
        { 
            int j = 0;
            while(argv[2][j])
            {  
                while((argv[1][i] == argv[2][j]) && !lookup[(argv[1][i])])
                {
                    lookup[(argv[1][i])] = 1;
                    write(1, &argv[1][i], 1);
                }
                j++;
            }
        i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

/*
Este programa, recibe dos strings y sin que se repitan los caracteres,
escribe las coincidencias, tienen que mantener el orden del primer string para que sea válido
Declaramos tres variables:
    i-> es un iterador para recorrer la primera cadena
    j-> otro iterador que recorre la segunda cadena
    lookup[256] = {} -> esto representa una tabla que contiene todos los valores de ascii
     y va marcando los caracteres que ya han coincidido para que no se repitan
-Comprobamos el número de argumentos
    -Recorremos la primera cadena
        -Recorremos la segunda
            -Mientras que ambas sean iguales y  lookup no está activado
                - Igualamos a 1 la posición de lookup porque hemos encontrado una coincidencia
                - write(1, &argv[1][i], 1);
            j++
        i++;
\n
Return 0
*/