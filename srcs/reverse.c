/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:19:11 by mrudloff          #+#    #+#             */
/*   Updated: 2023/06/06 13:22:39 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_push_swap.h"

void	reverse(t_lst **stack)
{
	t_lst	*lst;

	if (!(*stack) || !(*stack)->next)
		return ;
	lst = lst_last(*stack);
	lst->prev->next = NULL;
	lst->prev = NULL;
	lst->next = *stack;
	(*stack)->prev = lst;
	*stack = (*stack)->prev;
}

void	do_rra(t_lst **stack)
{
	reverse(stack);
	ft_printf("rra\n");
}

void	do_rrb(t_lst **stack)
{
	reverse(stack);
	ft_printf("rra\n");
}

void	do_rrr(t_lst **a_stack, t_lst **b_stack)
{
	reverse(a_stack);
	reverse(b_stack);
	ft_printf("rrr\n");
}
