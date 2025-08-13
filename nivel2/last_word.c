/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i])
        i++;
    return (i);
}

int main (int argc, char **argv)
{
    int i;
    int len;
    int end;

    if (argc == 2)
    {
        len = ft_strlen(argv[1]) - 1;
        i = len;
        while (ft_isspace(argv[1][i]))
            i--;
        end = i;
        while(!ft_isspace(argv[1][i]))
            i--;
        i++;
        while (i <= end)
            write(1, &argv[1][i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}