NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c bench.c algorithms.c \
      Operations/push.c Operations/swap.c Operations/rotate.c Operations/reverse_rotate.c \
      utils/parse.c utils/push_swap_utils.c utils/stack_utils.c utils/node_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
PRINTF = dprintf/libftprintf.a

INCLUDES = -I. -Ilibft -Idprintf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C dprintf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C libft clean
	make -C dprintf clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	make -C dprintf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
