/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    if (argc == 3)
    {
        unsigned int num1;
        unsigned int num2;
        unsigned int temp;

        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);

        if (num1 == 0 || num2 == 0)
            return(0);

        while(num2 != 0)
        {
            temp = num1 % num2;
            num1 = num2;
            num2 = temp;
        }
        printf("%d", num1);
    }
    printf("\n");
    return (0);
}

/*

pgcd - es el máximo común divisor de dos números
Que es el número más grande que divide ambos sin dejar resto.
De las funciones permitidas, vamos a utilizar solamente dos: atoi y printf


Comprobamos el número de argumentos
Declaramos dos variables de tipo int. num1 y num2.
Convertimos las variables con atoi pero ***es importante que lo hagamos dentro
de la comprobación del número de argumentos.***
Si ambos números son mayores que 0
    - Mientras que los números no sean iguales
        Si num1 es mayor que num2
            num1 = num1 - num2
        Sino
            num2 = num2 - num1
     imprimimos con print num1.
    \n
    fin del programa

    ** ACLARACIÓN RANDOM **

    En este caso, imprimimos n1 pero podríamos poner n2 y el resultado sería el mismo.
    Ambos números son iguales al MCD, esto es debido al algoritmo que estamos usando.

    Si number1 es mayor que number2, se le resta a number1 a number 2
        -> number1 = number1 - number2
    Si number2 es mayor que number1, se resta a number2, number1
        -> number2 = number2 - number1
    Esto continúa hasta que number1 == number2. 
        En este punto ambos números son iguales y contienen el MCD de los dos números inciales.
*/