NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c push_swap.c parse.c split.c stack.c swap.c push.c \
      rotate.c reverse_rotate.c algorithms.c push_swap_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

INCLUDES = -I. -Ilibft -Iprintf

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C printf
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C libft clean
	make -C printf clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	make -C printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
