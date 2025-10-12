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

#include <stdlib.h>

char	*ft_strncpy(char *s1, char *s2, int n)
{
    int i = 0;

    while(i < n && s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

char    **ft_split(char *str)
{
    int		word_count = 0; // contador de palabras
	int		new_word = 0; // índice temporal que guarda dónde empieza la siguiente palabra
	int		i = 0; //índice para recorrer str
	int		j = 0; //índice para rellenar el array out
	char 	**out = 0; //array de strings || Guarda el resultado de todas las palabras separadas

    //BLOQUE 1:
    while(str[i])
    {
        while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (str[i])
            word_count++;
        while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
    }
    //BLOQUE 2:
    i = 0;
    out = (char **)malloc(sizeof(char *) * (word_count + 1));
    if(!out)
        return (NULL);
    
    //BLOQUE 3:
    while(str[i])
    {
        while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        new_word = i;
        while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        if (i > new_word)
        {
            out[j] = (char *)malloc(sizeof(char) * (i - new_word) + 1);
            if (!out)
                return NULL;
            ft_strncpy(out[j++], &str[new_word], i - new_word);
        }
    }   
    out[j] = NULL;
    return out;
}


/*
	Creamos una función auxiliar ft_strncpy (char	*ft_strncpy(char *s1, char *s2, int n)
	para copiar "n" caracteres de s2 a s1.
		Declaramos un iterador (i) para recorrer las cadenas (usamos el mismo para las dos).
		Mientras que no se hayan copiado n caracteres y el carácter actual de s2 no sea nulo ('\0')
		copiamos todos los caracteres de s2 a s1 (mientras que i sea menor que n y s2[i] exista)
		(Esto garantiza que solo se copian hasta n caracteres y se detiene antes si s2 se acaba.)
			Copia -> s1[i] = s2[i]
			i++
		s1[i] = '\0' (Añadimos '\0' al final de s1 para asegurarse que la cadena está bien terminada.)
		return (s1) -> retorna un puntero al comienzo de s1.

	FUNCIÓN PRINCIPAL:

	char	**ft_split(char *str):
	Declaramos 5 variables. 
		int		word_count -> contador de palabras
		int		new_word -> índice temporal que guarda dónde empieza la siguiente palabra
		int		i -> índice para recorrer str
		int		j -> índice para rellenar el array out
		char 	**out -> array de strings || Guarda el resultado de todas las palabras separadas
	
	Voy a dividir la función en bloques.

	BLOQUE 1: Contamos las palabras

	Recorremos str[i]
		- Mientras que exista s1[i] y sea: " " || "\t" || "\n" 
			- avanza i (i++)
		- Si str[i]
			word_count++ ---> Cuenta una palabra
		- Mientras que str[i] exista y NO sea:  " " || "\t" || "\n" 
			- avanza i (i++)

	BLOQUE 2:

	Reiniciamos el iterador i a 0.
	Asignamos espacio al array out -> tamaño word_count + 1. 
	En este malloc necesitamos hacer un casteo previo ->
		out = (char **)malloc(sizeof(char *) * (word_count + 1));
	Comprobamos malloc

	BLOQUE 3:

	Recorremos str[i]
		- Mientras exista str[i] y sea: " " || "\t" || "\n" 
			- avanza en i (i++)
		- new_word = i  ---> 1ª posición de la siguiente palabra
		- Mientras exista str[i] y NO sea: " " || "\t" || "\n"
			- avanza en i (i++)
		** Extraemos y copiamos una palabra desde el original str hasta un array de cadenas (out)**
		- Si (i > new_word)
			-> Reservamos memoria para la nueva cadena (i - new_word) es la cantidad 
				de caracteres de la palabra + 1 (para '\0')
					out[j] = (char *)malloc(sizeof(char) * (i - new_word) + 1)
					comprobamos malloc
			-> Llamamos a la función strncpy -> se copian los caracteres de la palabra
				desde str[new_word] hasta str[i - 1] dentro de out[j]: j++
		- Añadimos NULL a out[j] -> out[j] = NULL;
		- Devuelve out.
		
		*******ACLARACIÓN**********
		- out[j++] -> 
		 	out es un arreglo de cadenas |
		 	j++ indica que se accede a la posición j de out, 
			y luego se incrementa j para la siguiente iteración.
			Entonces, la cadena copiada se guarda en out[j].
		- &str[new_word] -> 
			str es la cadena original de entrada.
			new_word es un índice donde comienza una nueva palabra en str.
			Al hacer &str[new_word], estás pasando un puntero al inicio de esa palabra
		- i - new_word ->
			i es el índice actual en str.
			new_word es donde comenzó la palabra.
			Entonces i - new_word es la longitud de la palabra.
			Se copia esa cantidad de caracteres.

	out[j] = NULL -> se añade un NULL para marcar el fin del array
	return out
*/