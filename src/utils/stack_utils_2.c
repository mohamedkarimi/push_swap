#include "push_swap.h"
int stack_size(t_stack *stack)
{
    int count;
    count = 0;
    while(stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}