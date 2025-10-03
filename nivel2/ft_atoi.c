/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

int ft_isspace(char c)
{
    return (c >= 9 && c <= 13 || c == 32);
}

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return(0);
}

int	ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (ft_isspace(str[i]))
        i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
    while (ft_isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
/*
#include <unistd.h>

int main ()
{
    const char *str = "hola";
    int i = 0;

    while(str[i])
    {
        ft_atoi(str[i]);
        i++;
    }
    write (1, &str, 1);

}
*/

/*
Utilizamos dos funciones auxiliares, una es para gestionar los espacios y la otra para saber si es un dígito o no
La función principal:
Declaramos 3 variables:
    Result = 0, sign = 1 e i = 0
Si hay espacios iniciales, los saltamos
Comprobamos el signo del número en caso de ser negativo, ponemos un - delante
Comprobamos si es un dígito -> mientras que sea un dígito
        Result = result * 10 + (str[i] – ‘0’)
Devuelve el resultado multiplicado por el signo.
*/