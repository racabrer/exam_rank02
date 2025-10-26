/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

int    ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;

    if (!s1)
        return (-1);
    if (!s2)
        return (1);
    while(s1[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
Esta función compara s1 y s2
Para ello crea inicializa una variable i que va a utilizar como iterador para recorrer ambas cadenas
Mientras que exista s1 o s2 y que s1 sea igual a s2
    Avanzamos en i
Devolvemos la diferencia entre s1 y s2 haciendo previamente un cast a s1 y s2
*/