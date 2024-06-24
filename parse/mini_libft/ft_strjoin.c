/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:18:21 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/21 16:45:18 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		len;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	s = (char *)malloc(len * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (*s1)
		*(s + i++) = *s1++;
	while (*s2)
	{
		*(s + i++) = *s2;
		s2++;
	}
	*(s + i) = '\0';
	return (s);
}
