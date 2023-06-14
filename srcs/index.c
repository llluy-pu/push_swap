/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:08:34 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/14 16:20:07 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lst	*ps_get_min(t_lst **stack)
{
	t_lst	*lst;
	t_lst	*lst_min;
	int		min;

	if (!(*stack))
		return (NULL);
	min = 0;
	lst_min = NULL;
	lst = *stack;
	while (lst)
	{
		if ((lst->index == -1)
			&& (!min || lst->content < lst_min->content))
		{
			lst_min = lst;
			min = 1;
		}
		lst = lst->next;
	}
	return (lst_min);
}

void	arg_index(t_lst **stack)
{
	t_lst	*lst;
	int		index;

	index = 0;
	lst = ps_get_min(stack);
	while (lst)
	{
		lst->index = index++;
		lst = ps_get_min(stack);
	}
}
