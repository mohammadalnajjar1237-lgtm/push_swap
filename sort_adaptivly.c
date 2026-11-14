/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptivly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:18:10 by moalnajj          #+#    #+#             */
/*   Updated: 2026/11/14 11:19:43 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptivly(t_stack **a, int size, int bench_flag)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		sort_simple(a, size, bench_flag);
	else if (disorder >= 0.2 && disorder < 0.5)
		sort_medium(a, size, bench_flag);
	else
		sort_complex(a, size, bench_flag);
}
