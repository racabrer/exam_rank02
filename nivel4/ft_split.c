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
	int	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	char	**out;
	int		word_count;
	int		new_word;
	int		i;
	int		j;

	word_count = 0;
	new_word = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			word_count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	i = 0;
	out = (char **)malloc(sizeof(char *) * (word_count + 1));
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		new_word = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > new_word)
		{
			out[j] = (char *)malloc(sizeof(char) * ((i - new_word) + 1));
			ft_strncpy(out[j++], &str[new_word], i - new_word);
		}
	}
	out[j] = NULL;
	return (out);
}