/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:03:11 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/22 01:06:59 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	puthex_ft_printf(unsigned int hex, char check, int *count)
{
	char	*str;

	if (check == 'x')
		str = "0123456789abcdef";
	else if (check == 'X')
		str = "0123456789ABCDEF";
	else
		str = NULL;
	if (hex >= 16)
	puthex_ft_printf((hex / 16), check, count);
	putchar_ft_printf(str[(hex % 16)], count);
}
