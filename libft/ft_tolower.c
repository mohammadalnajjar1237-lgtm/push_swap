/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:09:24 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/22 11:11:51 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%c \n", ft_tolower('['));
		printf("%c \n", tolower('['));
}*/
