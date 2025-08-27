/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

Reciba una cadena de caracteres (char *str)
La divida en palabras
Devuelva las palabras como un array de strings
terminado en NULL **out

💡 Conceptos clave:
Array de punteros: char ** (array de strings)
Memoria dinámica: Usar malloc para el array y cada string
NULL-terminated: El array debe terminar con NULL
Delimitadores múltiples: Espacios, tabs,
saltos de línea, inicio y final de cadena.
*/

