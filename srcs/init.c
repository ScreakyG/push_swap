/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:41:58 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/05 16:22:38 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	index_numbers(t_stack *stack_a, int stack_size)
{
	t_stack	*tmp;
	t_stack	*highest_number_pointer;
	int		highest_number;

	while (--stack_size > 0)
	{
		tmp = stack_a;
		highest_number_pointer = NULL;
		highest_number = INT_MIN;
		while (tmp)
		{
			if (tmp->nb == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->nb > highest_number && tmp->index == 0)
			{
				highest_number = tmp->nb;
				highest_number_pointer = tmp;
				tmp = stack_a;
			}
			else
				tmp = tmp->next;
		}
		if (highest_number_pointer != NULL)
			highest_number_pointer->index = stack_size;
	}
}

t_stack	*fill_stack_numbers(char **argv)
{
	t_stack	*stack_a;
	long	nb;
	int		i;

	stack_a = NULL;
	i = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			exit_error(&stack_a, NULL, argv);
		stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	ft_free_strs(argv);
	return (stack_a);
}
