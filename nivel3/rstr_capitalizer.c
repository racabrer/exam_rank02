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
    Esta función comprueba si son carácteres, si lo son convierte todas las letras a minúscula menos el 
    último carácter de cada palabra. Puede aceptar más de un argumento.
    RESUMEN PASO A PASO:
    Recorre cada cadena que se pasa por argumento
    Convierte todas las letras a minúscula
    Detecta la última letra de cada palabra (basado en que lo que sigue no es una letra)
    Convierte solo esa última letra a mayúscula
    Imprime todo con saltos de línea

*/

#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int main(int argc, char *argv[])
{
    int i;
    int j;
    int space;

    if (argc == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            space = is_space(argv[i][j + 1]) || argv[i][j + 1] == '\0';

            if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                argv[i][j] += 32;

            if (argv[i][j] >= 'a' && argv[i][j] <= 'z' && space)
                argv[i][j] -= 32;

            write(1, &argv[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}

/*
	Utilizamos una función auxiliar para gestionar los espacios.
	En la función principal:
	Declaramos 5 variables:
		- char *str -> string actual que estamos procesando
		- char newc -> carácter actual, modificado(por si hay que cambiar mayúsculas o minúsculas)
		- int i -> índice para recorrer los argumentos (empezamos en 1)
		- int j -> índice para recorrer los caracteres de cada argumento
		- int space -> flag para marcar si es un espacio

	- Comprobamos el número de argumentos (porque puede recibir más de 1)
		Si el número de argumentos es 1, devuelve salto de línea y 1
	- Inicializamos i en 1.
	- Mientras que i sea menor que argc
		- inicializo j en cero
		- inicializo str a argv[i] -> Tomamos el argumento actual (str = argv[i])
		- Recorremos str con el iterador j -> str[j] 
			- Guardo una copia del carácter actual del string str en la variable newc -> newc = str[j]

									***ACLARACIÖN***

		Esto se hace así porque queremos modificar ese carácter 
		(convertirlo a minúscula, o a mayúscula si es la última letra de una palabra) 
		Sin cambiar el string original.

									****************
			- Comprobamos si la siguiente posición es ' ' || '\t' || '\0'
			- Comprobamos si str[j] es mayúscula o minúscula para cambiarlas 
			- Imprimo &newc
			- j++
		- Escribo \n
		- i++
	devuelve \n
 
		

*/

