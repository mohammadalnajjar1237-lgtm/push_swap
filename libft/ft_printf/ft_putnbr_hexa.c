/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 11:13:50 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/06 16:54:59 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	choose_base(char b, char **base)
{
	if (b == 'x')
	{
		*base = "0123456789abcdef";
	}
	else
		*base = "0123456789ABCDEF";
}

int	ft_putnbr_hexa(unsigned int nbr, char b, int *count)
{
	char			*base;
	char			c;

	choose_base(b, &base);
	if (nbr >= 16)
		ft_putnbr_hexa(nbr / 16, b, count);
	c = base[nbr % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (1);
}
/*#include <stdio.h>
int	main(void)
{
	int i = 0;
    ft_putnbr_hexa(42949672950, 'X', &i);
    printf("\n");
    int x = printf("%X", 42949672950);
    printf("\n%d %d", i, x);
}*/
