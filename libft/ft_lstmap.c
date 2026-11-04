/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <moalnajj@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 15:48:32 by moalnajj          #+#    #+#             */
/*   Updated: 2026/09/28 12:53:27 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*succsess(t_list **head, t_list **head2, void *temp,
		void (*del)(void *))
{
	if (*head2 == NULL)
	{
		*head = ft_lstnew(temp);
		if (!(*head))
		{
			del(temp);
			return (NULL);
		}
		*head2 = *head;
	}
	else
	{
		(*head)->next = ft_lstnew(temp);
		if (!((*head)->next))
		{
			ft_lstclear(head2, del);
			del(temp);
			return (NULL);
		}
		*head = (*head)->next;
	}
	return (*head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*head2;
	void	*temp;

	head2 = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		temp = f(lst->content);
		if (temp != NULL)
			head = succsess(&head, &head2, temp, del);
		if (!head)
			return (NULL);
		lst = lst->next;
	}
	return (head2);
}
/*void *toup(void *content)
{
	void	*temp;
	size_t	i;

	i = ft_strlen((char*) content);
	temp = malloc(i + 1);
	ft_memcpy(temp, content, i + 1);
	return (temp);
}
void	del(void *c)
{
	void	*d;

	d = c;
	if (!d)
		;
}

#include <stdio.h>

int	main(void)
{
	t_list *lst;
	t_list *lst2;
	lst = ft_lstnew("");
	lst -> next = ft_lstnew("there");
	(lst -> next) -> next = ft_lstnew(",hru");
	lst2 = ft_lstmap(lst, toup, del);
	while (lst2)
	{
		printf("%s ", (char*)lst2 ->content);
		lst2 = lst2->next;
	}
}*/
