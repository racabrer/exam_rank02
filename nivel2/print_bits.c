/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned int  i;
	unsigned char bit;

	i = 8;
	bit = 0;

	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write (1, &bit, 1);
	}
}

/*
	Declaramos dos variables de tipo unsigned una tipo int(i) y la otra de tipo char (bit)
	Inicializamos las variables, int = 8 y bit = 0;
	Mientras que i va disminuyendo 
		Extraemos un bit específico del valor octet y convertimos ese caracter a 0 ó 1.
		Imprimimos con write
*/