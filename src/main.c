/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:02:23 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/01 21:59:07 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list			*stack_a;
	t_list			*stack_b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	stack_a = create_chained_list(ac, av);
	stack_b = NULL;
	if (is_stacks_sort(stack_a, stack_b))
	{
		ft_lstclear(&stack_a, free);
		return (EXIT_SUCCESS);
	}
	else if (ft_lstsize(stack_a) <= 3)
		sort_upto_three(&stack_a);
	else
		sort_morethan_three(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
