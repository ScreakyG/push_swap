/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:48:50 by fgonzale          #+#    #+#             */
/*   Updated: 2023/06/05 12:27:07 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	read_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		else if (!ft_strncmp(line, "pa\n", 3))
			pa(stack_a, stack_b);
		else if (!ft_strncmp(line, "pb\n", 3))
			pb(stack_a, stack_b);
		else if (!ft_strncmp(line, "sa\n", 3))
			sa(stack_a);
		else if (!ft_strncmp(line, "sb\n", 3))
			sb(stack_b);
		else if (!ft_strncmp(line, "ss\n", 3))
			ss(stack_a, stack_b);
		else if (!ft_strncmp(line, "ra\n", 3))
			ra(stack_a);
		else if (!ft_strncmp(line, "rb\n", 3))
			rb(stack_b);
		else if (!ft_strncmp(line, "rr\n", 3))
			rr(stack_a, stack_b);
		else if (!ft_strncmp(line, "rra\n", 4))
			rra(stack_a);
		else if (!ft_strncmp(line, "rrb\n", 4))
			rrb(stack_b);
		else if (!ft_strncmp(line, "rrr\n", 4))
			rrr(stack_a, stack_b);
		else
		{
			get_next_line(-1);
			if (line)
				free(line);
			exit_error(stack_a, stack_b, NULL);
		}
		free(line);
	}
	if (line)
		free(line);
	get_next_line(-1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_argvs;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	split_argvs = ft_parse(argv);
	if (!correct_input(split_argvs))
		exit_error(NULL, NULL, split_argvs);
	stack_a = fill_stack_numbers(split_argvs);
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), free_stack(&stack_b), 0);
	read_instructions(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
}
