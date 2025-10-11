/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>

char    *ft_strdup(char *src)
{
    char *tmp;
    int len = 0;
    int i = 0;
    
    while (src[len])
        len++;
    tmp = malloc(sizeof(char) * len + 1);
    if (!tmp)
        return (NULL);
    while(src[i])
    {
        tmp[i] = src[i];
        i++;
    }
    tmp[i] = '\0';
    return(tmp);
}

/*
Esta función duplica un string y devuelve un puntero a la nueva cadena.
Declaramos tres variables:
    Char *temp -> donde guardaremos la cadena
    Int len -> tamaño de la cadena
    Int i -> iterador
Recorremos la cadena hasta el final con len -> len++ -> contendrá el tamaño del string
Asignamos espacio con malloc al string temporal temp y hacemos la comprobación de malloc
Mientras que exista src
    Copiamos el valor de src en la variable temporal tmp = src
    i++
Añadimos un cero al final a temp
Devuelve temp. Que es la copia del string.
*/