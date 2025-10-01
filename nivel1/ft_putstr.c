#include <unistd.h>

void	ft_putstr(char *str)
{
    int i = 0;

    while(str[i])
        write(1, &str[i++], 1);
}
/*int main ()
{
    char str[] = "Cristian";

    ft_putstr(str);
    return (0);    
}
*/


/*
    Esta función escribe un string
    Creamos una variable para iterar el string
    Mientras exista str, lo recorremos y lo imprimimos con write.
*/