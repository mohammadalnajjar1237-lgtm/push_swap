#include <unistd.h>

void ft_putstr_itoa(char *num)
{
    int i;

    i = 0;
    while (i < 8)
    {
        write(1, &num[i], 1);
        i++;
    }
}

void    ft_itoa_p(unsigned int n)
{
	char	buffer[8];
	long	nbr;
	int		i;
    char *base = "0123456789abcdef";

	nbr = n;
	i = 7;
	while (nbr >= 16)
	{
		buffer[i--] = base[nbr % 16] ;
		nbr = nbr / 16;
	}
	buffer[i--] = base[nbr % 16];
    while (i >= 0)
        buffer[i--] = '0';
    ft_putstr_itoa(buffer);    
}