/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 02:38:47 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/21 22:35:21 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_utilities.h"
#include <stdio.h>

static	int	ft_splitor_check(char str_index, char	*splitor)
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
static	int	ft_count_word(char const *str, char *splitor)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (ft_splitor_check(str[i], splitor) && (str[i + 1] == '\0' || !ft_splitor_check(str[i + 1], splitor)))
			words++;
		i++;
	}
	return (words);
}

static	char	**ft_free_words(char **ptrs, int index)
{
	while (index >= 0)
		free(ptrs[index--]);
	free(ptrs);
	return (NULL);
}


static	char	**ft_allo(char **ptrs, char const *str, char *splitor, int words)
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

char	**ft_split(char const *s, char *c)
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

// int main(void)
// {
//     char *str = "Hello	this ,ispaptest";
//     char *delimiter = "	 ,";

//     char **result = ft_split(str, delimiter);

//     if (!result)
//     {
//         printf("ft_split failed\n");
//         return 1;
//     }

//     // Print the split words
//     int i = 0;
//     while (result[i])
//     {
//         printf("Word %d: %s\n", i, result[i]);
//         i++;
//     }

//     // Free allocated memory
//     i = 0;
//     while (result[i])
//     {
//         free(result[i]);
//         i++;
//     }
//     free(result);

//     return 0;
// }
