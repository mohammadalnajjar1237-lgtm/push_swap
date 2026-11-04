/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:18:03 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/27 12:16:53 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**free_all(char **strs, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static void	copy_str(size_t current_len, size_t start, const char *s, char *str)
{
	size_t	j;

	j = 0;
	while (j < current_len && s[start] != '\0')
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
}

static char	**find_strs(char **strs, char c, const char *s)
{
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			strs[j] = malloc((i - start + 1) * sizeof(char));
			if (!strs[j])
				return (free_all(strs, j));
			copy_str(i - start, start, s, strs[j]);
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	cs;
	char	**strs;

	i = 0;
	cs = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			cs++;
		i++;
	}
	strs = malloc((cs + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	return (find_strs(strs, c, s));
}
/*#include <stdio.h>
int	main(void)
{
    char **temp = ft_split("", 'c');
printf("%s\n", temp[0]);
printf("%s\n", temp[1]);
}*/
