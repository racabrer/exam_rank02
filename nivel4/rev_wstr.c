/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <unistd.h>

int main(int argc, char **argv)
{
	int start;
	int end;
    int flag;
	int i = 0;

	if (argc == 2)
	{
		while(argv[1][i] != '\0')
			i++;
		while(i >= 0)
		{
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			flag = start;
			while(start <= end)
			{
				write (1, &argv[1][start], 1);
				start++;
			}
			if (flag !=0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}

/*
Este programa da la vuelta al orden de las palabras de un string.

Declaramos 4 variables:
	start y end -> se utiliza para acotar el principio y el final de cada palabra
	flag -> se utiliza para saber si hay que escribir un espacio o no. 
		Se activa cuando hemos impreso la palabra
	i -> iterador para recorrer la cadena.
Comprobamos el número de argumentos
	Recorremos la cadena hasta el final
	Mientras que i sea menor o igual a cero
		Mientras que sea el final del string = '\0' ||
		sea un espacio || sea un tab
			retrocede
		end = i establecemos la posición de end
		Mientras que exita argv y NO sea un espacio o un tab
			retrocede en i
		start = i + 1 -> establecemos el valor de start
		Igualamos la flag de start en i + 1
		Mientras que start sea menor o igual que end
			escribe el argumento desde start
			start++
		Si la flag no está activada
			Escribe el espacio
	\n

	
*/