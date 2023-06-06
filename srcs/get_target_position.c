/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:55:32 by fgonzale          #+#    #+#             */
/*   Updated: 2023/06/06 15:10:36 by parallels        ###   ########.fr       */
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

int	get_target(t_stack **stack_a, int b_index, int cible_idx, int cible_pos)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < cible_idx)
		{
			cible_pos = tmp_a->position;
			cible_idx = tmp_a->index;
		}
		tmp_a = tmp_a->next;
	}
	if (cible_idx != INT_MAX)
		return (cible_pos);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < cible_idx)
		{
			cible_idx = tmp_a->index;
			cible_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (cible_pos);
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
		target_position = get_target(stack_a, tmp_b->index, INT_MAX, 0);
		tmp_b->target_position = target_position;
		tmp_b = tmp_b->next;
	}
}
