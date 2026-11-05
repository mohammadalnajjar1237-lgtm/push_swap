/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:29:50 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/28 19:29:47 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;
	unsigned char	ch;

	i = 0;
	ch = c;
	temp = s;
	while (i < n)
	{
		temp[i] = ch;
		i++;
	}
	return (s);
}
/*#include <stdio.h>
int	main(void)
{
	char i[2]="am";
	char ft[2];
	
	printf("%s\n", (char*)memset(i, 65, 2 * sizeof(char)));	
}*/
