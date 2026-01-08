#include "push_swap.h"

void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int chunk_count;
	int chunk_size;
	int current_chunk;
	int max_index;
	int position;
	int pushed_index;

	size = stack_size(*stack_a);
	chunk_count = calculate_chunk_count(size); // Ch7al men chunk (matalan 5)
	chunk_size = size / chunk_count;          
		// Ch7al men ra9m f kol chunk (matalan 20)
	current_chunk = 0;                         // Kan-bdaw b chunk lowel
	while (*stack_a)
	{
		max_index = (current_chunk + 1) * chunk_size - 1;
		if (current_chunk == chunk_count - 1) // ila wsslna l akhir chunk
			max_index = size - 1;

		position = get_best_pos(*stack_a, max_index);
		if (position == -1)
		{
			current_chunk++;
			continue ;
		}
		rotate_a_to_top(stack_a, position);
		pushed_index = (*stack_a)->index;
		pb(stack_a, stack_b);
		if (pushed_index < max_index - chunk_size / 2)
			rb(stack_b);
	}
}