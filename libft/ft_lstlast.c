/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:27:03 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/27 14:27:39 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*#include <stdio.h>
int	main(void)
{
    t_list *head;
    t_list *new;
    new = ft_lstnew(" heyy");
    head = ft_lstnew("hello");
    ft_lstadd_front(&head, new);
    printf("%s",ft_lstlast(head) ->content);
}*/
