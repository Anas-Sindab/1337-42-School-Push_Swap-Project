/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:55:00 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/22 01:07:04 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	putptr_ft_printf(unsigned long ptn, int *count)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (ptn >= 16)
	{
		putptr_ft_printf((ptn / 16), count);
	}
	putchar_ft_printf(str[(ptn % 16)], count);
}
