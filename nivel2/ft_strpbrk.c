/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

STRPBRK(3) (simplified)

NAME
     strpbrk –- locate multiple characters in string
LIBRARY
     Standard C Library (libc, -lc)
SYNOPSIS
     #include <string.h>
     char *strpbrk(const char *s, const char *charset);

DESCRIPTION
     The strpbrk() function locates in the null-terminated string s the first
     occurrence of any character in the string charset and returns a pointer to this
     character.  If no characters from charset occur anywhere in s strpbrk()
     returns NULL.
RETURN VALUES
     The strpbrk() function return a pointer to the first occurence of any character
     in the string,if no characters occur anywhere in s, strpbrk() returns NULL.
*/

#include <stdio.h> 

char	*ft_strpbrk(const char *s1, const char *s2)
{
     int i = 0;
     int j;

     while(s1[i])
     {
          j = 0;
          while(s2[j])
          {
               if (s1[i] == s2[j])
                    return ((char *) &s1[i]);
               j++;
          }
          i++;
     }
     return(NULL);
}

/*
Esta fusión busca en una cadena s1 el primer carácter que también esté presente en otra cadena s2,
si lo encuentra, devuelve un puntero a ese carácter dentro de s, si no lo encuentra, devuelve NULL
Declaramos dos variables que son iteradores i y j
Mientras s1[i]
     Mientras s2[j]
          Si s1[i] y s2[j] son iguales
               Devuelve ((char *) &s1[i])
               ( -> puntero al carácter, importante hacer el casteo )
          Avanzamos en j (j++)
     Avanzamos en i (i++)
Sino devuelve NULL, en este caso será que no hemos encontrado coincidencia.
*/
