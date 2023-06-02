/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:08:34 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/02 21:37:59 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list *create_node(int value)
{
	t_stack *node = malloc(sizeof(*node));
	if (node == NULL)
		return NULL;
	node->value = value;
	node->cost_a = -1;
	node->cost_b = -1;
	node->index = 0;
	node->pos = 0;
	node->target_pos = 0;
	t_list *list = malloc(sizeof(*list));
	if (list == NULL)
	{
		free(node);
		return NULL;
	}
	list->content = node;
	list->next = NULL;
	return list;
}

t_list	*create_list(int ac, char **av)
{
	unsigned int	i;
	t_list			*node;
	t_list			*stack_a;
	int				*array;
	unsigned int	size;

	array = check_args(ac, av, &size);
	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		node = create_node(array[i++]);
		if (node == NULL)
		{
			ft_lstclear(&stack_a, free);
			free(array);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&stack_a, node);
	}
	get_index(stack_a);
	free(array);
	return (stack_a);
}
