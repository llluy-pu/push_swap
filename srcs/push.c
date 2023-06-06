/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:18:59 by mrudloff          #+#    #+#             */
/*   Updated: 2023/06/06 13:22:40 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_push_swap.h"

static void	push(t_lst **a_stack, t_lst **b_stack)
{
	t_lst	*tmp;

	if (!b_stack)
		return ;
	tmp = (*b_stack)->next;
	lst_addfront(a_stack, *b_stack);
	*b_stack = tmp;
	if (*b_stack)
		(*b_stack)->prev = NULL;
}

void	do_pa(t_lst **a_stack, t_lst **b_stack)
{
	push(a_stack, b_stack);
	ft_printf("pa\n");
}

void	do_pb(t_lst **a_stack, t_lst **b_stack)
{
	push(b_stack, a_stack);
	ft_printf("pb\n");
}
