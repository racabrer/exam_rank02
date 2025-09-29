/*
Nombre de la asignación: rostring
Archivos esperados: rostring.c
Funciones permitidas: write, malloc, free
--------------------------------------------------------------------------------

Escriba un programa que tome una cadena y la muestre después de rotarla una palabra a la izquierda.

De esta manera, la primera palabra se convierte en la última y las demás permanecen en el mismo orden.

Una "palabra" se define como una parte de una cadena delimitada por espacios/tabuladores o por el inicio/fin de la cadena.

Las palabras se separarán solo por un espacio en la salida.

Si hay menos de un argumento, el programa muestra \n.

Ejemplo:

$>./rostring "abc " | cat -e
abc$
$>
$>./rostring |
la lumiere soit et la lumiere fut Que
$>
$>./rostring " AkjhZ zLKIJz , 23y"
zLKIJz , 23 y AkjhZ
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' '|| c == '\t');
}

int main (int argc, char **argv)
{
    int i = 0;
    int printed = 0;
    int start;
    int end;

    if (argc > 1)
    {
        while(ft_isspace(argv[1][i]))
            i++;
        start = i;
        while(argv[1][i] && !ft_isspace(argv[1][i]))
            i++;
        end = i;
        while (argv[1][i] && ft_isspace(argv[1][i]))
            i++;
        while(argv[1][i])
        {
            while( argv[1][i] && !ft_isspace(argv[1][i]))
            {
                write(1, &argv[1][i], 1);
                i++;
                printed = 1;
            }
            while(argv[1][i] && ft_isspace(argv[1][i]))
                i++;
            if (argv[1][i] && printed)
                write(1, " ", 1);
        }
        if (start < end)
        {
            if (printed)
                write(1, " ", 1);
            while(start < end)
                write(1, &argv[1][start++], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}

/*
los fallos que he tenido en esta función es en el número de argumentos 
y en la parte final, la comprobación de la flag printed va por separado del while (start < end)
*/

/*
    Necesitamos mover la primera palabra del string al final de la cadena 
    Vamos a usar solo write de las funciones permitidas
    Creo una función auxiliar para los espacios

    En el main:
    Declaro 4 variables:
        i -> para recorrer argv
        start -> marca el inicio de la palabra
        end -> marca el final de la palabra
        printed -> flag para marcar que hemos impreso una palabra
    Comprobamos el número de argumentos (if (argc > 1) -> esto es así porque necesita 
    poder gestionar varios argumentos a la vez)

    BLOQUE 1:
    Ignoramos los espacios iniciales -> esta es el único de los bucles que NO comprobamos además que exista argv[1][i]
    Igualamos start a la posición de i (el primer carácter de la primera palabra).
    ****A partir de este bucle en cada uno de los while/if vamos a comprobar primero que exista argv[1][i])*******
    Mientras que no sea un espacio, avanza -> end = i. Hemos encontrado el final de la primera palabra.
    Hasta aquí hemos acotado la palabra que tenemos que desplazar.
    Ignoramos los espacios entre palabras: mientras que exista argv[1][i] y sea un espacio, avanza

    BLOQUE 2:
    Mientras exista argv[1][i]
        Mientras exista argv[1][i] y !espacio
            escribe argv[1][i]
            avanza en i (i++)
            marca la flag printed en 1 (porque marca que hemos impreso una palabra)
            Marcar la flag printed es importante porque luego tenemos que imprimir un espacio después de cada palabra 
            que hemos impreso.
        Mientras exista argv[1][i] y sea un espacio, avanza en i (ignora el espacio, lo añadimos después)
        si argv[1][i] existe 
            imprime un espacio.
        
    BLOQUE 3:
    Si start es menor a end
        Si la flag printed está activada:
            imprime un espacio
        mientras que start < end
            escribe (1, &argv[1][start++], 1);
    
    Salto de línea
    Fin del programa.
*/






















