/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:39:44 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/28 19:30:12 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*#include <stdio.h>

int	main(void)
{
	char	ft[2];
	char	i[2];

	ft_bzero(ft, 2 * sizeof(char));
	bzero(i, 2 * sizeof(char));
	printf("%s %d\n%s %d", ft, 3, i, 4);
}*/
