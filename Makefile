SRC = 		src/cub3d.c \
			src/init/init.c \
			src/init/get_file.c \
			src/init/get_mapconf.c \
			src/init/check_mapconf.c \
			src/init/check_params.c \
			src/init/get_map.c \
			src/init/check_map.c \
			src/init/check_wall.c \
			src/init/check_xpm.c \
			src/utils/utils_char.c \
			src/utils/utils_color.c \
			src/utils/utils_error.c \
			src/utils/utils_mem.c \
			src/utils/cb_split.c \
			src/utils/utils_map.c \
			src/utils/utils_params.c \
			src/utils/utils_debug.c \
			game/init_player_datas.c \
			game/raycasting.c\
			game/raycasting_utils.c\
			game/vector_operations.c\
			game/print.c \
			game/print_test.c \
			game/keys.c \
			game/movements.c \
			game/get_texture_datas.c

OSRC = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

NAME = cub3D

B	= \033[0;96m
E	= \033[0m

all: nice_text $(NAME)

nice_text:
	@echo "$(B)"
	@echo " ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ "
	@echo "██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗"
	@echo "██║     ██║   ██║██████╔╝ █████╔╝██║  ██║"
	@echo "██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║"
	@echo "╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝"
	@echo " ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝"
	@echo "$(E)" 

$(NAME): $(OSRC)
	make -C libft
	cp libft/libft.a .
	make -C mlx
	cp mlx/libmlx.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OSRC) -lft -lmlx -L. -framework OpenGL -framework AppKit

norminette:
	norminette $(SRC)
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
