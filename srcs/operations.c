/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:46:52 by parallels         #+#    #+#             */
/*   Updated: 2023/06/21 11:43:00 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_ope(int cost_a, int cost_b, t_stack **stack_a, t_stack **stack_b)
{
	if (cost_a < 0 && cost_b < 0)
		r_rotate(&cost_a, &cost_b, stack_a, stack_b);
	else if (cost_a > 0 && cost_b > 0)
		rotates(&cost_a, &cost_b, stack_a, stack_b);
	rotates_a(stack_a, &cost_a);
	rotates_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}

void	rotates(int *cost_a, int *cost_b, t_stack **stack_a, t_stack **stack_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	r_rotate(int *costa, int *costb, t_stack **stack_a, t_stack **stack_b)
{
	while (*costa < 0 && *costb < 0)
	{
		rrr(stack_a, stack_b);
		(*costa)++;
		(*costb)++;
	}
}

void	rotates_a(t_stack **stack_a, int *cost_a)
{
	if (*cost_a > 0)
	{
		while (*cost_a > 0)
		{
			ra(stack_a);
			(*cost_a)--;
		}
	}
	else if (*cost_a < 0)
	{
		while (*cost_a < 0)
		{
			rra(stack_a);
			(*cost_a)++;
		}
	}
}

void	rotates_b(t_stack **stack_b, int *cost_b)
{
	if (*cost_b > 0)
	{
		while (*cost_b > 0)
		{
			rb(stack_b);
			(*cost_b)--;
		}
	}
	else if (*cost_b < 0)
	{
		while (*cost_b < 0)
		{
			rrb(stack_b);
			(*cost_b)++;
		}
	}
}
