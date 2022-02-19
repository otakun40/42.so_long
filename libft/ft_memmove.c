/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:46:20 by pjacoby           #+#    #+#             */
/*   Updated: 2021/10/23 22:46:20 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	char		*s;
	size_t		i;

	d = (char *)dst;
	s = (char *)src;
	if (src || dst)
	{
		if (d <= s)
		{
			i = -1;
			while (++i < len)
				d[i] = s[i];
		}
		else
		{
			i = (int)len;
			while (i > 0)
			{
				d[i - 1] = s[i - 1];
				i--;
			}
		}
	}
	return (d);
}
