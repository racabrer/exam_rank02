#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            if ((argv[1][i] >= 65 && argv[1][i] <= 77) || (argv[1][i] >= 97 && argv[1][i] <= 109))
                argv[1][i] += 13;
            else if ((argv[1][i] >= 78 && argv[1][i] <= 90) || (argv[1][i] >= 109 && argv[1][i] <= 122))
                argv[1][i] -= 13;
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}

/*
    Recorre una cadena y para cada carácter lo intercambia por su posicion + 13 o -13 
    dependiendo de su posición en el abecedario.
    Los 13 primeros tanto de mayúsculas como de minúscula +13,
    Los 13 últimos tanto de mayúsculas como de minúscula -13
*/