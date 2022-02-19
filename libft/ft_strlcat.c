/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:46:20 by pjacoby           #+#    #+#             */
/*   Updated: 2021/10/23 22:46:20 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	slen;

	dstlen = 0;
	slen = ft_strlen(src);
	while (*dst && dstsize > 0)
	{
		dst++;
		dstlen++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst = *src;
		dstsize--;
		dst++;
		src++;
	}
	if (dstsize == 1 || *src == '\0')
		*dst = '\0';
	return (dstlen + slen);
}
