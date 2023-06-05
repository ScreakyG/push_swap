/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:46:28 by fgonzale          #+#    #+#             */
/*   Updated: 2023/06/05 12:11:24 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size <= 3 && !is_sorted(*stack_a))
		simple_sort(stack_a, stack_size);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**split_argvs;

	if (argc < 2)
		return (0);
	split_argvs = ft_parse(argv);
	if (!correct_input(split_argvs))
		exit_error(NULL, NULL, split_argvs);
	stack_b = NULL;
	stack_a = fill_stack_numbers(split_argvs);
	stack_size = get_stack_size(stack_a);
	index_numbers(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
