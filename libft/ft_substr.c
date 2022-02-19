/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:46:20 by pjacoby           #+#    #+#             */
/*   Updated: 2021/10/23 22:46:20 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	slen;
	size_t	substringlen;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen((char *)s);
	if (len == 0 || start > slen)
		substringlen = 0;
	else if (start + len > slen)
		substringlen = slen - start;
	else
		substringlen = len;
	substring = (char *)malloc(sizeof(char) * (substringlen + 1));
	if (substring)
	{
		substring[substringlen] = 0;
		while (i < substringlen)
			substring[i++] = s[start++];
	}
	return (substring);
}
