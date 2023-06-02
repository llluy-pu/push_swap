/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:53:39 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/02 21:05:21 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_stack_a_sorted(t_list *stack_a, t_list *stack_b)
{
	int	prev_value;

	if (stack_b != NULL) return (false);
	if (ft_lstsize(stack_a) == 1) return (true);
	prev_value = stack_a->content->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (prev_value > stack_a->content->value)
			return (false);
		prev_value = stack_a->content->value;
		stack_a = stack_a->next;
	}
	return (true);
}

/*
 t_bool is a function that returns a boolean value 
  	which is either true or false.
 If stack_b is NULL return false which means the stack_b is empty.
 If the size of stack_a is 1 return true which means the stack_a is sorted.
 prev_value is the value of the first element of stack_a then move
	to the next element.
 Iterate through the stack_a and compare the prev_value with the
	current value of the stack_a if the current value is bigger than
	the prev_value return false which means the stack_a is not sorted.
*/

// t_bool	is_stack_a_sorted(t_list *stack_a, t_list *stack_b)
// {
// 	int	max_value;

// 	if (stack_b != NULL)
// 		return (false);
// 	if (ft_lstsize(stack_a) == 1)
// 		return (true);
// 	max_value = stack_a->content->value;
// 	stack_a = stack_a->next;
// 	while (stack_a)
// 	{
// 		if (max_value < stack_a->content->value)
// 			max_value = stack_a->content->value;
// 		else
// 			return (false);
// 		stack_a = stack_a->next;
// 	}
// 	return (true);
// }