/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 02:38:47 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 10:22:36 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/helper_functions.h"
#include <stdio.h>

static int	ft_splitor_check(char str_index, char *splitor)
{
	int	i;

	i = 0;
	while (splitor[i])
	{
		if (splitor[i] == str_index)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_count_word(char const *str, char *splitor)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (ft_splitor_check(str[i], splitor) && (str[i + 1] == '\0'
				|| !ft_splitor_check(str[i + 1], splitor)))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_free_words(char **ptrs, int index)
{
	while (index >= 0)
		free(ptrs[index--]);
	free(ptrs);
	return (NULL);
}

static char	**ft_allo(char **ptrs, char *str, char *splitor, int words)
{
	int	index;
	int	start;
	int	end;

	index = 0;
	start = 0;
	end = 0;
	while (index < words)
	{
		while (!ft_splitor_check(str[start], splitor))
			start++;
		end = start;
		while (ft_splitor_check(str[end], splitor) && str[end])
			end++;
		ptrs[index] = ft_substr(str, start, end - start);
		if (!ptrs[index])
			return (ft_free_words(ptrs, index));
		start = end;
		index++;
	}
	ptrs[index] = NULL;
	return (ptrs);
}

char	**ft_split(char *s, char *c)
{
	int		words;
	char	**ptrs;

	if (!s)
		return (NULL);
	words = ft_count_word(s, c);
	ptrs = malloc(sizeof(char *) * (words + 1));
	if (!ptrs)
		return (NULL);
	return (ft_allo(ptrs, s, c, words));
}
