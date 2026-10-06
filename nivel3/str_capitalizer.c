/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/
#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

int main (int argc, char **argv)
{
    int i;
    int j;
    int new_word;

    if (argc == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    while(i < argc)
    {
        j = 0;
        new_word = 1;
        while (argv[i][j])
        {
            if (new_word && argv[i][j] >= 'a' && argv[i][j] <= 'z')
                argv[i][j] -= 32;
            else if (!new_word && argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                argv[i][j] += 32;
            write(1, &argv[i][j], 1);
            if (ft_isspace(argv[i][j]))
                new_word = 1;
            else
                new_word = 0;
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}

/*
Hay que pensar en que te pueden pasar uno o más argumentos, por eso argv[j][i]
Declaramos tres variables, dos son iteradores y la otra una flag
Comprobamos el número de argumentos que en este caso tiene que ser al menos 2
j empieza en 1 porque argv como mínimo será 1
Mientras que j sea menor que argc, entramos 
*/

/*
    Necesitamos poner en mayúsculas la primera letra de cada palabra
    Podemos recibir más de un argumento.
    Lo primero que hacemos es declarar tres variables:
    j  = 1 -> para iterar en los distintos argumentos (empieza en 1 porque cero es el nombre del programa)
    i  = 0-> para iterar dentro de cada argumento como tal
    new_word  = 1-> flag para saber si tenemos que poner la letra en mayúsculas o no
        empieza en 1 porque necesitamos que ponga en mayúsculas la primera letra del string
    
    Comprobamos el número de argumentos
    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }

    while (j < argc) //Cuando hay más argumentos que el nombre del programa
        - Si la letra está en mayúsculas, la pasamos a minúscula 
        - Si la flag new_word está activada y es una letra, la ponemos en mayúsculas
        - Escribimos argv[j][i]

        ACTUALIZAMOS LA FLAG NEW_WORD
        - Si es un espacio:
            - new_word = 1
        - Sino
            - new_word = 0
        Avanza en i
    - Escribe un salto de línea
    - Avanza en j
- Fin del programa
*/
