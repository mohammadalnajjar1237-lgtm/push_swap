/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:48:46 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 10:48:48 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_between_1_9(int nbr, int *count)
{
	char	c;

	write(2, "0.0", 3);
	c = nbr + '0';
	write(2, &c, 1);
	*count += 4;
	return (1);
}

static int	print_else(int nbr, int *count)
{
	char	*buffer;
	int		i;
	int		len;

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

int	ft_print_double(int nbr, int *count)
{
	if (nbr == 0)
	{
		if (write(2, "0.00", 4) == -1)
			return (-1);
		(*count) += 4;
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
