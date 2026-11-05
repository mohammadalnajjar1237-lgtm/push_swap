/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:10:08 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/28 19:41:31 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*temp1;
	const unsigned char	*temp2;

	i = 0;
	temp1 = s1;
	temp2 = s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && temp1[i] == temp2[i])
		i++;
	return ((int)(temp1[i]) - (int)(temp2[i]));
}
/*#include <stdio.h>
int	main(void)
{
    int a[] = {256};
    int b[] = {1000};


    printf("%d %d", ft_memcmp(a, b, 1), memcmp(a, b, 1));
}*/
