/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

PSEUDOCÓDIGO:

función ft_atoi_base(str, base):
    inicializar índice i = 0
    inicializar resultado = 0
    inicializar signo = 1

    # 1. Saltar espacios
    mientras str[i] existe y ft_isspace(str[i]) == 1:
        i++

    # 2. Manejar signo
    si str[i] == '-':
        signo = -1
        i++
    si str[i] == '+':
        i++

    # 3. Recorrer la cadena mientras el carácter sea válido en esa base
    mientras str[i] existe y carácter válido para base:
        - convertir str[i] a su valor numérico
          (ej: '0'→0, '9'→9, 'a'→10, 'f'→15)
        - acumular:
            resultado = resultado * base + valor
        - avanzar i++

    # 4. Devolver resultado con signo
    devolver resultado * signo


*/

int ft_isspace(char c)
{
    return(c == ' ' || c == '\t');
}

int ft_ishexa(int ch, int base_len)
{
    if ((ch >= '0' && ch <= '9') || (base_len > 10 && ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))))
        return (1);
    else
        return (0);
    
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    while(ft_isspace(str[i]))
        i++;
    while(str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        else 
            i++;
    }
    while(str[i] && ft_ishexa(str[i], str_base))
    {
        result *= str_base;
        if (str[i] >= '0' && str[i] <= '9')
            result += str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            result += str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            result += str[i] - 'A' + 10;
        i++;
    }
    return (result * sign);

}


/*
    Esta función convierte una cadena de caracteres que está en una base específica a su valor en base 10.
    La base puede ir de 2 a 16.
    Creamos dos funciones auxiliares:
        Una de ellas es para gestionar los espacios 
        la otra para gestionar 
        tanto si es un dígito que abarca de 0 a 9 o si está entre 'a' - 'f' o si está entre 'A' y 'F'
    La función principal : int	ft_atoi_base(const char *str, int str_base)
    es muy similar a atoi, pero en este caso, gestiona la base.

Función auxiliar is_hexa:

    int ft_ishexa(int ch, int base_len):
    Comprueba si es un número o si es una letra de a-f o una letra de A-F
    - ch: es el carácter que queremos verificar
    - base_len: es la longitud de la base
    - Comprueba si el carácter es un dígito entre '0' y '9', 
        lo considera válido para cualquier base desde la base 2 en adelante.
    - Si la base es mayor que 10 (por ejemplo, base 16) y el carácter 
        está entre 'a' y 'f' o 'A' y 'F', también lo considera válido.

Función principal
    Declaramos tres variables:
        i -> iterador para recorrer str[i]. Lo inicializamos a cero
        sign -> para manejar el signo (negativo o positivo). Lo inicializamos a uno
        result -> para almacenar el resultado. Lo inicializamos a cero.
    Si hay espacios al principio, los ignoramos
    Gestionamos el signo:
    Mientras que sea '+' o '-' 
        Si es '-'
            sign = -1
        avanzamos en i (i++)
    Mientras que exista str[i] y (llamamos a la función is_hexa para comprobar la base)
        Multiplicamos el resultado por la base.
        Si str[i] está entre '0' y '9' 
            result += str[i] - '0' || result += str[i] - 48
        Sino si str[i] está entre 'a' y 'f'
            result += str[i] - 'a' + 10
        Sino si str[i] está entre 'A' y 'F'
            result += str[i] - 'A' + 10  
        Avanzamos en i (i++)
    Devuelve result * sign
*/