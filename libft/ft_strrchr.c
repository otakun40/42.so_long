/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:46:20 by pjacoby           #+#    #+#             */
/*   Updated: 2021/10/23 22:46:20 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;

	pos = 0;
	while (*s)
	{
		if (*s == (char)c)
			pos = (char *)s;
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	return (pos);
}
