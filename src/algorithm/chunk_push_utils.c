#include "push_swap.h"

/*
 * Recommended values (tuned for performance):
 *   Size <= 100:  5 chunks  (chunk_size = 20)
 *   Size <= 500:  11 chunks (chunk_size ≈ 45)
 *   Size > 500:   sqrt(size) or size/20
 */
int	calculate_chunk_count(int size)
{
	if (size <= 100)
		return (4);
	else if (size <= 500)
		return (7);
	else
		return (size / 20);
}

int	find_first_pos(t_stack *stack, int max_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index <= max_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	find_last_pos(t_stack *stack, int max_index)
{
	int	pos;
	int	last_pos;

	pos = 0;
	last_pos = -1;
	while (stack)
	{
		if (stack->index <= max_index)
			last_pos = pos;
		pos++;
		stack = stack->next;
	}
	return (last_pos);
}

int	get_best_pos(t_stack *stack, int max_index)
{
	int	first;
	int	last;
	int	size;

	first = find_first_pos(stack, max_index);
	last = find_last_pos(stack, max_index);
	size = stack_size(stack);
	if (first == -1)
		return (-1);
	if (first <= (size - last))
		return (first);
	else
		return (last);
}
/**
 * #brief Rotate stack to bring element at position to top
 *
 * Chooses shortest rotation direction:
 *   - If position <= size/2: use ra (rotate up)
 *   - If position > size/2: use rra (rotate down)
 *
 * #param stack_a Pointer to stack A
 * #param position Position of element to bring to top
 */
void	rotate_a_to_top(t_stack **stack_a, int position)
{
	int size;
	size = stack_size(*stack_a);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(stack_a);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rra(stack_a);
			position++;
		}
	}
}