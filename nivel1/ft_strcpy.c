/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);

*/

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;

    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return(s1);
}

/*
Esta función copia s2 en s1.
Mientras que s2 exista
    Copio carácter por carácter s2 en s1
    Avanzo en i
Añado el '\0' al final
Devuelvo s1 que es la copia de s2
*/