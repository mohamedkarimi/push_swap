#include "push_swap.h"

void    sort_two(t_stack **stack_a)
{
    if((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void    sort_three(t_stack **stack_a)
{
    int first;
    int second;
    int third;

    first = (*stack_a)->value;
    second = (*stack_a)->next->value;
    third = (*stack_a)->next->next->value;
    if(first < second && second < third)// Case 1: [1, 2, 3] 
        return;
    else if(first < second && second > third && first < third)// Case 2: [1, 3, 2]
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if(first > second && second < third && first < third)// Case 3: [2, 1, 3]
        sa(stack_a);
    else if(first < second && second > third && first > third)// Case 4: [2, 3, 1]
        rra(stack_a);
    else if(first > second && second < third && first > third)// Case 5: [3, 1, 2]
        ra(stack_a);
    else if(first > second && second > third )// Case 6: [3, 2, 1]
    {
        sa(stack_a);
        rra(stack_a);
    }
}

static int find_min_value(t_stack *stack)
{
    int min;
    min = stack->value;
    while (stack)
    {
        if(stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

static int find_value_position(t_stack *stack, int value)
{
    int pos;
    pos = 0;
    while (stack)
    {
        if(stack->value == value)
            return (pos);
        stack = stack->next;
    }
    return -1;
}

void    sort_4_5_elements(t_stack **stack_a, t_stack **stack_b)
{
    int size;
    int pushes;
    int min;
    int pos;

    size = stack_size(*stack_a);
    if(size == 5)
        pushes = 2;
    else if(size == 4)
        pushes = 1;
    else
        return;
    while(pushes > 0)
    {
        min = find_min_value(*stack_a);
        pos = find_value_position(*stack_a,min);
        size = stack_size(*stack_a);
        if(pos <= size / 2)
        {
            while(pos > 0)
            {
                ra(stack_a);
                pos--;
            }
        }
        else
        {
            while (pos < size)
            {
                rra(stack_a);
                pos++;
            }
        }
        pb(stack_a,stack_b);
        pushes--;
    }
    sort_three(stack_a);
    while(*stack_b)
        pa(stack_a, stack_b);
}