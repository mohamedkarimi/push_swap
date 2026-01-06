#include "push_swap.h"

void    rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if(!*stack || !(*stack)->next)
        return;
    
    first = *stack;
    last = stack_last(*stack);
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void    ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putstr_fd("ra\n",1);
}

void    rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr_fd("rb\n",1);
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd("rr\n",1);
}