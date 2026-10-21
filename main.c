#include <stdio.h>
#include <stdlib.h>


stack   *creat_stack(int capacity)
{
    stack   *s;

    s = malloc(sizeof(stack));
    if (!s)
        return (NULL);
    s->collection = malloc(sizeof(int) * capacity);
    if (s->collection == NULL)
        return (NULL);
    s->size = 0;
    return (s);
}

int is_empty(stack *s)
{
    if (s->size == 0)
        return (1);
    return (0);
}

int is_full()
{
    return (s->size == s->capacity);
}

int push(stack *s, int item)
{
    s->collection[s->size] = item;
    s->size++;
}

int pop(stack *s)
{
    int popped_item;

    if (is_empty(s))
        return (0);
    s->size--;
    popped_item = s->collection[size];
    return (popped_item);
}

int peek(stack *s)
{
    int peek_item;
    if (is_empty(s))
        return (0);
    peek_item = s->collection[size - 1];
    return (peek_item);
}

int main()
{

}
