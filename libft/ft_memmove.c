/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:45:23 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/30 17:03:38 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*temp_src;
	unsigned char		*temp_dest;
	size_t				i;

	temp_src = src;
	temp_dest = dest;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			temp_dest[i] = temp_src[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*#include <stdio.h>
int	main(void)
{
	char s[] = "ABCDEfghij";
	char ft[5];
	printf("%s\n%s",(char*)memmove(NULL , , 6),(char*)ft_memmove(ft , ft+4,
					6));
}*/
