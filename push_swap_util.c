#include "push_swap.h"

void sort_in_simple(stack *a, int capacity, int bench_flag)
{
    stack *b;
    double disorder;
    b = create_stack(capacity);
    disorder = measure_disorder(a);
    while (disorder > 0)
        bubble_sort(a, b, size,bench);
}
