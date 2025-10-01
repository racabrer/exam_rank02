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

/*
Esta función recorre cada uno de los strings y comprueba carácer por carácer
si s1 se encuentra dentro de s2 pero en el mismo orden 
Si s1 está en s2, imprime s1. 
Paso a paso:
1. Decalaramos dos variables "i" y "j" que son los iteradores que vamos a usar para recorrer las cadenas
2. Inicializamos a cero ambas variables.
3. Comprobamos el número de argumentos.
	4. Recorremos s1
		5. Mientras s2 exista y sea distinto de s1, avanza en j (j++).
			6. Si !s2 (no lo encuentra)
				6.1 Imprime salto de línea 
				6.2 Retorna 1
			7. Avanza en i (i++)
	8. (Fuera del while s1)
		Imprime argv[1], importante:
			- No imprimimos argv[1][i], como solemos hacer
			----> write(1, argv[1], i); *****esto es así porque imprime los i primeros caracteres del string*******
	9. \n
	10. return (0).
*/