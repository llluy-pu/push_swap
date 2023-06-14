/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:55:54 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/14 16:57:27 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tree(t_lst **stack)
{
	while (sort_check(stack) != 1)
	{
		if (((*stack)->index > (*stack)->next->index)
			&& ((*stack)->index < (*stack)->next->next->index))
			do_sa(stack);
		else if (((*stack)->index > ((*stack)->next->index))
			&& ((*stack)->index > (*stack)->next->next->index))
			do_ra(stack);
		else
			do_rra(stack);
	}
}

static void	sort_four(t_lst **a_stack, t_lst **b_stack)
{
	if (is_order(a_stack, 4) == 1)
		return ;
	rotate_to_min(a_stack, 4);
	do_pb(a_stack, b_stack);
	reset_arg_index(a_stack);
	sort_tree(a_stack);
	do_pa(a_stack, b_stack);
}

void	stack_sort(t_lst **a_stack, t_lst **b_stack)
{
	int	size;

	size = lst_size(*a_stack);
	if (size == 3)
		sort_tree(a_stack);
	else if (size == 4)
		sort_four(a_stack, b_stack);
	else
	{
		if (is_order(a_stack, 5) == 1)
			return ;
		rotate_to_min(a_stack, 5);
		do_pb(a_stack, b_stack);
		reset_arg_index(a_stack);
		sort_four(a_stack, b_stack);
		do_pa(a_stack, b_stack);
	}
}
