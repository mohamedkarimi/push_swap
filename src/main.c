/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:50:00 by mokarimi          #+#    #+#             */
/*   Updated: 2026/01/16 16:20:08 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	helper(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size <= 5)
		sort_4_5_elements(&stack_a, &stack_b);
	else
		chunk_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_arguments(ac, av, &stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack_a);
		return (1);
	}
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	size = stack_size(stack_a);
	helper(stack_a, stack_b, size);
	return (0);
}
