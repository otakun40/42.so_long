/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:46:20 by pjacoby           #+#    #+#             */
/*   Updated: 2021/10/23 22:46:20 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_numlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_get_strnum(char *dest, long nb, char sign, int len)
{
	int		i;

	if (nb == 0)
		dest[0] = '0';
	else
	{
		if (sign)
			dest[0] = '-';
		i = 1;
		while (nb != 0)
		{
			dest[len - i] = nb % 10 + '0';
			nb /= 10;
			if (nb != 0)
				i++;
		}
	}
	dest[len] = 0;
	return (dest);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	sign;
	char	*result;

	nb = n;
	sign = 0;
	len = ft_get_numlen(nb);
	if (nb < 0)
	{
		nb *= -1;
		sign = 1;
		len++;
	}
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (result)
		result = ft_get_strnum(result, nb, sign, len);
	return (result);
}
