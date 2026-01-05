/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:07:21 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 12:07:42 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_append(char *stash, char *buffer)
{
	int		i;
	int		j;
	char	*ptr;

	if (!stash)
		stash = ft_strdup("");
	if (!stash || !buffer)
		return (NULL);
	ptr = malloc(sizeof(char) * ((ft_strlen(stash) + ft_strlen(buffer)) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[j])
		ptr[i++] = stash[j++];
	j = 0;
	while (buffer[j])
		ptr[i++] = buffer[j++];
	ptr[i] = '\0';
	free(stash);
	return (ptr);
}
