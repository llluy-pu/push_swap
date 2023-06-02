/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:15:25 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/02 20:53:24 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_two(t_list **stack_a)
{
	if (is_stack_a_sorted(*stack_a, NULL))
		return (*stack_a);
	sa(stack_a, false);
	return (*stack_a);
}

t_list	*sort_three(t_list **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	while (is_stack_a_sorted(*stack_a, NULL) == false)
	{
		first = (*stack_a)->content;
		second = (*stack_a)->next->content;
		third = (*stack_a)->next->next->content;
		if (first->index > second->index && first->index > third->index)
			ra(stack_a, false);
		else if (second->index > first->index && second->index > third->index)
			rra(stack_a, false);
		else if (first->index > second->index)
			sa(stack_a, false);
		else
			exit_print("Couldn't sort three numbers.");
	}
	return (*stack_a);
}

t_list	*sort_upto_three(t_list **stack_a)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size == 1)
		return (*stack_a);
	if (size == 2)
		return (sort_two(stack_a));
	if (size == 3)
		return (sort_three(stack_a));
	return (NULL);
}
