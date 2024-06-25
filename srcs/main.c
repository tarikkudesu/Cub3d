/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:29:48 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/25 17:29:33 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	cub;

	if (ac != 2)
		return (putendl_fd("Error bad number of arguments", 2), 1);
	get_cub(&cub);
	initialize_data(&cub);
	if (!file_parse(&cub, av[1]))
		return (2);
	set_data(&cub);
	if (init_window(&cub))
		return (0);
}
