#include "push_swap.h"
static void copy_strs(char **new, char **strs)
{
	int i;

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

	splitted_len = 0;
	integers_len = 0;
	if (!splitted)
	{
		free(integers);
		exit(1);
	}
	if (integers == NULL)
		return (splitted);
	while (splitted[splitted_len])
		splitted_len++;
	while (integers[integers_len])
		integers_len++;
	new = malloc(sizeof(char *) * (splitted_len + integers_len + 1));
	if (!new)
		exit(1);
	copy_strs(new, integers);
	copy_strs(new + integers_len, splitted);
	//new[i] = NULL;
	return (new);
}
int	ft_atoi_m(char **npt, t_stack *a, int j)
{
	int		i;
	long	result;
	int		sign;
	char *nptr;

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
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0' || result * sign > 2147483647 || result * sign < -2147483648)
	{
		free_all(npt);
		free_nodes(a);
		print_error();
	}
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
