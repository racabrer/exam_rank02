/*Escribe una función que reciba una cadena de caracteres y la muestre en orden inverso, seguida de un salto de línea.
El prototipo de la función debe ser:

char *ft_rev_print(char *str);

La función debe devolver el mismo puntero recibido como argumento.
Solo se permite usar la función write (no se puede usar printf, puts, etc.).*/

#include <unistd.h>

char *ft_rev_print(char *str)
{
    int i = 0;

    while(str[i])
        i++;
    i--;
    while(i >= 0)
    {
        write(1, &str[i], 1);
        i--;

    }
    write(1, "\n", 1);
    return(str);
}

/*int main()
{
    char str[] = "piloto";

    ft_rev_print(str);

    return (0);

}*/

/*
    En el examen es distinto 
    Recorremos la cadena hasta final y desde ahí retrocede
    Mientras que i es mayor o igual a cero,
        imprime str[i]
        i--
    Salto de línea
    Devuelve la cadena.
*/