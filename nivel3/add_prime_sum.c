/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' '|| c == '\t');
}

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    while(ft_isspace(str[i]))
        i++;
    while(str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (sign * result);
}

void ft_putnbr(int nb)
{
    char c;

    if (nb >= 10)
        ft_putnbr(nb / 10);
    c = nb % 10 + 48;
    write(1, &c, 1);
}

int is_prime(int n)
{
    int i = 2;

    if (n <= 1)
        return (0);
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return(1);
}

int main(int argc, char **argv)
{
    int num; 
    int i = 2;
    int sum = 0;

    if (argc == 2)
    {
        num = ft_atoi(argv[1]);
        if (num <= 0)
        {
            write(1, "0", 1);
            return (0);
        }
        while(i <= num)
        {
            if (is_prime(i))
                sum += i;
            i++;
        }
        ft_putnbr(sum);
    write(1, "\n", 1);        
    }
    else
    {
    write(1, "0\n", 2);
    return (0);
    }
}

/*
Necesitamos crear 4 funciones auxiliares (en realidad pueden ser solo 3 si hacemos un atoi simplificado)
ft_isspace -> para gestionar los espacios de ft_atoi
ft_atoi -> para convertir el argumento de la función principal en un número
is_prime -> la utilizamos para saber si un número es primo o no.

is_prime:
Esta función verifica si un número n es primo:
    - descartamos los números menores o iguales a 1 (no son primos).
    - Luego verifica si hay algún divisor i desde 2 hasta la raíz cuadrada de n (i * i <= n).
        - Si encuentra un divisor (n % i == 0), 
            - devuelve 0 (no es primo).
        - i++
    - Si no encuentra divisores, devuelve 1 (es primo).

Función principal:

Declaramos tres variables:
int num -> el número que le vamos a pasar 
int i = 2 -> empieza en 2 porque es el primer número primo
int sum = 0 -> usamos esto para el resultado de la suma

- Comprobamos el número de argumentos
    - convertimos el argumento con atoi -> num
    - Si el número (num) es menor o igual a cero
        - imprime cero y sale
    - Mientras i (2) es menor o igual que num 
        - Si es primo (i)
            - le suma i a sum
        i++
    -escribe num con ft_putnbr
- escribe salto de línea
else
    Escribe cero y salto de línea
    devuelve cero
*/