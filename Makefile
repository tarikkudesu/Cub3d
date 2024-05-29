SRC			=	main.c \
				utils/talloc.c \
				srcs/window_handling.c \
				utils/ft_putendl_fd.c \
				utils/error.c \
				srcs/key_hooks.c

CC			=	cc
NAME		=	cub3d
HEADER		=	include/cub3d.h include/struct.h
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -g
# MLXFLAGS	=	-L MLX -l mlx -framework OpenGL -framework AppKit
MLXFLAGS_L	=	-L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd


all: $(NAME)
	
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS_L)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
