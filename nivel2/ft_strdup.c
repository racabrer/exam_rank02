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
    tmp[i] = 0;
    return(tmp);
}
