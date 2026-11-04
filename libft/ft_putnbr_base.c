#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

static int    turn_hexa(char *binary)
{
    long long nbr;
    int i;
    int x;
    int len;
    int c;

    nbr = 0;
    len = ft_strlen(binary);
    i = 0;
    while (binary[i] != '\0')
    {
        c = binary[i] - '0';
        x = len - 1;
        while (x > 0)
        {
            c *= 2;
            x--;
        }
        nbr += c;
        i++;
        len--;
    }
    return (nbr);
}

static char	*copy_buffer(char *buff, char *binary, int start)
{
	int	j;
	int	len;

	j = 0;
	len = 32 - start;
	while (j < len)
	{
        if (buff[start] == '1')
            buff[start] = '0';
        else
            buff[start] = '1';
		binary[j] = buff[start];
		j++;
		start++;
	}
    binary[j] = '\0';
	return (binary);
}

static char *turn_binary(long long n)
{
    char buffer[32];
    char *binary;
    int i;

    i = 31;
    n *= -1;
	while (n >= 2)
	{
		buffer[i--] = (n % 2) + '0';
		n = n / 2;
	}
	buffer[i] = n % 2 + '0';
	binary = malloc(1 * (32 - i + 1));
	if (!binary)
		return (0);
	return (copy_buffer(buffer, binary, i));

}

char    *choose_base(char b)
{
    if (b == 'x')
        return ("0123456789abcdef");
    return ("0123456789ABCDEF");
}

void ft_putnbr_hexa(long long n,char b)//btraje3ha long
{
    char *base;
    int base_length;
    char c;
    char *binary;

    base = choose_base(b);
    base_length = ft_strlen(base);
    if (n < 0)
    {
        binary = turn_binary(n);
       n = turn_hexa(binary);
        free(binary);
    }
    if (n >= base_length)
        ft_putnbr_hexa(n / base_length, b);
    c = base[n % base_length];
    write(1 ,&c, 1);
}
#include <stdio.h>
int main()
{
    ft_putnbr_hexa(-315, 'x');
    printf("\n%x", -400);
}