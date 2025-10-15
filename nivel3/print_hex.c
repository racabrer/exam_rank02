/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '\t')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!(str[i] >= '0' && str[i] <= '9'))
	    return (-1);    
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
            i++; 
        }
        else 
            return (0);
    }
    return (result * sign);
}

void print_hex(unsigned int nb)
{
    char *base = "0123456789abcdef";

    if (nb >= 16)
        print_hex(nb / 16);
    write(1, &base[nb % 16], 1);
}

int main(int argc, char **argv)
{
    int number;

    if (argc == 2)
    {
        number = ft_atoi(argv[1]);
        if (number >= 0)
            print_hex((unsigned int)number);
    }
    write(1, "\n", 1);
    return (0);
}


/*
otra versión:

#include <unistd.h>

void print_hex_number (int n)
{
    char c;

    if (n >= 16)
        print_hex_number(n / 16);
    c = n % 16;
    if (c < 10)
        c = '0' + c;
    else
        c = 'a' + c - 10;
    write(1, &c, 1);
}


int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i]>= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result);
}

int main (int argc, char **argv)
{
    int num = 0;

    if (argc == 2)
    {
        num = ft_atoi(argv[1]);
        if (num == 0)
            write(1, "0", 1);
        else
            print_hex_number(num);
    } 
    write(1, "\n", 1);
    return (0);
}
*/


/*

void print_hex_number(n)
    si n ≥ 16
        llamar recursivamente a print_hex_number(n / 16)

    calcular residuo = n % 16

    si residuo < 10
        escribir carácter ('0' + residuo)
    si no
        escribir carácter ('a' + residuo - 10)
fin función

ft_atoi -> hacer una función ft_atoi

función main(argumentos)
    si número de argumentos ≠ 1
        escribir '\n'
        salir del programa

    convertir argumento[1] a número entero → num

    si num == 0
        escribir '0'
    si no
        llamar a función recursiva print_hex_number(num)

    escribir '\n'
fin función

** en mi repo tengo un atoi completo pero no es necesario más que que funcione para si son dígitos.

*/