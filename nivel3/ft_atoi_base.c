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
    return (c == ' ' || c == '\t');
}

int ft_isvalid (int ch, int baselen)
{
    if ((ch >= 48 && c <= 57) || (baselen > 10 && ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))))
        return (1);
    else 
        return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    if (str_base < 2 || str_base > 16)
        return (0);
    while(ft_isspace(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
        {
            sign = - 1;
            i++;
        }
        else 
            i++;
    }
    while (str[i] && ft_isvalid(str[i], str_base))
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


// Another version 

int ft_isspace (char c)
{
    return (c == ' ' || c == '\t');
}

int	ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int sign = 1;
    int i = 0;
    int valor = 0;

    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') ||
        (str[i] >= 'A' && str[i] <= 'F'))
    {
        if (str[i] >= '0' && str[i] <= '9')
            valor = str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f') 
            valor  = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            valor = str[i] - 'A' + 10;
        else 
            break;
        if (valor >= str_base)
            break;
        result = result * str_base + valor;
        i++;
    }
    return (result * sign);
}

