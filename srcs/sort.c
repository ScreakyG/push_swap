/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:36:51 by parallels         #+#    #+#             */
/*   Updated: 2023/06/05 12:23:46 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	stack_size = get_stack_size(*stack_a);
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	get_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		size_stack_a;
	int		size_stake_b;

	tmp_b = *stack_b;
	tmp_a = *stack_a;
	size_stack_a = get_stack_size(tmp_a);
	size_stake_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_stake_b / 2)
			tmp_b->cost_b = (size_stake_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_position;
		if (tmp_b->target_position > size_stack_a / 2)
			tmp_b->cost_a = (size_stack_a - tmp_b->target_position) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		cost_a;
	int		cost_b;
	int		cheapest_move;

	tmp_b = *stack_b;
	cheapest_move = INT_MAX;
	while (tmp_b)
	{
		if (abs(tmp_b->cost_a) + abs(tmp_b->cost_b) < abs(cheapest_move))
		{
			cheapest_move = abs(tmp_b->cost_a) + abs(tmp_b->cost_b);
			cost_a = tmp_b->cost_a;
			cost_b = tmp_b->cost_b;
		}
		tmp_b = tmp_b->next;
	}
	do_ope(cost_a, cost_b, stack_a, stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	simple_sort(stack_a, 3);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_costs(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}

void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}
