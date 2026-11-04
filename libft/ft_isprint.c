/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:54:39 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/22 10:57:45 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
        printf("%d \n", ft_isprint(128));
         printf("%d \n", isprint(128));
}*/
