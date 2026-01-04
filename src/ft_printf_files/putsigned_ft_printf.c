/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsigned_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:02:44 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/22 01:07:06 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	putsigned_ft_printf(unsigned int nbr, int *count)
{
	char	c;

	if (nbr > 9)
		putsigned_ft_printf(nbr / 10, count);
	c = (nbr % 10) + '0';
	*count += write(1, &c, 1);
}
