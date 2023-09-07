SRC =		main.c

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
