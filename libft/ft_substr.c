/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:44:23 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/29 11:58:48 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdint.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*to;
	size_t	j;
	size_t	last_index;
	size_t	s_len;

	j = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		len = 0;
	else if (start > SIZE_MAX - len || len + start > s_len)
		len = s_len - start;
	last_index = len + start;
	to = malloc(sizeof(char) * (len + 1));
	if (!to)
		return (NULL);
	while (start < last_index && s[start] != '\0')
	{
		to[j] = s[start];
		start++;
		j++;
	}
	to[j] = '\0';
	return (to);
}
/*#include <stdio.h>
int	main(void)
{
	const char *s = "mhmd alnajjar";
	printf("%s", ft_substr("ded", 10, 10));
}*/
