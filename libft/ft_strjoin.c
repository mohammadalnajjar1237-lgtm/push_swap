/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 16:06:03 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/24 16:37:52 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = malloc(s1_len + s2_len + 1);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, s1, s1_len);
	ft_memcpy(temp + s1_len, s2, s2_len);
	temp[s1_len + s2_len] = '\0';
	return (temp);
}
/*#include <stdio.h>
int	main(void)
{
	const char *s = "";
	const char *s2 = "";
	//char *temp = ft_strjoin(s, s2);
	printf("%s", ft_strjoin(NULL, s2));
}*/
