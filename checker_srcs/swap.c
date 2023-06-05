/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 03:09:46 by fgonzale          #+#    #+#             */
/*   Updated: 2023/06/01 00:08:21 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	swap;

	if (!stack || !stack->next)
		return ;
	swap = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = swap;
	swap = stack->index;
	stack->index = stack->next->index;
	stack->next->index = swap;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
}
