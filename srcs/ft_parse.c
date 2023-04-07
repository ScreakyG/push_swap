/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:41:49 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/07 12:56:52 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_strs(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

char	**ft_parse(char **argv)
{
	char	*join_all;
	char	**split;

	join_all = ft_strjoin_all(argv);
	if (!join_all)
		return (NULL);
	split = ft_split(join_all, ' ');
	if (!split)
		return (free(join_all), NULL);
	return (free(join_all), split);
}

char	*ft_strjoin_all(char **argv)
{
	char	*joined;
	size_t	size;
	int		i;
	size_t	j;
	size_t	s;

	i = 1;
	s = 0;
	size = 0;
	while (argv[i])
		size += ft_strlen(argv[i++]) + 1;
	joined = malloc(size * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
			joined[s++] = argv[i][j++];
		if (argv[i + 1])
			joined[s++] = ' ';
	}
	joined[s] = '\0';
	return (joined);
}
