/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 03:16:52 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/05 16:22:52 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_stack *stack_a)
{
	int	max_bits;
	int	highest_index;

	highest_index = stack_a->index;
	max_bits = 0;
	while (stack_a)
	{
		if (stack_a->index > highest_index)
			highest_index = stack_a->index;
		stack_a = stack_a->next;
	}
	while ((highest_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		stack_size;
	int		max_bits;
	t_stack	*head;

	stack_size = get_stack_size(*stack_a);
	head = *stack_a;
	i = 0;
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < stack_size)
		{
			head = *stack_a;
			if (((head->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (get_stack_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
