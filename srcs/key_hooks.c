
#include "../include/cub3d.h"

int	handle_key(int key, t_cub3d *cub)
{
	if (key == ESC_L)
		exit_program(cub);
	printf("%d\n", key);
	return (0);
}
