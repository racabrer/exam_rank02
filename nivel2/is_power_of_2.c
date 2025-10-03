/*
Explicame sin código cómo hacer esto Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
        return(0);
    while (n % 2 == 0)
        n = n / 2;
    if (n == 1)
        return (1);
    else 
        return (0);
}

/*
Esta función devuelve uno si n es potencia de dos y devuelve cero si no es potencia de dos
Si n es igual a cero, devuelve cero porque cero no es potencia de dos
Mientras que el módulo de n entre dos sea cero(mientras que n sea divisible por 2),
    Dividimos n entre dos -> verificamos si n sigue siendo divisible por dos.
Si tras hacer esto n es 1, devuelve 1 porque significará que es potencia de dos, en caso contratio, devuelve cero
*/