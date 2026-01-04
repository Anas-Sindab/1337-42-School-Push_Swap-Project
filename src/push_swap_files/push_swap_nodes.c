/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:51:37 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/02 17:43:30 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/push_swap_header_file.h"

t_arg	*create_node(int nb)
{
	t_arg *node;

	node = malloc(sizeof(t_arg));
	if (!node)
		return (NULL);
	node->value = nb;
	node->next = NULL;

	return (node);
}

void	add_node_back(t_arg **list, int nb)
{
	t_arg *tmp;

	if (!list || !(*list))
		return ;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_node(nb);
}

void	add_node_front(t_arg **list, int nb)
{
	t_arg *tmp;

	if (!list || !(*list))
		return ;

	tmp = create_node(nb);
	tmp->next = *list;
	*list = tmp;
}
int	ft_lstsize(t_arg *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}
