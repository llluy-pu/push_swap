/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:19:21 by mrudloff          #+#    #+#             */
/*   Updated: 2023/06/06 13:22:37 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_push_swap.h"

static void	swap(t_lst **stack)
{
	int	index;
	int	content;

	if (!(*stack)->next)
		return ;
	content = (*stack)->next->content;
	index = (*stack)->next->index;
	(*stack)->next->content = (*stack)->content;
	(*stack)->next->index = (*stack)->index;
	(*stack)->content = content;
	(*stack)->index = index;
}

void	do_sa(t_lst **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	do_sb(t_lst **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	do_ss(t_lst **a_stack, t_lst **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_printf("ss\n");
}
