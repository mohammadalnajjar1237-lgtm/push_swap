#include "push_swap.h"

void sort_in_simple(stack *a, int size, int bench_flag)
{
    stack *b;
    double disorder;
    b = a
    disorder = measure_disorder(a);
    while (disorder > 0)
    {
        bubble_sort(a, b, size,bench);
        disorder = measure_disorder(a);
    }
}