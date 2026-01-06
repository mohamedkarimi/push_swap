#include "push_swap.h"
static int find_max_index_pos(t_stack *stack)
{
    int pos;
    int max_pos;
    int max_index;

    if(!stack)
        return (-1);
    pos = 0;
    max_pos = 0;
    max_index = stack->index;
    while(stack)
    {
        if(stack->index > max_index)
        {
            max_index = stack->index;
            max_pos = pos;
        }
        pos++;
        stack = stack->next;
    }
    return (max_pos);
}

static void rotate_b_to_top(t_stack **stack_b, int position)
{
    int size;
    size = stack_size(*stack_b);
    if(position <= size / 2)
    {
        while (position > 0)
        {
            ra(stack_b);
            position--;
        }
    }
    else
    {
        while (position < size)
        {
            rra(stack_b);
            position++;
        }
    }
}

void push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int max_pos;
    while (stack_b)
    {
        max_pos = find_max_index_pos(*stack_b);
        rotate_b_to_top(stack_b, max_pos);
        pa(stack_a,stack_b);
    }
    
}