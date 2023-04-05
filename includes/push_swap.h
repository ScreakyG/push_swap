/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:43:03 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/04 19:44:02 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* INITIALISATION */

int		correct_input(char **argv);
t_stack	*fill_stack_numbers(char **argv);
void	index_numbers(t_stack *stack_a, int stack_size);

/* INPUT CHECK */

int		arg_is_number(char *argv);
int		doublons(char **argv);
int		nb_cmp(char *nb1, char *nb2);
int		is_zero(char *argv);

/* STACK */

t_stack	*stack_new(int nb);
void	stack_add_bottom(t_stack **stack_a, t_stack *new);
int		get_stack_size(t_stack *stack);
void	free_stack(t_stack **stack);

/* SORTING */

void	simple_sort(t_stack **stack_a, t_stack **stack_b, int stack_size);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

/* INSTRUCTIONS */

void	swap(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_src, t_stack **stack_dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_a);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* UTILS */

void	exit_error(t_stack **stack_a, t_stack **stack_b, char **splited_args);
long	ft_atoi(char *str);
void	ft_putstr(char *str);
int		is_sorted(t_stack *stack_a);
int		get_distance(t_stack *stack_a, int index_min);

char	**ft_parse(char **argv);
char	*ft_strjoin_all(char **argv);
char	**ft_split(char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	ft_free_strs(char **split_args);

#endif
