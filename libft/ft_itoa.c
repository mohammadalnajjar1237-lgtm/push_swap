/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:22:20 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/27 12:50:03 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static char	*copy_buffer(char *buff, char *num, int start, int flag)
{
	int	j;
	int	len;

	j = 0;
	len = 15 - start;
	if (flag)
	{
		num[j] = buff[14];
		j++;
	}
	while (j < len)
	{
		num[j] = buff[start];
		j++;
		start++;
	}
	num[j] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	char	buffer[15];
	long	nbr;
	int		i;
	int		flag;
	char	*number;

	flag = 0;
	nbr = n;
	i = 14;
	if (nbr < 0)
	{
		buffer[i--] = '-';
		nbr *= -1;
		flag = 1;
	}
	while (nbr >= 10)
	{
		buffer[i--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	buffer[i] = nbr % 10 + '0';
	number = malloc(1 * (15 - i + 1));
	if (!number)
		return (NULL);
	return (copy_buffer(buffer, number, i, flag));
}
/*#include <stdio.h>
int	main(void)
{
	char *s = ft_itoa(1234);
    printf("%s", s);
    free(s);
    
}*/
