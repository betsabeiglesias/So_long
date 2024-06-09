NAME = so_long

SRCS = so_long.c so_long_utils.c \
	so_long_checkmap.c \
	so_long_images.c\
	so_long_keys.c \
	so_long_floodfill.c


OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

INCLUDES = -I./lib/ft_printf/ -I./lib/mlx/

LIBS = -L./lib/ft_printf/ -L./lib/mlx/

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(NAME): $(OBJS) so_long.h
	make -C ./lib/ft_printf
	make -C ./lib/mlx
	$(CC) $(CFLAGS) $(LIBS) -lftprintf -lmlx -framework OpenGl -framework AppKit $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ./lib/ft_printf
	make clean -C ./lib/mlx

fclean:
	rm -f $(NAME)
	make fclean -C ./lib/ft_printf
	make clean

re: fclean all

.PHONY: all clean fclean re

