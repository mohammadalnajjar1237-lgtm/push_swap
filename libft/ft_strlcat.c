/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 10:47:22 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/22 12:22:16 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	j;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	while (size > 0 && dst[i] != '\0' && i < size - 1)
		i++;
	dest_len = i;
	if (size == 0 || dst[i] != '\0')
		return (size + src_len);
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest_len + src_len);
}
/*#include <stdio.h>
int	main(void)
{
        char dest1[13] ="mhmd" ;
        const char *src = "alnajjar";
        char dest2[13] = "mhmd";
	printf("%zu %s\n", ft_strlcat(dest1, src, 13),dest1);
	printf("%zu %s",  strlcat(dest2, src, 13), dest2);
}*/
