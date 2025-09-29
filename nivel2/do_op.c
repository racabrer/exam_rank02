/*
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 4)
    {
        if (*argv[2] == '+')
            printf("%d", atoi(&argv[1][i]) + atoi(&argv[3][i]));
        else if (*argv[2] == '-')
            printf("%d", atoi(&argv[1][i]) - atoi(&argv[3][i]));
        else if (*argv[2] == '*')
            printf("%d", atoi(&argv[1][i]) * atoi(&argv[3][i]));
        else if (*argv[2] == '/')
            printf("%d", atoi(&argv[1][i]) / atoi(&argv[3][i]));
        else if (*argv[2] == '%')
            printf("%d", atoi(&argv[1][i]) % atoi(&argv[3][i]));
    }
    printf("\n");
    return (0);
}


/*
    Necesitamos crear un programa que recibe tres strings e identifica el símbolo de la operación que tiene que hacer,
    la ejecuta y la imprime (es como una calculadora).

    Creamos una variable i y la inicializamos a cero
    Comprobamos el número de argumentos 
    Si *argv[2] que representa el símbolo de la operación que tetenos que hacer es == a (añade símbolo), hace la operación 
    que corresponda.
        Imprimimos con printf en la misma línea que hacemos la operación.
    Hacemos lo mismo para todas las operaciones posibles '+', '-', '/', '%', '*'
    Imprimimos un salto de línea 
    Fin del programa.

    *cosas a tener en cuenta*
        argv[2] -> va como *argv[2].
        En la conversión con atoi(), necesitamos añadir & delante del argumento -> atoi(&argv[1][i]). También necesitamos el iterador.
        Cuando pasamos los argumentos por terminal, necesitamos pasarlos como " " -> "2" "*" "4"
*/