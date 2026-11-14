/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_libft_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:43:26 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 14:43:30 by moalnajj         ###   ########.fr       */
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

char	**ft_strjoin_m(char **splitted, char **integers)
{
	int		splitted_len;
	int		integers_len;
	char	**new;

	new = NULL;
	if (!splitted)
	{
		free_all(integers);
		exit(1);
	}
	if (integers == NULL)
		return (splitted);
	splitted_len = num_pointers(splitted);
	integers_len = num_pointers(integers);
	new = malloc(sizeof(char *) * (splitted_len + integers_len + 1));
	if (!new)
	{
		free_all(splitted);
		free_all(integers);
		exit(1);
	}
	copy_strs(new, integers);
	copy_strs(new + integers_len, splitted);
	return (new);
}

static void	free_atoi(char **npt, t_stack *a)
{
	free_all(npt);
	free_nodes(a);
	print_error();
}

int	ft_atoi_m(char **npt, t_stack *a, int j)
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
	result = turn_to_int(nptr, &i);
	if (nptr[i] != '\0' || result * sign > 2147483647 || result * sign
		< -2147483648)
		free_atoi(npt, a);
	return (result * sign);
}

char	**free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}
