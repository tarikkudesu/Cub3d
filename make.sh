#!/bin/sh

file=$(find . -name "*.c" -not -path "./MLX*" -not -path "./minilibx-linux*")
if [ $# -gt 0 ]; then
	# cc -Wall -Wextra -Werror $file -o cub3D -g -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd -D Z=1
	cc -Wall -Wextra -Werror $file -o cub3D -g -L/usr/local/lib -l mlx -framework OpenGL -framework AppKit -D Z=1
	# make clean
else
	# cc -Wall -Wextra -Werror $file -o cub3D -g -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
	cc -Wall -Wextra -Werror $file -o cub3D -g -fsanitize=address -L/usr/local/lib -l mlx -framework OpenGL -framework AppKit
	# make clean
fi
