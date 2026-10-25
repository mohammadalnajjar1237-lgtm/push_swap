#include "push_swap.h"

void    print_error()
{
    write(2, "ERROR\n", 6);
    exit(1);
}

double compute_disorder(t_stack *a, int size)
{
int mistakes = 0;
int total_pairs = 0;
int i = 0;
int j;
t_stack *temp;
while (i < size - 1)
{
    temp = a -> next;   
    j = i + 1;
    while (j < size)
    {
        total_pairs += 1;
        if (a > a -> next)
            mistakes += 1;
        j++;
        temp = temp -> next;
    }
    a = a-> next;
    i++;
}
return mistakes / total_pairs;
}