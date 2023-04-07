/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:27:57 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/07 11:49:37 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min(t_stack *stack_a, int value)
{
	int	min;

	min = stack_a->index;
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		if ((stack_a->index < min) && stack_a->index != value)
			min = stack_a->index;
	}
	return (min);
}

static void	sort_3(t_stack **stack_a)
{
	int	min;
	int	next_min;

	min = get_min(*stack_a, -1);
	next_min = get_min(*stack_a, min);
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->index == min && (*stack_a)->next->index != next_min)
		do_ra_sa_rra(stack_a);
	else if ((*stack_a)->index == next_min)
	{
		if ((*stack_a)->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if ((*stack_a)->next->index == min)
			ra(stack_a);
		else
			do_sa_rra(stack_a);
	}
}

static void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (is_sorted(*stack_a))
		return ;
	distance = get_distance(*stack_a, get_min(*stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(*stack_a, get_min(*stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb (stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sort_3(stack_a);
	else if (stack_size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_size == 5)
		sort_5(stack_a, stack_b);
}
