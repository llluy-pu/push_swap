/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_three_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:41:28 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/01 21:59:09 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_steps(long int cost_a, long int cost_b)
{
	long int	steps;

	steps = 0;
	while (cost_a != 0 || cost_b != 0)
	{
		if (cost_a > 0 && cost_b > 0)
		{
			steps++;
			cost_a--;
			cost_b--;
		}
		else if (cost_a < 0 && cost_b < 0)
		{
			steps++;
			cost_a++;
			cost_b++;
		}
		else
		{
			steps += (ft_abs(cost_a) + ft_abs(cost_b));
			cost_a = 0;
			cost_b = 0;
		}
	}
	return (steps);
}

static void	get_and_do_best_move(t_list	**stack_a, t_list **stack_b)
{
	t_list		*node;
	long int	best_cost_a;
	long int	best_cost_b;
	long int	steps;

	node = *stack_b;
	steps = LONG_MAX;
	while (node)
	{
		if (get_steps(node->content->cost_a, node->content->cost_b) < steps)
		{
			best_cost_a = node->content->cost_a;
			best_cost_b = node->content->cost_b;
			steps = get_steps(node->content->cost_a, node->content->cost_b);
		}
		node = node->next;
	}
	chose_and_do_rr_or_r(stack_a, stack_b, best_cost_a, best_cost_b);
}

static void	get_cost_stack(t_list *stack_a, t_list *stack_b)
{
	size_t	pos_max_b;
	size_t	pos_max_a;

	pos_max_b = ft_lstsize(stack_b);
	pos_max_a = ft_lstsize(stack_a);
	while (stack_b)
	{
		if (pos_max_b - stack_b->content->pos < stack_b->content->pos)
		{
			stack_b->content->cost_b = pos_max_b - stack_b->content->pos;
			stack_b->content->cost_b = -stack_b->content->cost_b;
		}	
		else
			stack_b->content->cost_b = stack_b->content->pos;
		if (pos_max_a - stack_b->content->target_pos < \
			stack_b->content->target_pos)
		{
			stack_b->content->cost_a = pos_max_a - stack_b->content->target_pos;
			stack_b->content->cost_a = -stack_b->content->cost_a;
		}	
		else
			stack_b->content->cost_a = stack_b->content->target_pos;
		stack_b = stack_b->next;
	}
}

static void	sort_stack_a(t_list **stack_a)
{
	long int		pos_lower_index;
	t_list			*node;
	long int		size;

	get_position_stack(*stack_a, NULL);
	node = *stack_a;
	pos_lower_index = 0;
	while (node)
	{
		if (node->content->index == 1)
		{
			pos_lower_index = node->content->pos;
			break ;
		}
		node = node->next;
	}
	size = (long int)ft_lstsize(*stack_a);
	if (size - pos_lower_index < pos_lower_index)
	{
		pos_lower_index = size - pos_lower_index;
		pos_lower_index = -pos_lower_index;
	}
	chose_and_do_rr_or_r(stack_a, NULL, pos_lower_index, 0);
}

void	sort_morethan_three(t_list **stack_a, t_list **stack_b)
{
	create_stack_b(stack_a, stack_b);
	sort_upto_three(stack_a);
	while (!is_stacks_sort(*stack_a, *stack_b))
	{
		get_position_stack(*stack_a, *stack_b);
		get_target_position_stack(*stack_a, *stack_b);
		get_cost_stack(*stack_a, *stack_b);
		get_and_do_best_move(stack_a, stack_b);
		pa(stack_a, stack_b, false);
		if (*stack_b == NULL)
			sort_stack_a(stack_a);
	}
}
