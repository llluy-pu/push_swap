/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:11:03 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/01 21:59:14 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_print(char *str)
{
	ft_putstr_fd("Error message : ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

long int	ft_abs(long int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

void	free_double_ptr_char(char **arr_char)
{
	size_t	i;

	i = 0;
	while (arr_char[i])
	{
		free(arr_char[i]);
		i++;
	}
	free(arr_char);
}
