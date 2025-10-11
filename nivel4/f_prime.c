/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num;
    int i = 2;

    // Verificamos que se pase exactamente un argumento
    if (argc != 2)
    {
        printf("\n");
        return (1);
    }

    // Convertimos el argumento a número entero
    num = atoi(argv[1]);

    // Si el número es menor a 1, no se puede factorizar
    if (num < 1)
    {
        printf("\n");
        return (1);
    }

    // Caso especial: si es 1, solo imprimimos 1
    if (num == 1)
    {
        printf("1\n");
        return (0);
    }
    // Bucle principal: factorización
    while (num > 1)
    {
        if (num % i == 0)
        {
            printf("%d", i);
            num = num / i;
            if (num > 1)
                printf("*");
        }
        else
            i++;
    }
    printf("\n");
    return (0);
}


/*
Si número de argumentos != 2:
    imprimir salto de línea
    salir

Convertir argv[1] a entero n (usando atoi)

Si n == 1:
    imprimir "1\n"
    salir

factor = 2
mientras n > 1:
    si n divisible por factor:
        comprobamos si la flag first está activada, 
            si lo está, imprimimos * porque quiere decir que ya hemos impreso otro factor previamente
        imprimir factor
        dividir n por factor
        si n > 1:
            imprimir '*'
    sino:
        factor = factor + 1
imprimir salto de línea
*/