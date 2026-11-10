#include "push_swap.h"

void init_ops(int **ops_count)
{
	*ops_count = malloc(11  * sizeof(int));
    if (!(*ops_count))
        return ;
    ft_bzero(*ops_count, 11 * sizeof(int));
}
