/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:07:43 by mokarimi          #+#    #+#             */
/*   Updated: 2026/01/16 17:15:07 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack *stack)
{
	int		index;
	t_stack	*current;
	t_stack	*checker;

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
