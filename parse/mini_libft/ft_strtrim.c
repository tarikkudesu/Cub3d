/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:29:34 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/24 19:41:12 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	len(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

static int	is_in(const char c, const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i++) == c)
			return (1);
	}
	return (0);
}

static int	last(const char *s, const char *set, int l)
{
	while (is_in(*(s + l), set))
		l--;
	return (l);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		length;

	if (!set)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	i = 0;
	while (*(s1 + i) && is_in(*(s1 + i), set))
		i++;
	if (!*(s1 + i))
		return (ft_strdup(""));
	length = last(s1, set, len(s1) - 1) - i + 2;
	str = (char *)talloc(length * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < length - 1)
		*(str + j++) = *(s1 + i++);
	*(str + j) = '\0';
	return (str);
}
