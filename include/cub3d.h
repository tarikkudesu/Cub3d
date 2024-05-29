/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:04:05 by tamehri           #+#    #+#             */
/*   Updated: 2024/05/15 12:47:10 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
// # include "../MLX/mlx.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "struct.h"

# ifdef D
#  define _MAL_CALL_INFO() \
    printf("\t\tFile: \033[35m%s\033[0m, Line: \033[35m%d\033[0m, Function: \033[35m%s\033[0m\n", __FILE__, __LINE__, __func__)
# endif

# ifndef D
#  define D 0
#  define _MAL_CALL_INFO() 1
# endif

/* FUNCTIONS */
int		handle_key(int key, t_cub3d *cub);
int		exit_program(t_cub3d *cub);
void	ft_putendl_fd(char *s, int fd);
int		init_window(t_cub3d *cub);
void	*talloc(t_heap **heap, size_t __size);
void	clearheap(t_heap **node);
void	leaks();

#endif
