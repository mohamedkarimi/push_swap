#include "push_swap.h"

void    chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
    assign_indices(*stack_a);
    push_chunks_to_b(stack_a,stack_b);
    push_back_to_a(stack_a, stack_b);
}