/*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts 
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	newc;
	int		i;
	int		j;
	int		space;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return(1);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		str = argv[i];
		while (str[j])
		{
			newc = str[j];
			space = is_space(str[j + 1]) || str[j + 1] == '\0';

			if (newc >= 'A' && newc <= 'Z')
				newc += 32;

			if (newc >= 'a' && newc <= 'z' && space)
				newc -= 32;

			write(1, &newc, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

/*
    Esta función comprueba si son carácteres, si lo son convierte todas las letras a minúscula menos el 
    último carácter de cada palabra. Puede aceptar más de un argumento.
    RESUMEN PASO A PASO:
    Recorre cada cadena que se pasa por argumento
    Convierte todas las letras a minúscula
    Detecta la última letra de cada palabra (basado en que lo que sigue no es una letra)
    Convierte solo esa última letra a mayúscula
    Imprime todo con saltos de línea
*/
