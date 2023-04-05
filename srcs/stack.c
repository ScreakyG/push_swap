/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 04:12:05 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/05 16:23:10 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	stack_add_bottom(t_stack **stack_a, t_stack *new)
{
	t_stack	*lst;

	lst = *stack_a;
	if (!new)
		return ;
	if (*stack_a == NULL)
		*stack_a = new;
	else
	{
		while (lst && lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
