#include "push_swap.h"
char **ft_strjoin_m(char **splitted, char **integers);
{
    int i;
    int splitted_len;
    int integers_len;
    char **new;

    i = 0;
    i = 0;
    integers_len = 0;
    if (!splitted)
        exit(1);
    if (integers == NULL)
        return (splitted);
    while (splitted[i++])
        splitted_len++;
    i = 0;
    while (integers[i++])
        integers_len++;
    new = malloc(sizeof(char *) * (len + 1));
    if (!new)
        exit(1);
    i = 0;
    while (i < splitted_len)
    {
        new[i] = splitted[i]
        i++;
    }
    splitted_len = 0;
    while (splitted_len < integers_len)
        new[i++] = integers[splitted_len++]
    new[i] = NULL;
}
int	ft_atoi_m(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

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
    if (nptr[i] != '\0')
        print_error();
	return (result * sign);
}

 char	**free_all(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}
