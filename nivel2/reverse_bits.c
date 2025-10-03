/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100
*/

unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char byte = 0;
    unsigned int i = 8;

    while(i--)
    {
        byte = (byte << 1) | (octet & 1);
        octet = octet >> 1;
    }
    return (byte)
    
}

/*
Esta función toma un número de 8 bits que en este caso es octet e invierte el orden de sus bits.
-Declaramos dos variables
Un unsigned char byte = 0y un unsigned int i = 8
-Recorre i hacia atrás 
    (Cada vez que el bucle se ejecuta, i se decrementa, y el bucle se repite 8 veces (para cada bit del octeto)).
byte = (byte << 1) | (octet & 1)

Desplaza los bits de byte una posición a la izquierda (byte << 1), preparando espacio para el siguiente bit.
(octet & 1) obtiene el bit menos significativo de octet (el bit más a la derecha).
Luego, con | (OR bit a bit), coloca este bit en el espacio más a la izquierda de byte.
octet = octet >> 1;:
Desplaza los bits de octet una posición a la derecha para procesar el siguiente bit en la siguiente iteración.
Retornamos byte que tiene los bits de octet invertidos
*/