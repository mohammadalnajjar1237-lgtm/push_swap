/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:06:14 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/28 19:40:43 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*temp;
	unsigned char		ch;

	i = 0;
	temp = s;
	ch = c;
	while (i < n)
	{
		if (temp[i] == ch)
			return ((void *)&temp[i]);
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int	main(void)
{
    //const char s[] = "c\0";
    //char *c = (char *)(memchr(NULL,'\0', 2));
    char *ft = (char *)ft_memchr(NULL, '\0', 2);
    printf("%s ", ft);
}*/
