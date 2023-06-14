/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:57:03 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/14 16:55:56 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duplucate_check(t_lst *stack)
{
	int		tmp;
	t_lst	*dup;

	while (stack && stack->next)
	{
		tmp = stack->content;
		dup = stack;
		while (dup->next)
		{
			dup = dup->next;
			if (dup->content == tmp)
				return (-1);
		}
		stack = stack->next;
	}
	return (1);
}

static void	ps_stackclear(t_lst **stack)
{
	if (!stack || !(*stack))
		return ;
	ps_stackclear(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

static int	stack_init(int ac, char **av, t_lst **a_stack)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < ac)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		if (!split[j])
			return (0);
		while (split[j])
		{
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				return (0);
			lst_addback(a_stack, lst_new(ft_atoi(split[j])));
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}

void	exit_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_lst	*a_stack;
	t_lst	*b_stack; 

	if (ac == 1)
		exit_error();
	a_stack = NULL;
	b_stack = NULL;
	if (stack_init(ac, av, &a_stack) == 0 || duplucate_check(a_stack) == -1)
		exit_error();
	else
	{
		arg_index(&a_stack);
		if (sort_check(&a_stack) != 1)
		{
			if (lst_size(a_stack) <= 5)
				stack_sort(&a_stack, &b_stack);
			else
				radix_sort(&a_stack, &b_stack);
		}
	}
	ps_stackclear(&a_stack);
	ps_stackclear(&b_stack);
	return (0);
}

/*
  What main does:
  - Check if there is any parametres
  - Create two stacks
  - Check if the parametres are valid
  - Check if there is any duplicate in the stack
  - Add the parametres to the stack
  - Add the index to the stack
  - Check if the stack is sorted
  - If the stack is not sorted:
	- If the stack size is less than 5:
	  - Sort the stack
	- Else:
	  - Sort the stack with radix sort
  - Free the stacks
  - Return 0

  What stack_init does:
  - Create a new stack
  - Split the parametres into a new array
  - Check if the parametres are valid
  - Add the parametres to the stack
  - Free the array
  - Return 1 if everything is ok
  - Return 0 if there is an error
  
  What duplucate_check does:
  - Check if there is any duplicate in the stack
  - Return 1 if there is no duplicate
  - Return -1 if there is a duplicate
  
  What ps_index does:
  - Add the index to the stack

  What sort_check does:
  - Check if the stack is sorted
  - Return 1 if the stack is sorted
  - Return 0 if the stack is not sorted

  What lst_size does:
  - Return the size of the stack

  What stack_sort does:
  - Sort the stack

  What radix_sort does:
  - Sort the stack with radix sort

  What ps_stackclear does:
  - Free the stack
*/