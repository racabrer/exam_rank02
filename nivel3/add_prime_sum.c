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

void ft_putnbr(int nb)
{
    char c;
    if (nb >= 10)
        ft_putnbr(nb / 10);
    c = nb % 10 + '0';
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int is_prime(int n)
{
    int i = 2;
    if (n < 2)
        return 0;
    while (i * i <= n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    int i = 2;
    int sum = 0;
    int num;

    if (argc != 2)
    {
        write(1, "0\n", 2);
        return 0;
    }

    num = ft_atoi(argv[1]);
    if (num <= 0)
    {
        write(1, "0\n", 2);
        return 0;
    }

    while (i <= num)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }

    ft_putnbr(sum);
    write(1, "\n", 1);
    return 0;
}
