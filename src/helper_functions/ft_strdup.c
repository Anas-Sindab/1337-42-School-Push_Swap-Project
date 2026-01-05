/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:40:40 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 10:17:08 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/helper_functions.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		size;
	char	*ptr;

	size = ft_strlen(s);
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
