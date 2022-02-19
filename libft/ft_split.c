/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:46:20 by pjacoby           #+#    #+#             */
/*   Updated: 2022/01/29 23:37:39 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		if ((*str != c && *(str + 1) == c)
			|| (*str != c && *(str + 1) == 0))
			count++;
		str++;
	}
	return (count);
}

static char	*ft_get_word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word)
	{
		word[i] = 0;
		i--;
		while (i >= 0)
		{
			word[i] = s[i];
			i--;
		}
	}
	return (word);
}

static char	**ft_get_one_string(const char *string)
{
	char	**res;

	if (!*string)
	{
		res = (char **) malloc(sizeof(char *) * 1);
		if (res)
			res[0] = NULL;
		return (res);
	}
	res = (char **) malloc(sizeof(char *) * 2);
	if (res)
	{
		res[0] = ft_strdup(string);
		res[1] = 0;
	}
	return (res);
}

static char	**ft_clear_str_array(char **array)
{
	while (*array)
		free(*array++);
	free(array);
	array = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**result;

	if (!s)
		return (NULL);
	if (c == '\0')
		return (ft_get_one_string(s));
	i = -1;
	words = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	while (++i < words)
	{
		while (*s && *s == c)
			s++;
		result[i] = ft_get_word(s, c);
		if (!result[i])
			return (ft_clear_str_array(result));
		while (*s && *s != c)
			s++;
	}
	result[i] = 0;
	return (result);
}
