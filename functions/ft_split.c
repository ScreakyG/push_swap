/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:49:14 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/05 16:22:07 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_split(char **split, int i)
{
	int	nb;

	nb = 0;
	while (nb < i)
	{
		free(split[nb]);
		nb++;
	}
	free(split);
}

static int	get_nb_words(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int	get_words_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(char *str, char c)
{
	char	**split;
	int		i;
	int		nb_words;
	int		word_len;

	i = 0;
	nb_words = get_nb_words(str, c);
	split = malloc((nb_words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (i < nb_words)
	{
		word_len = get_words_len(str, c);
		if (word_len > 0)
		{
			split[i] = ft_substr((char const *)str, 0, (size_t)word_len);
			if (!split[i++])
				return (ft_free_split(split, i), NULL);
		}
		str = &str[word_len + 1];
	}
	split[nb_words] = NULL;
	return (split);
}
