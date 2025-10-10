/*Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)
  
  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/


unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int c; 

    if (a == 0 || b == 0)
        return (0);
    if (a > b)
        c = a;
    else
        c = b;
    while (1)
    {
        if ((c % a == 0) && (c % b == 0))
            return (c);
        c++;
    }
}

/*
    #include <stdio.h>
    #include <stdlib.h>

    int main (int argc, char **argv)
    {
        unsigned int n;

        if (argc == 3)
        {
            n = lcm(atoi(argv[1], atoi(argv[2])));
            printf("LCM:" "%u\n", n);
        }
        return (0);
    }
*/

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int c;

    if (a == 0 || b == 0)
        return (0);
    if (a > b)
        c = a;
    else
        c = b;
    while (1)
    {
        if ((c % a == 0) && (c % b == 0))
            return (c);
        c++;
    }
}

/*
Esta función nos devuelve el mínimo común múltiplo de dos números. 
El mínimo común múltiplo de dos números es el número más pequeño que es divisible tanto por a como por b.

Declaramos una variable  unsigned int “c”
    - Comprobamos que los valores no sean cero, si alguno de los dos es cero, devuelve 0
        (el lcm no está definido cuando uno de los números es cero.)
    - Inicializamos la variable c con el número mayor entre a y b, 
        el lcm no puede ser menor que el mayor de los dos números. 
        (comparamos si (a > b || b > a) y el mayor se iguala a c)

Empezamos con el valor más grande de a y b (c) y buscamos el primer número que sea múltiplo de ambos.
    - Usamos un bucle infinito while(1) que continúa hasta que encuentra el lcm
    - comprobamos los múltiplos, verificando si c es divisible tanto por a como por b usando el operador % 
    (Si c % a == 0 y c % b == 0, significa que c es un múltiplo de ambos números, 
    que por lo tanto es el MCM. En ese caso, se devuelve c).
    - Devolvemos c
c++
*/