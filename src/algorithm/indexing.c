#include "push_swap.h"

void	assign_indices(t_stack *stack)
{
	int	index;

	t_stack *current; // L-ra9m li kan-7esbou lih l-index dialo daba
	t_stack *checker; // L-3essas li kiy-douz 3la l-stack kamel bach y-9aren
	current = stack;
	while (current)
	{
		index = 0;
		checker = stack;
		while (checker)
		{
			if (checker->value < current->value)
				index++;
			checker = checker->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	update_positions(t_stack **stack)
{
	t_stack *current;
	int pos;

	current = *stack;
	pos = 0;

	while (current)
	{
		current->pos = pos;
		pos++;
		current = current->next;
	}
}