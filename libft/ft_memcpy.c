/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:05:49 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/30 17:04:55 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*temp;
	unsigned char		*temp1;

	i = 0;
	temp = (unsigned char *) dest;
	temp1 = (unsigned char *) src;
	while (i < n)
	{
		temp[i] = temp1[i];
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
int	main(void)
{
	char s[] = "ab";
	char ft[3] 
	char f[3];
	printf("%s\n", (char*)ft_memcpy(NULL, s, 3));
	printf("%s\n", (char*)memcpy(NULL, s, 3));
	return (0);
}*/
