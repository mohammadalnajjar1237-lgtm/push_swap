/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:41:40 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/29 12:24:29 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	total;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	if (total == 0)
		total = 1;
	s = malloc(total);
	if (s != NULL)
		ft_bzero(s, total);
	return (s);
}
/*#include <stdio.h>
int	main(void)
{
	char *ft = ft_calloc((size_t)0,(size_t)2);
	//char *c = calloc((size_t)2000000000, (size_t)2000000000000);
	//int i = 0;
	printf("%s %d\n", ft, 4);
	  free(ft);
	//printf("%s %d", c, 4);

}*/
