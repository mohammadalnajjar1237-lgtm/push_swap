#include "libft.h"

/*int ft_print_double(int nbr, int *count)
{
    char buffer[4];
    int i;

    i = 3;
    if (nbr == 0)
    {
        if  (write(2, "0.00", 3) == -1)
            return (-1);
        (*count) += 3;
        return (1);
    }
     if (nbr == 10000)
    {
        if (write(2, "100.00", 6) == -1)
            return (-1);
        (*count) += 6;
        return (1);
    }
    while (nbr >= 10)
    {
        buffer[i--] = nbr % 10 + '0';
        nbr = nbr / 10;
    }
    buffer[i] = nbr % 10 + '0';
    while (i < 4)
    {
        if (i == 2)
        {
            if (write(2, ".", 1) == -1)
                return (-1);
            (*count)++
        }
        if (write(2, &buffer[i], 1) == -1)
            return (-1);
        i++;
        (*count)++;
    }
    return (*count);
}*/

static int ft_floor(float nbr)
{
    return ((int)nbr);
}


int ft_print_double(float nbr, int *count)
{
    char *fraction;
    char  *floor;
    char *final_num;

    if (nbr == 1)
        *count += write(2, "100.00", 6);
    else if (nbr == 0)
        *count += write(2, "0.00", 4);
    else
    {
        nbr *= 100;
        floor = ft_itoa(ft_floor(nbr));
        fraction = ft_itoa((int)((nbr - ft_floor(nbr)) * 100));
        final_num = ft_strjoin(floor, fraction);
        if (!final_num)
            exit(1);
        write(2, final_num, 2);
        write(2, ".", 1);
        write(2, final_num + 2, 2);
    }
    free(final_num);
    return (1);
}