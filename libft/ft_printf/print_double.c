#include "ft_printf.h"

int ft_print_double(int nbr, int *count)
{
    char buffer[4];
    int i;

    i = 3;
    if (nbr == 0)
        return (write(1, "0.00", 4));
     if (nbr == 10000)
        return (write(1, "100", 3));
    while (nbr >= 10)
    {
        buffer[i--] = nbr % 10 + '0';
        nbr = nbr / 10;
    }
    buffer[i] = nbr % 10 + '0';
    while (i < 4)
    {
        if (i == 2)
            write(1, ".", 1);
        write(1, &buffer[i], 1);
        i++;
        (*count)++;
    }
    return (*count);
}