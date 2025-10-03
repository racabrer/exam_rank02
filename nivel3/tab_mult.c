/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	num;
	int	i;
	int	res;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	num = ft_atoi(argv[1]);
	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(num);
		write(1, " = ", 3);
		res = i * num;
		ft_putnbr(res);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

/*
Este programa muestra la tabla de multiplicar del número que le pases por terminal
Utilizamos dos funciones auxiliares:
	atoi y putnbr
En el main:
	Declaramos tres variables:
	num -> es el número por el que vamos a multiplicar
	i -> iterador para recorrer los números del 1 al 9
	res -> devuelve el resultado.
Comprobamos el número de argumentos 
comvertimos argv[1] con atoi 
inicializamos i a 1
mientras que i sea menor o igual a 9
	escribe el número 
	escribe el signo "x"
	escribe el número
	escribe "="
	hace la operación correspondiente -> res = i * num
	escribe el resultado
	\n
	avanza en i
devuelve 0
*/