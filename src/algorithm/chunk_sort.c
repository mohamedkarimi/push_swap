#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	assign_indices(*stack_a);
	push_chunks_to_b(stack_a, stack_b);
	push_back_to_a(stack_a, stack_b);
}