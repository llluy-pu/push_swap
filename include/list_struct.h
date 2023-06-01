/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:01:06 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/01 22:01:09 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_STRUCT_H
# define LIST_STRUCT_H

# define T_LIST

typedef struct s_stack
{
	int				value;
	unsigned int	index;
	unsigned int	pos;
	unsigned int	target_pos;
	long int		cost_a;
	long int		cost_b;
}					t_stack;

typedef struct s_list
{
	t_stack			*content;
	struct s_list	*next;
}					t_list;

#endif