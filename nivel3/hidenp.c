/*Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
/
*/

int main (int argc, char **argv)
{
    int i = 0;
    int j = 0;

    if (argc == 3)
    {
        while (argv[2][j])
        {
            if (argv[1][i] && argv[1][i] == argv[2][j])
                i++;
            j++;
        }
        if (argv[1][i] == '\0')
            write(1, "1", 1);
        else 
            write(1, "0", 1);
    }
    write(1, "\n", 1);
    return (0);
}


/*
    Esta función busca si s1 está contenida en s2. Si esto es así, devuelve 1. Sino, devuelve 0.

    Declaramos dos variables i y j, los inicializamos a cero, utilizamos i para recorrer argv[1] 
    utilizamos j para recorre argv[2]. 

    comenzamos recorriendo argv[2]
        Si argv[1][i] existe y argv[1][i] y argv[2][i] son iguales
            Avanzamos en i (i++)
        Avanzamos en j (j++)
    Si argv[1][i] es igual al diablito ('\0'), es decir si argv[1] ha llegado hasta el final, escribimos 1
    En caso contrario, escribimos 0
    Salto de línea
    Fin del programa
*/