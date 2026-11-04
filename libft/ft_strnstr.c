/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:24:42 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/28 19:42:30 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*little))
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (i + j < len && little[j] == big[i + j] && little[j] != '\0')
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
/*#include <stdio.h>
int	main(void)
{
	const char *big = "mmmhmd";
	const char *little = "mhmd";
	
	printf("%s\n%s", ft_strnstr(big, little, 20), strnstr(big, little, 20));
}*/
