/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

void ft_putnbr(int nb)
{
    char c;

    if (nb >= 10)
        ft_putnbr(nb / 10);
    c = (nb % 10) + '0';
    write(1, &c, 1);
}


int main (int argc, char **argv)
{
    int i = 1;

    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write (1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write (1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(i);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}

/*

Usamos la función auxiliar putnbr para imprimir números 
Creamos una variable "n" y la inicializamos a 1
Mientras que n sea menor o igual a 100
    - Si n es múltiplo de 3, imprime "fizz"
    - Si n es múltiplo de 5, imprime "buzz"
    - Si n es múltiplo de 3 y de 5, imprime "fizzbuzz"
    - Sino, imprime el número que corresponda
********IMPORTANTE********
Escribir salto de línea
Avanza en i.


*/