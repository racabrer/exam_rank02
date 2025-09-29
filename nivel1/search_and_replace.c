/*
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $
*/

#include <unistd.h>

int main(int argc, char **argv)
{

    int i = 0;

    if (argc == 4)
    {

        if (argv[2][1] != '\0' || argv[3][1] != '\0')
        {
            write(1, "\n", 1);
            return (1);
        }
        while (argv[1][i])
        {
            if (argv[1][i] == argv[2][0])
                argv[1][i] = argv[3][0];
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}

/*
Comprobamos el número de argumentos 
comprobamos que la posición 1 de argv[2] y argv[3] sea '\0' porque solo pueden contener un caracter.
(Si argv[2][1] != '\0' || argv[3][1] != '\0', devuelve cero.) -> esta parte es importante porque siempre se me olvida 
que además de retornar cero, necesitas imprimir un salto de línea.
en esta comprobación imprimimos un salto de línea y finaliza el programa.
Recorremos el argv[1][i]
    Mientras que argc[1] sea igual a argv[2] 
    igualamos el valor de argv[1] en argv[3]
    imprimimos argv[1][i]
    avanzamos en i.
\n
Fin del programa
*/