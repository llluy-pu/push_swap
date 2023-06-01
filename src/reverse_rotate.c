/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:39:37 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/01 21:59:11 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*node;

	if (*stack == NULL || stack == NULL)
		return ;
	node = *stack;
	if (node->next == NULL)
		return ;
	while (node->next->next != NULL)
		node = node->next;
	ft_lstadd_front(stack, node->next);
	node->next = NULL;
}

void	rra(t_list **stack_a, t_bool silent)
{
	if (*stack_a)
		reverse_rotate(stack_a);
	if (!silent)
		ft_putendl("rra");
}

void	rrb(t_list **stack_b, t_bool silent)
{
	if (*stack_b)
		reverse_rotate(stack_b);
	if (!silent)
		ft_putendl("rrb");
}

void	rrr(t_list **stack_a, t_list **stack_b, t_bool silent)
{
	if (stack_a)
		reverse_rotate(stack_a);
	if (stack_b)
		reverse_rotate(stack_b);
	if (!silent)
		ft_putendl("rrr");
}
