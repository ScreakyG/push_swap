/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:43:03 by fgonzale          #+#    #+#             */
/*   Updated: 2023/06/06 15:09:23 by parallels        ###   ########.fr       */
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
	int				target_position;
	int				position;
	int				cost_b;
	int				cost_a;
	int				cost_total;
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

void	simple_sort(t_stack **stack_a, int stack_size);
void	sort(t_stack **stack_a, t_stack **stack_b);

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
void	do_ra_sa_rra(t_stack **stack);
void	do_sa_rra(t_stack **stack);

/* POSITION */

void	get_positions(t_stack **stack);
int		get_target(t_stack **stack_a, int b_idx, int cible_idx, int cible_pos);
void	get_target_position(t_stack **stack_a, t_stack **stack_b);
int		get_lowest_index_position(t_stack **stack);

/* OPERATIONS */

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	do_ope(int cost_a, int cost_b, t_stack **stack_a, t_stack **stack_b);
void	rotates(int *cost_a, int *cost_b, t_stack **stack_a, t_stack **stack_b);
void	r_rotate(int *costa, int *costb, t_stack **stack_a, t_stack **stack_b);
void	rotates_a(t_stack **stack_a, int *cost_a);
void	rotates_b(t_stack **stack_b, int *cost_b);

/* UTILS */

void	exit_error(t_stack **stack_a, t_stack **stack_b, char **splited_args);
long	ft_atoi(char *str);
void	ft_putstr(char *str);
int		is_sorted(t_stack *stack_a);
int		get_distance(t_stack *stack_a, int index_min);
int		abs(int nbr);

char	**ft_parse(char **argv);
char	*ft_strjoin_all(char **argv);
char	**ft_split(char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	ft_free_strs(char **split_args);

/* BONUS CHERCKER */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	ft_free(char **str1, char **str2, char **str3);
int		ft_strchr(char *str, char c);
char	*ft_strdup(char *src);
char	*ft_join_str(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* REMAKE FUNCTIONS */

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void	get_costs(t_stack **stack_a, t_stack **stack_b);
void	shift_stack(t_stack **stack_a);

#endif
