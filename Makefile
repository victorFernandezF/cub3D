SRC = 		src/cub3d.c \
			src/init/init.c \
			src/init/get_file.c \
			src/init/get_mapconf.c \
			src/init/check_params.c \
			src/init/get_map.c \
			src/init/check_map.c \
			src/init/check_wall.c \
			src/utils/utils_char.c \
			src/utils/utils_color.c \
			src/utils/utils_error.c \
			src/utils/utils_mem.c \
			src/utils/cb_split.c \
			src/utils/utils_map.c


OSRC = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

NAME = cub3D

all: $(NAME)

$(NAME): $(OSRC)
	make -C libft
	cp libft/libft.a .
	make -C mlx
	cp mlx/libmlx.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OSRC) -lft -lmlx -L. -framework OpenGL -framework AppKit

clean:
	make clean -C libft
	make clean -C mlx
	$(RM) $(OSRC)

fclean: clean
		make fclean -C libft
		$(RM) libft.a
		$(RM) libmlx.a
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
