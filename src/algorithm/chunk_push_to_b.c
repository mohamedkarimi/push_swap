/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:53:02 by mokarimi          #+#    #+#             */
/*   Updated: 2026/01/09 10:24:40 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int (max_index), (position), (pushed_index);
	int (size), (chunk_count), (chunk_size), (current_chunk);
	size = stack_size(*stack_a);
	chunk_count = calculate_chunk_count(size);
	chunk_size = size / chunk_count;
	current_chunk = 0;
	while (*stack_a)
	{
		max_index = (current_chunk + 1) * chunk_size - 1;
		if (current_chunk == chunk_count - 1)
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
