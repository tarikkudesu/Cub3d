
#include "../include/cub3d.h"

int	init_mlx(t_cub3d *cub)
{
	cub->mlx.__mlx = mlx_init();
	if (!cub->mlx.__mlx)
		return (ft_putendl_fd(ERR_MLX_INIT, 2), 1);
	cub->mlx.__win = mlx_new_window(cub->mlx.__mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->mlx.__win)
		return (ft_putendl_fd(ERR_MLX_WIN, 2), 1);
	return (0);	
}

int	init_window(t_cub3d *cub)
{
	if (init_mlx(cub))
		return (1);
	// for (int i = 0; i < 100; i++) {
	// 	for (int j = 0; j < 100; j++) {
	// 		mlx_pixel_put(cub->mlx.__mlx, cub->mlx.__win, i, j, 0xffffff);
	// 	}
	// }
	mlx_hook(cub->mlx.__win, 2, 1L<<0, handle_key, cub);
	mlx_hook(cub->mlx.__win, 17, 0, exit_program, cub);
	mlx_loop(cub->mlx.__mlx);
	return (0);
}