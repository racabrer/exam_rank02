/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

size_t	ft_strspn(const char *s, const char *accept)
{
    int i = 0;
    int j;
    int check;

    while(s[i])
    {
        j = 0;
        check = 0;
        while(accept[j])
        {
            if (s[i] == accept[j])
                check = 1;
            j++;
        }
        if (check == 0)
            return (i);
        i++;
    }
    return (i);
}

/*
La función recorre las dos cadenas comparándolas y devuelve el número de caracteres comunes
 desde el principio de s. Los caracteres tienen que ser consecutivos, 
 en el momento que encuentra uno que no coincide (que no se encuentra en accept), para.
 ******devuelve esa cantidad como size_t******
-Declaramos tres variables:
i -> recorre la cadena s, -> inicializamos al principio
j -> recorre la cadena accept
Check -> es una flag que verifica si el carácter actual de s[i] está en accept
-recorremos s[i]
    -inicializamos j y Check a 0
    -recorremos accept[j]
        Si s[i] es igual a accept[j]
            Activamos la flag Check porque hemos encontrado coincidencia
        Avanzamos en j (en accept y seguimos comparando)
    -Si Check es cero
        Devolvemos i que es la cantidad que ha coincidido
    i++
Sino, devuelve i porque es que toda la cadena s se encontraba en accept.
*/