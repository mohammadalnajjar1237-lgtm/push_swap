int main()
{
    char s[20];

    s[0] = 1000000;  checking_dups = malloc(sizeof(int) * capacity);
    if (!a || !checking_dups)
        exit(1);
    while (i < capacity)
    {
        a->value = integers[i];
        if (i != 0 &&!check_args(integers[i]))
        {
            write(2, "ERROR\n", 6);
            exit(1);
        }
        checking_dups[j++] = integers[i++];
        a = a->next;
    }
}

void sort_in_simple(stack *a, int capacity, int bench_flag)
{
    stack *b;
    double disorder;
    b = create_stack(capacity);
    disorder = measure_disorder(a);
    bubble_sort(a, b, size,bench);
}
