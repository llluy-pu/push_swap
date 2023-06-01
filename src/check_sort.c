/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:53:39 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/01 21:59:02 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_stacks_sort(t_list *stack_a, t_list *stack_b)
{
	int	max_value;

	if (stack_b != NULL)
		return (false);
	if (ft_lstsize(stack_a) == 1)
		return (true);
	max_value = stack_a->content->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (max_value < stack_a->content->value)
			max_value = stack_a->content->value;
		else
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}
