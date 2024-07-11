SRCS	=	./srcs/dda.c \
			./srcs/init.c \
			./srcs/main.c \
			./srcs/doors.c \
			./parse/bools.c \
			./parse/parse.c \
			./srcs/images.c \
			./utils/talloc.c \
			./srcs/boolean.c \
			./utils/terror.c \
			./srcs/mini_map.c \
			./utils/lst_img.c \
			./srcs/draw_line.c \
			./srcs/key_hooks.c \
			./srcs/utilities.c \
			./utils/lst_door.c \
			./utils/lst_heap.c \
			./utils/lst_line.c \
			./parse/fill_data.c \
			./parse/parse_map.c \
			./srcs/collisions.c \
			./srcs/mouse_hooks.c \
			./srcs/ray_casting.c \
			./srcs/update_door.c \
			./utils/lst_sprite.c \
			./parse/parse_map_2.c \
			./srcs/update_hooks.c \
			./srcs/update_frame.c \
			./parse/parse_header.c \
			./srcs/render_column.c \
			./parse/get_next_line.c \
			./srcs/sprites/sprites.c \
			./srcs/window_handling.c \
			./srcs/sprites/set_sprite.c \
			./parse/mini_libft/ft_atoi.c \
			./srcs/sprites/init_sprite.c \
			./parse/get_next_line_utils.c \
			./parse/mini_libft/ft_split.c \
			./parse/mini_libft/ft_strchr.c \
			./parse/mini_libft/ft_strdup.c \
			./parse/mini_libft/ft_strlen.c \
			./parse/mini_libft/ft_substr.c \
			./parse/mini_libft/ft_strjoin.c \
			./parse/mini_libft/ft_strncmp.c \
			./parse/mini_libft/ft_strrchr.c \
			./parse/mini_libft/ft_strtrim.c \
			./parse/mini_libft/putendl_fd.c

CC			=	cc
NAME		=	cub3D
HEADER		=	./include/cub3d.h ./include/macros.h ./include/struct.h
OBJ			=	$(SRCS:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L/usr/local/lib -l mlx -framework OpenGL -framework AppKit

all: $(NAME)
	
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
