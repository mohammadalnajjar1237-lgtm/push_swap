#include "push_swap.h"

void	ft_lstadd_back2(t_stack **lst, t_stack *new)
{
	t_stack	*new_head;

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
