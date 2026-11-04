/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:06:40 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/28 19:40:09 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	size_t			counter;
	unsigned char	ch;

	i = 0;
	counter = 0;
	ch = c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			counter = i;
		i++;
	}
	if (s[i] == ch)
		counter = i;
	if (s[counter] == ch)
		return ((char *)&s[counter]);
	else
		return (0);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[] = "";
	printf("%s %s", strrchr(s, '\0'), ft_strrchr(s,'\0'));
}*/
