/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 03:37:01 by anasinda          #+#    #+#             */
/*   Updated: 2025/12/22 23:55:08 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_FUNCTIONS_H
# define HELPER_FUNCTIONS_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

long long	ft_atoi(const char *nptr);
char		**ft_split(char const *s, char *c);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
