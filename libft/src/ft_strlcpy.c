/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:24:05 by llluy-pu          #+#    #+#             */
/*   Updated: 2022/04/19 22:19:49 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy_static(char *dest, const char *src, size_t n)
{
	ft_bzero((void *)dest, n);
	if (ft_strlen(src) < n)
		ft_memcpy(dest, src, ft_strlen(src));
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size > len_src)
	{
		dst = ft_strncpy_static(dst, src, len_src);
		dst[len_src] = 0;
	}
	else
	{
		dst = ft_strncpy_static(dst, src, (size - 1));
		dst[size - 1] = 0;
	}
	return (len_src);
}
