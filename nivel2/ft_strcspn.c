/* 
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

     The strspn() function spans the initial part of the null-terminated
     string s as long as the characters from s occur in the null-terminated
     string charset.  In other words, it computes the string array index of
     the first character of s which is not in charset, else the index of the
     first null character.

Esta función compara s con reject, si hay coincidencia, devuelve el tamaño
de lo que se ha recorrido de s hasta la coincidencia
*/

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i; 
    size_t j;

    i = 0;
    while (s[i])
    { 
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}


/*
    Esta función busca una coincidencia de *s en *reject.
    Recorremos la cadena *s con el iterador i.
        -Mientras que recorremos la cadena s[i], empezamos a recorrer reject con el iterador j.
            -Si encuentra una coincidencia, devuelve i que es la posición en la que han coincidido.
        Avanza en j (j++)
    Avanza en i (i++)
    Si no ha encontrado una coincidencia devuelve i que es el tamaño de *s

    *Dato importante, tenemos que añadir #include <stddef.h> porque la función utiliza size_t*

*/