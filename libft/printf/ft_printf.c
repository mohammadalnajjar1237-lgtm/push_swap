#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>



void	ft_putnbr(long long n)//long
{
	char	c;
    if (n < 0)
    {
        write(1, "-", 1);
        n *= -1;
    }
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr_u(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr_u(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd == -1)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putchar_fd(unsigned char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_putnbr_hexa(long long n, char b);

void    ft_itoa_p(int n);

void choose_type(va_list *ap ,char b)
{
     if (b == 'c')
        ft_putchar_fd(va_arg(*ap, int), 1);//unsgined
    else if (b == 's')
        ft_putstr_fd(va_arg(*ap, char*), 1);//shoof el unsigned
    else if (b == 'X' || b == 'x')
        ft_putnbr_hexa(va_arg(*ap, int), b);//improve putnbr_base I should choose
                 //the base depending on f[i + 1]
    else if (b == 'i' || b == 'd')
        ft_putnbr(va_arg(*ap, int)); 
    else if (b == 'p')
        ft_itoa_p((unsigned int) va_arg(*ap, void*));
    else if (b == 'u')
        ft_putnbr_u((unsigned int)va_arg(*ap, int));
    else if (b == '%')
        write(1, "%", 1);
}

void ft_printf(char *f, ...)
{
    va_list ap;
    va_start(ap,f);
    int i;

    i = 0;
    while (f[i] != '\0')
    {
        if (f[i] != '%')
            write(1, &f[i], 1);
        else if (f[i] == '%')
        {
           choose_type(&ap, f[i + 1]);
                i++;
        }
        if (f[i] != '\0')
            i++;
    }
    va_end(ap);
}


int main()
{
    void *s = "jeuu";
    ft_printf("%p %i", s, 2147483647);
    printf("\n%p %i", s, 2147483647);
}