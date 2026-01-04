/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:19:35 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/21 19:07:04 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format_str, ...);
void	putstr_ft_printf(char *s, int *count);
void	putsigned_ft_printf(unsigned int nbr, int *count);
void	putptr_ft_printf(unsigned long ptn, int *count);
void	putnbr_ft_printf(int n, int *count);
void	puthex_ft_printf(unsigned int hex, char check, int *count);
void	putchar_ft_printf(char c, int *count);
void	ptr_check_ft_printf(void *ptr, int *count);

#endif
