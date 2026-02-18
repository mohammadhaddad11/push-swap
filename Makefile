NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/push_swap.c src/disorder.c src/bench.c \
      src/algorithms/algorithms.c src/algorithms/chunk_sort.c src/algorithms/radix_sort.c \
      src/operations/push.c src/operations/swap.c src/operations/rotate.c src/operations/reverse_rotate.c \
      src/utils/parse.c src/utils/push_swap_utils.c src/utils/stack_utils.c src/utils/node_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
PRINTF = dprintf/libftprintf.a

INCLUDES = -I. -Iinclude -Ilibft -Idprintf

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
