/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:25:26 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/21 10:05:02 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (cc == *(s + i))
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
