#include "../include/cub3d.h"

bool	is_visible(t_cub3d *cub, int x, int y)
{
	return (cub->mapS[x][y].visited);
}

void	transform_sprite(t_cub3d *cub, double *trans_x, double *trans_y)
{
	double	inv_det;
	double	dx;
	double	dy;

	dx = cub->sprites->x - cub->player.pos.x;
	dy = cub->sprites->y - cub->player.pos.y;
	inv_det = 1.0 / (cub->player.plan.x * cub->player.dir.y \
		- cub->player.dir.x * cub->player.plan.y);
	*trans_x = inv_det * (cub->player.dir.y * dx - cub->player.dir.x * dy);
	*trans_y = inv_det * (cub->player.plan.x * dy - cub->player.plan.y * dx);
}

void	put_sprites(t_cub3d *cub)
{
	double	trans_x;
	double	trans_y;
	int		screen_x;

	transform_sprite(cub, &trans_x, &trans_y);
	screen_x = (int)((WIDTH / 2) * (1 + trans_x / trans_y));
	cub->sprites->height = abs((int)(HEIGHT / trans_y));
	cub->sprites->width = abs((int)(HEIGHT / trans_y));

	cub->sprites->start_x = - cub->sprites->width / 2 + screen_x;
	cub->sprites->end_x = cub->sprites->width / 2 + screen_x ;
	cub->sprites->start_y = HEIGHT / 2 - cub->sprites->height / 2;
	cub->sprites->end_y = HEIGHT / 2 + cub->sprites->height / 2;
}
