/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:05:46 by mokarimi          #+#    #+#             */
/*   Updated: 2026/01/09 10:35:56 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk_count(int size)
{
	if (size <= 100)
		return (4);
	else if (size <= 500)
		return (8);
	else
		return (size / 45);
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

void	rotate_a_to_top(t_stack **stack_a, int position)
{
	int	size;

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
