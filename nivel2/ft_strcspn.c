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

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j;

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
