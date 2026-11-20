/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_libft_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:43:26 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/20 23:24:44 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_strs(char **new, char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		new[i] = strs[i];
		i++;
	}
	new[i] = NULL;
	free(strs);
}

char	**merge_string_arrays(char **splitted, char **integers)
{
	int		splitted_len;
	int		integers_len;
	char	**new;

	new = NULL;
	if (!splitted)
	{
		free_string_array(integers);
		exit(1);
	}
	if (integers == NULL)
		return (splitted);
	splitted_len = count_strings(splitted);
	integers_len = count_strings(integers);
	new = malloc(sizeof(char *) * (splitted_len + integers_len + 1));
	if (!new)
	{
		free_string_array(splitted);
		free_string_array(integers);
		exit(1);
	}
	copy_strs(new, integers);
	copy_strs(new + integers_len, splitted);
	return (new);
}

static void	integer_parse_error(char **npt, t_stack *a)
{
	free_string_array(npt);
	free_nodes(a);
	print_error();
}

int	parse_integer(char **npt, t_stack *a, int j)
{
	int		i;
	long	result;
	int		sign;
	char	*nptr;

	i = 0;
	result = 0;
	sign = 1;
	nptr = npt[j];
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] == '0')
		i++;
	if (nptr[i] == '\0')
		return (0);
	result = parse_digits(nptr, &i);
	if (nptr[i] != '\0' || result * sign > 2147483647 || result * sign
		< -2147483648)
		integer_parse_error(npt, a);
	return (result * sign);
}

char	**free_string_array(char **strs)
{
	int	i;

	if (!strs)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}
