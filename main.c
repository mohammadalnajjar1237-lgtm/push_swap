/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:10:46 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 14:45:05 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_the_only_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] > '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		print_error();
	exit(0);
}

int	main(int av, char **args)
{
	t_stack	*a;

	a = NULL;
	if (av == 1)
		return (1);
	if (av == 2 && (ft_strncmp(args[1], "--", 2) == 0))
		print_error();
	if (av == 2)
		check_the_only_num(args[1]);
	push_swap(args, av, &a);
	free_nodes(a);
}
