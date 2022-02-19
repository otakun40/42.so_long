/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:46:20 by pjacoby           #+#    #+#             */
/*   Updated: 2021/10/24 00:15:59 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	if (*needle == 0)
		return (hay);
	needle_len = ft_strlen(needle);
	while (hay[i] && len && hay[i + needle_len - 1])
	{
		if (needle_len <= len)
		{
			if (!ft_strncmp(hay + i, needle, needle_len))
				return (hay + i);
		}
		i++;
		len--;
	}
	return (NULL);
}
