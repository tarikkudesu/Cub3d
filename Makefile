SRC			=		./main.c      \
					./srcs/dda.c   \
					./srcs/colors.c \
					./utils/error.c  \
					./utils/talloc.c  \
					./srcs/mini_map.c  \
					./srcs/draw_line.c  \
					./srcs/key_hooks.c   \
					./srcs/utilities.c    \
					./srcs/collisions.c    \
					./srcs/mouse_hooks.c    \
					./srcs/render_wall.c     \
					./utils/putendl_fd.c      \
					./srcs/update_frame.c      \
					./srcs/ray_processing.c     \
					./srcs/window_handling.c

CC			=	cc
NAME		=	cub3D
HEADER		=	include/cub3d.h include/struct.h
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-L./MLX -l mlx -framework OpenGL -framework AppKit
# MLXFLAGS_L	=	-L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd


all: $(NAME)
	
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS_L) $(MLXFLAGS)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
