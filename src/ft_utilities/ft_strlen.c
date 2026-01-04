/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 02:41:33 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/21 20:18:55 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_utilities.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int main()
{
    char c = 'a';
    char b = 'b';
    char v = 'v';
    // printf("%d\n", ft_strlen(&c + 1));
    // printf("%d\n", ft_strlen(&b+ 2));
    printf("%d\n", ft_strlen(&v));
}*/
