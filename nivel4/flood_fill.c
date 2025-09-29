/*
Assignment name  : flood_fill
Expected files   : flood_fill.c
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this: (put it in flood_fill.c)

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

Example:

$> cat test.c
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$> 
*/

void fill(char **tab, t_point size, char target, int row, int col)
{
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
        return;
    if(tab[row][col] == 'F' || tab[row][col] != target)
        return;
    tab[row][col] = 'F';

    fill(tab, size, target, row - 1, col);
    fill(tab, size, target, row + 1, col);
    fill(tab, size, target, row, col + 1);
    fill(tab, size, target, row, col - 1);

}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char target;
    
    target = tab[begin.y][begin.x];
    fill(tab, size, target, begin.y, begin.x);
}


/*
Estructura t_point:
    x: entero
    y: entero

Función fill(tab, size, target, row, col):
    Si (row < 0 o row >= size.y) o (col < 0 o col >= size.x):
        Salir (fuera de los límites)
    Si (tab[row][col] != target):
        Salir (no es parte de la zona a llenar)

    Cambiar tab[row][col] a 'F'  (llenamos el punto actual)

    Llamar a fill para los 4 puntos adyacentes:
        fill(tab, size, target, row + 1, col)  (abajo)
        fill(tab, size, target, row - 1, col)  (arriba)
        fill(tab, size, target, row, col + 1)  (derecha)
        fill(tab, size, target, row, col - 1)  (izquierda)

Función flood_fill(tab, size, begin):
    Si (begin.x < 0 o begin.x >= size.x) o (begin.y < 0 o begin.y >= size.y):
        Salir (el punto inicial está fuera de los límites)

    target = tab[begin.y][begin.x]  (el carácter en el punto de inicio)
    Llamar a fill(tab, size, target, begin.y, begin.x)  (empezamos el llenado)

*/

/*
	El objetivo de esta función es llenar una zona de caracteres dentro de una matriz bidimensional (char **)
		char ** = char [][].
	Comienza desde un punto inicial y va reemplazando los caracteres adyacentes (horizontales y verticales) con 'F'
	El punto inicial es el target.

		**********************************************************************************************************

	Creamos una función auxiliar:
	void fill (char ** tab, t_point size, char target, int row, int col)
	Hacemos comprobaciones para ver que no desborda.

		Si row o col < 0, o si el tamaño de row es mayor/igual que size.y o col es mayor/igual row
		Si (tab[row][col] != target) -> sale
		Vamos llenando el punto actual igualando tab[row][col] a 'F'
		Utilizamos recursividad para recorrer todos los puntos: 
	        fill(tab, size, target, row + 1, col)  (abajo)
        	fill(tab, size, target, row - 1, col)  (arriba)
        	fill(tab, size, target, row, col + 1)  (derecha)
        	fill(tab, size, target, row, col - 1)  (izquierda)		
	
	Función flood_fill(tab, size, begin):
		Declaramos una variable target (que va a ser el carácter del punto de inicio).
		target ->> target = tab[begin.y][begin.x]
		Comenzamos a rellenar llamando a fill(tab, size, target, begin.y, begin.x)
*/