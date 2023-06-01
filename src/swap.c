/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:20:43 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/01 21:59:12 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*node;
	t_list	*third_node;

	if (stack == NULL)
		return ;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	node = *stack;
	third_node = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = node;
	(*stack)->next->next = third_node;
	return ;
}

void	sa(t_list **stack_a, t_bool silent)
{
	swap(stack_a);
	if (!silent)
		ft_putendl("sa");
}

void	sb(t_list **stack_b, t_bool silent)
{
	swap(stack_b);
	if (!silent)
		ft_putendl("sb");
}

void	ss(t_list **stack_a, t_list **stack_b, t_bool silent)
{
	swap(stack_a);
	swap(stack_b);
	if (!silent)
		ft_putendl("ss");
}
