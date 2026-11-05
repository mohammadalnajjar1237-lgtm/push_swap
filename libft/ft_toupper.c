/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:02:22 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/30 17:58:58 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%c \n", ft_toupper('['));
		printf("%c \n", toupper('['));
}*/
