SRC			=	main.c \
				utils/talloc.c \
				srcs/window_handling.c \
				utils/putendl_fd.c \
				utils/error.c \
				srcs/key_hooks.c \
				srcs/draw_line.c \
				srcs/update_frame.c \
				srcs/frame_processing.c \
				srcs/ray_processing.c \
				srcs/dda.c

CC			=	cc
NAME		=	cub3d
HEADER		=	include/cub3d.h include/struct.h
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-L./MLX -l mlx -framework OpenGL -framework AppKit
# MLXFLAGS_L	=	-L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd


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
