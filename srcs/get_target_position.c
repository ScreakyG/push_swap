/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:55:32 by fgonzale          #+#    #+#             */
/*   Updated: 2023/06/05 12:21:03 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_positions(stack);
	lowest_pos = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	get_positions(t_stack **stack)
{
	int		position;
	t_stack	*tmp;

	position = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->position = position;
		position++;
		tmp = tmp->next;
	}
}

int	get_target(t_stack **stack_a, int b_index)
{
	int		target_position;
	int		target_index;
	t_stack	*tmp_a;

	target_position = 0;
	tmp_a = *stack_a;
	target_index = INT_MAX;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < target_index)
		{
			target_position = tmp_a->position;
			target_index = tmp_a->index;
		}
		tmp_a = tmp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_position);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_position = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (target_position);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	int		target_position;
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	get_positions(stack_a);
	get_positions(stack_b);
	target_position = 0;
	while (tmp_b)
	{
		target_position = get_target(stack_a, tmp_b->index);
		tmp_b->target_position = target_position;
		tmp_b = tmp_b->next;
	}
}
