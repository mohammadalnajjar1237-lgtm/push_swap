#include "libft.h"

static int print_between_1_9(int nbr, int *count)
{
    char c;

    write(2, "0.0", 3);
    c = nbr + '0';
    write(2, &c, 1);
    *count += 4;
    return (1);
}

static int print_else(int nbr, int *count)
{
    char *buffer;
    int i;
    int len;

    i = 0;
    buffer = ft_itoa(nbr);
    if (!buffer)
        return (0);
    len = ft_strlen(buffer);
    if (len == 2)
        *count += write(2, "0.", 2);
    while (buffer[i])
    {
        if (i == len / 2 && len != 2)
           *count += write(2, ".", 1);
        *count += write(2, &buffer[i], 1);
        i++;
    }
    free(buffer);
    return (1);
}

int ft_print_double(int nbr, int *count)
{
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

    if (nbr > 0 && nbr < 10)
        return (print_between_1_9(nbr, count));
    else
        return (print_else(nbr, count));
}

/*static int ft_floor(float nbr)
{
    return ((int)nbr);
}


static void print_else(double nbr, int *count)
{
    char *final_num;
    int len;
    char *floor;
    char *fraction;

    nbr /= 100;
    floor = ft_itoa(ft_floor(nbr));
    fraction = ft_itoa((int)((nbr - ft_floor(nbr)) * 100));
    final_num = ft_strjoin(floor, fraction);
    if (!final_num)
        exit(1);
    if (final_num[0] != '0' && ft_strlen(final_num) > 3)
        len = 2;
    else
        len = 1;
    write(2, final_num, len);
    write(2, ".", 1);
    write(2, final_num + len, 2);
        //write(2, &last_digit, 1);
    free(final_num);
    free(floor);
    free(fraction);
    *count += len + 3;       
}

int ft_print_double(double nbr, int *count)
{
    if (nbr == 10000)
        *count += write(2, "100.00", 6);
    else if (nbr == 0)
        *count += write(2, "0.00", 4);
    else if (nbr > 0 && nbr < 10)
        print_between_1_9(nbr, count);       
    else
        print_else(nbr, count);
    return (1);
}*/