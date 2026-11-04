/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:19:56 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/27 14:25:10 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_head;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new_head = *lst;
	while (new_head->next != NULL)
		new_head = new_head->next;
	new_head->next = new;
}
/*#include <stdio.h>
int	main(void)
{
    t_list *head;
    t_list *new;
    new = ft_lstnew(" heyy");
    head = ft_lstnew("hello");
    ft_lstadd_back(&head, new);
    head = head ->next;
    printf("%s", head ->content);
}*/
