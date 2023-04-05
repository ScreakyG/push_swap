/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 03:13:10 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/05 16:22:57 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_b);
	reverse_rotate(stack_a);
	ft_putstr("rrr\n");
}
