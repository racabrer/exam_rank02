#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

int main (int argc, char **argv)
{
    int i = 0;
    int start;
    int end;
    int printed;

    if (argc == 2)
    {
        while (ft_isspace(argv[1][i]))
            i++;
        start = i;
        while (argv[1][i] && !ft_isspace(argv[1][i]))
            i++;
        end = i;
        while (ft_isspace(argv[1][i]))
            i++;
        
        while(argv[1][i])
        {
            while(ft_isspace(argv[1][i]))
                i++;
            if (!argv[1][i])
                break;
            if (printed)
                write(1, " ", 1);
            while (argv[1][i] && !ft_isspace(argv[1][i]))
                write(1, &argv[1][i++], 1);
            printed = 1;
            if (start < end)
            {
                if (printed)
                    write(1, " ", 1);
                while (start < end)
                    write(1, &argv[1][start++], 1);
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}


    /*
    Función aux isspace 

    Primer bloque:
        3 while:
            1. Ignoramos los espacios del principio y guardamos la posición de i en start
            2. Verificamos que argv exista y que no hay espacio. Guardamos la posición de i en end para la última letra.
            *primera palabra delimitada*
            3. ignoramos el espacio entre las dos palabras (la primera posición será la primera 
            letra de la siguiente palabra)

    Segundo bloque: 
        Imprimir todas las palabras que van después que la primera en orden.
        1. Recorrer la cadena desde donde lo dejamos.
        2. Saltamos los espacios si hay una sola palabra y si llega al final y no hay otra palabra, break.
        3. El bucle de la flag de printed, en la primera vuelta no entra, entra solo cuando hemos impreso toda argv

    */