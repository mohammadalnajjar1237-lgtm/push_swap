#include "push_swap.h"

char	**ft_strjoin_m(char **splitted, char **integers)
{
	int		i;
	int		splitted_len;
	int		integers_len;
	char	**new;

	i = 0;
	splitted_len = 0;
	integers_len = 0;
	if (!splitted)
		exit(1);
	if (integers == NULL)
		return (splitted);
	while (splitted[splitted_len])
		splitted_len++;
	while (integers[integers_len])
		integers_len++;
	new = malloc(sizeof(char *) * (splitted_len + integers_len + 1));
	if (!new)
		exit(1);
	while (i < integers_len)
	{
		new[i] = integers[i];
		i++;
	}
	free(integers);
	integers_len = 0;
	while (integers_len < splitted_len)
		new[i++] = splitted[integers_len++];
	new[i] = NULL;
	free(splitted);
	return (new);
}
int	ft_atoi_m(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0' || result > 2147483647 || result < -2147483648)
		print_error();
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

t_stack	*ft_lstlast2(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
