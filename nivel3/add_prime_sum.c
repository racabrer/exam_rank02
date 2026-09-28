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

int ft_isdigit(int c)
{
    return(c >= '0' && c <= '9');
}

int is_positive_number(char *str)
{
    int i = 0;

    if (!str || str[0] == '\0')
        return (0);
    while(str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    i = 0;
    while (str[i] == '0')
        i++;
    if (str[i] == '\0')    
        return (0);
    return (1);
       
}

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
 
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - 48);
        i++;
    }
    return (result);
}

int ft_isprime(int nb)
{
    int i = 2;
   
    if (nb <= 1)
        return (0);
    while (i * i <= nb)
    {
        if (nb % i == 0) //no es primo
            return (0);
        i++;
    }
    return (1);
}

void ft_putnbr(int nb)
{
    char c;

    if (nb >= 10)
        ft_putnbr(nb / 10);
    c = nb % 10 + 48;
    write(1, &c, 1);
}

int main(int argc, char **argv) 
{
    int i;
    int num;
    int sum; 
    
    i = 2; 
    sum = 0; 
    if (argc == 2) 
    {
        if (!is_positive_number(argv[1])) 
        {
            write(1, "0\n", 2);
            exit(0); 
        } 
        num = ft_atoi(argv[1]); 
        while (i <= num) 
        { 
            if (ft_isprime(i)) 
                sum += i;
            i++; 
        } 
        ft_putnbr(sum); 
        write(1, "\n", 1); 
    } 
    else 
        write(1, "0\n", 2); 
}
