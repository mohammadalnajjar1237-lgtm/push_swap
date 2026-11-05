/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:56:49 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/24 12:20:31 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	dup = malloc(sizeof(char) * (src_len + 1));
	if (!dup)
		return (0);
	src_len = 0;
	while (src[src_len] != '\0')
	{
		dup[src_len] = src[src_len];
		src_len++;
	}
	dup[src_len] = '\0';
	return (dup);
}
