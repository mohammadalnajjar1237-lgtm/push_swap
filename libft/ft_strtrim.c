/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 16:56:34 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/24 18:27:20 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_set(const char c, const char *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	size_t	i;
	size_t	j;
	size_t	trimmed_length;

	if (set == NULL || s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && check_set(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && check_set(s1[j - 1], set))
		j--;
	trimmed_length = j - i;
	temp = malloc(trimmed_length + 1);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, &s1[i], trimmed_length + 1);
	return (temp);
}
/*#include <stdio.h>
int	main(void)
{
	char *s = "dddd";
	printf("%s", ft_strtrim(s, "d"));
}*/
