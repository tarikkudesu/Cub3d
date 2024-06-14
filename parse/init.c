
#include "../include/cub3d.h"

t_door *new_door(t_cub3d *cub, int x, int y)
{
	t_door *door;

	door = talloc(&cub->heap, sizeof(t_door *)); _MAL_CALL_INFO();
	if (!door)
		return (NULL);
	door->x = x;
	door->y	= y;
	door->isopen = 0;
	door->ismoving = 0;
	door->progress = 0.f;
	door->next = NULL;
	return (door);
}

void	door_addback(t_cub3d *cub, t_door *door)
{
	t_door *tmp;

	if (!cub->doors)
	{
		cub->doors = door;
		return ;
	}
	tmp = cub->doors;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = door;
}

int	init_doors(t_cub3d *cub)
{
	t_door *door;

	cub->doors_n = 4;
	door = new_door(cub, 5, 6);
	door_addback(cub, door);
	door = new_door(cub, 10, 2);
	door_addback(cub, door);
	door = new_door(cub, 11, 9);
	door_addback(cub, door);
	door = new_door(cub, 16, 6);
	door_addback(cub, door);




	int fd = open("maps/nova.cub", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	cub->map = (int **)talloc(&cub->heap, sizeof(int *) * cub->map_height); _MAL_CALL_INFO();
	if (!cub->map)
	{
		perror("malloc");
		exit(1);
	}
	for (int i = 0; i < cub->map_height; i++) {
		cub->map[i] = (int *)talloc(&cub->heap, sizeof(int) * cub->map_width); _MAL_CALL_INFO();
		if (!cub->map[i])
		{
			perror("malloc 2");
			exit(1);
		}
		for (int j = 0; j < cub->map_width; j++)
			cub->map[i][j] = 2;
	}
	char	str[cub->map_width + 1];
	for (int i = 0; i < cub->map_height; i++) {
		read(fd, str, cub->map_width + 1);
		str[cub->map_width + 1] = '\0';
		for (int j = 0; j < cub->map_width; j++) {
			cub->map[i][j] = str[j] - 48;
		}
	} 
	return (0);
}

