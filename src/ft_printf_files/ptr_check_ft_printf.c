/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_check_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:56:11 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/22 01:06:55 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ptr_check_ft_printf(void *ptr, int *count)
{
	unsigned long	ptn;

	if (!ptr)
		*count += write(1, "(nil)", 5);
	else
	{
		ptn = (unsigned long)ptr;
		putstr_ft_printf("0x", count);
		putptr_ft_printf(ptn, count);
	}
}
