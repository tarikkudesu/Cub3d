SRC			=	main.c \
				srcs/colors.c \
				srcs/dda.c \
				srcs/draw_line.c \
				srcs/frame_processing.c \
				srcs/key_hooks.c \
				srcs/mini_map.c \
				srcs/mouse_hooks.c \
				srcs/pole.c \
				srcs/ray_processing.c \
				srcs/update_frame.c \
				srcs/window_handling.c \
				utils/error.c \
				utils/putendl_fd.c \
				utils/talloc.c

CC			=	cc
NAME		=	cub3D
HEADER		=	include/cub3d.h include/struct.h
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -g
# MLXFLAGS	=	-L./MLX -l mlx -framework OpenGL -framework AppKit
MLXFLAGS_L	=	-L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd


all: $(NAME) clean
	
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
