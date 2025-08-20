/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j;

	if (argc == 3)
	{
		while (argv[1][i]) // Va carácter por carácter verificando si ese carácter existe en argv[2].
		{
			j = 0;
			while (argv[2][j] && argv[2][j] != argv[1][i]) //Recorre argv[2] hasta encontrar una coincidencia o llegar al final.
				j++;
			if (!argv[2][j]) // Si no lo encuentra, termina
			{
				write(1, "\n", 1); //imprime salto de línea
				return (1); //termina
			}
			i++;
		}
		write(1, argv[1], i); // Escribe en la pantalla (1) los primeros i caracteres de la cadena argv[1]
	}
	write(1, "\n", 1);
	return (0);
}
// Tiene que encontrar s1 en s2. Completo, si no está en orden o no contiene TODO, sale