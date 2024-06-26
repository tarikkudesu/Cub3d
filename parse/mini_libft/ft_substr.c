/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:09:23 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/25 16:25:35 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*t;
	unsigned int	l;
	size_t			buff;

	if (!s)
		return (NULL);
	l = (unsigned int)ft_strlen((char *)s);
	i = 0;
	if (start >= l)
		return (ft_strdup(""));
	if (len > l - start)
		buff = l - start;
	else
		buff = len;
	t = (char *)talloc((buff + 1) * sizeof(char));
	if (!t)
		return (NULL);
	while (i < len && *(s + start + i))
	{
		*(t + i) = *(s + start + i);
		i++;
	}
	*(t + i) = '\0';
	return (t);
}
