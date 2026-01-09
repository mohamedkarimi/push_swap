/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:04:33 by mokarimi          #+#    #+#             */
/*   Updated: 2026/01/08 19:08:59 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Case 1: [1, 2, 3]
Case 2:1,3,2
Case 3:2,1,3
Case 4:2,3,1
Case 5:3,1,2
 Case 6: [3, 2, 1]*/

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first < second && second < third)
		return ;
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first < second && second > third && first > third)
		rra(stack_a);
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

static int	find_min_value(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

static int	find_value_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

static void	helper(t_stack **stack_a)
{
	int (min), (pos), (size);
	min = find_min_value(*stack_a);
	pos = find_value_position(*stack_a, min);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while (pos > 0)
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
}

void	sort_4_5_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushes;

	size = stack_size(*stack_a);
	if (size == 5)
		pushes = 2;
	else if (size == 4)
		pushes = 1;
	else
		return ;
	while (pushes > 0)
	{
		helper(stack_a);
		pb(stack_a, stack_b);
		pushes--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
