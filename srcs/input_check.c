/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:56:07 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/05 16:22:41 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '\0')
		return (0);
	if ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] != '\0')
		i++;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	nb_cmp(char *nb1, char *nb2)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (nb1[i] == '+')
		i++;
	if (nb2[j] == '+')
		j++;
	while (nb1[i] || nb2[j])
	{
		if (nb1[i] == nb2[j])
		{
			i++;
			j++;
		}
		else
			return (1);
	}
	return (0);
}

int	doublons(char **argv)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nb_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_zero(char *argv)
{
	unsigned int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	correct_input(char **argv)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		nb_zeros += is_zero(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (doublons(argv))
		return (0);
	return (1);
}
