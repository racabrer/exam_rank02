/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100

*/

unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4 | octet << 4));
}

/*
Esta función intercambia los 4 bits superiores con los 4 bits inferiores de un byte.
octet >> 4  -> desplaza los 4 bits más significativos que son los primeros 4 bits de octet hacia la derecha, 
esto deja a los 4 bits menos significativos como cero
| es el operador OR que combina los resultados                 
octet << 4 -> desplaza los 4 bits menos significativos del byte octet hacia la izquierda 
  y coloca los 4 inferiores (más a la izda.)
*/