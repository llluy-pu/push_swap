/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:59:01 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/01 21:59:10 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*node;

	if (*stack_from == NULL)
		return ;
	node = *stack_from;
	*stack_from = (*stack_from)->next;
	node->next = NULL;
	ft_lstadd_front(stack_to, node);
}

void	pa(t_list **stack_a, t_list **stack_b, t_bool silent)
{
	push(stack_b, stack_a);
	if (!silent)
		ft_putendl("pa");
}

void	pb(t_list **stack_a, t_list **stack_b, t_bool silent)
{
	push(stack_a, stack_b);
	if (!silent)
		ft_putendl("pb");
}
