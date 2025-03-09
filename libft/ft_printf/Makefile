NAME    = libftprintf.a

FILES   = ft_printf \
          ft_putchar \
          ft_putstring \
          ft_putnumber \
          ft_put_unsigned_number \
          ft_put_hexadecimal \
          ft_hexadecimal_digit \
          ft_putpointer 

CFILES  = $(FILES:%=%.c)
OFILES  = $(FILES:%=%.o)

CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
