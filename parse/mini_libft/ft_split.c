/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:26:36 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/21 09:43:28 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i) && *(s + i) == c)
		i++;
	while (*(s + i))
	{
		while (*(s + i) && *(s + i) != c)
			i++;
		count++;
		while (*(s + i) && *(s + i) == c)
			i++;
	}
	return (count);
}

static void	free_space(char **str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(*(str + i));
		i++;
	}
	free(str);
}

static const char	*get_offset(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count(s, c);
	strings = (char **)malloc((words + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	i = 0;
	while (i < words)
	{
		s = get_offset(s, c);
		*(strings + i) = ft_substr(s, 0, len_word(s, c));
		if (!*(strings + i))
		{
			free_space(strings, i);
			return (NULL);
		}
		i++;
		s += len_word(s, c);
	}
	*(strings + i) = NULL;
	return (strings);
}
