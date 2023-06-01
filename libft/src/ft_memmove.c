/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 03:04:14 by llluy-pu          #+#    #+#             */
/*   Updated: 2022/04/10 01:10:26 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
		while (n-- > 0)
			*d++ = *s++;
	else
		while (n-- > 0)
			*(d + n) = *(s + n);
	return (dest);
}
