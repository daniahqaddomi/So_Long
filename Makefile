NAME = so_long

FILES = so_long.c \
		read_map.c \
		 checks.c	\
		 map.c		\
		 key.c		\
		 flood.c
		 
OFILES = $(FILES:%.c=%.o)

LIBFT = libft/libft.a
CC = cc
MLX_FLAGS = -lmlx -lX11 -lXext
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Ilibft -g

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) $(LIBFT) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OFILES)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
