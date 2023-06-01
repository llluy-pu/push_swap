/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:18:57 by llluy-pu          #+#    #+#             */
/*   Updated: 2022/09/09 18:19:04 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace_static(int c)
{
	if (c == ' ')
		return (8192);
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (8192);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t			i;
	unsigned int	nbr;
	int				signe;

	i = 0;
	nbr = 0;
	signe = 1;
	while (ft_isspace_static(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] == '0')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (signe * nbr);
}
