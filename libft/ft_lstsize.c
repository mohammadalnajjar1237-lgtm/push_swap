/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:18:21 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/27 14:18:54 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*#include <stdio.h>
int	main(void)
{
    t_list *head;
    t_list *new;
    new = ft_lstnew(" heyy");
    head = ft_lstnew("hello");
    ft_lstadd_front(&head, new);
    printf("%zu", ft_lstsize(head));
}*/
