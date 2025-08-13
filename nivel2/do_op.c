#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 4)
    {
        if (*argv[2] == '+')
            printf("%d", atoi(&argv[1][i]) + atoi(&argv[3][i]));
        else if (*argv[2] == '-')
            printf("%d", atoi(&argv[1][i]) - atoi(&argv[3][i]));
        else if (*argv[2] == '*')
            printf("%d", atoi(&argv[1][i]) * atoi(&argv[3][i]));
        else if (*argv[2] == '/')
            printf("%d", atoi(&argv[1][i]) / atoi(&argv[3][i]));
        else if (*argv[2] == '%')
            printf("%d", atoi(&argv[1][i]) % atoi(&argv[3][i]));
    }
    printf("\n");
    return (0);
}