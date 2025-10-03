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


/*
Este programa, recibe dos strings y sin que se repitan los caracteres,
escribe los coincidentes y los no coincidentes tienen que mantener
el orden del primer string para que sea válido
Declaramos dos variables:
i-> es un iterador para recorrer la primera cadena
lookup[256] = {} 
    -> esto representa una tabla que contiene todos los valores de ascii 
    y va marcando los caracteres que ya han coincidido para que no se repitan
-Comprobamos el número de argumentos
    -Recorremos la primera cadena
        Si argv existe y lookup no está activado
            Escribe el carácter
            Lookup = 1
        Avanza en i (i++)
    -Reiniciamos i
Volvemos a hacer el mismo proceso pero en la segunda cadena
    Mientras que el segundo string
        Si el segundo string existe y existe y lookup no está activado
            Escribe el carácter
            Lookup = 1
        i ++
\n y fin del programa
*/