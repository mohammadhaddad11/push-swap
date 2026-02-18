NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -Ilibft -Idprintf
RM = rm -f

SRC = src/push_swap.c src/disorder.c src/bench.c \
      src/algorithms/algorithms.c src/algorithms/chunk_sort.c src/algorithms/radix_sort.c \
      src/operations/push.c src/operations/swap.c src/operations/rotate.c src/operations/reverse_rotate.c \
      src/utils/parse.c src/utils/push_swap_utils.c src/utils/input_checks.c \
      src/utils/stack_utils.c src/utils/node_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
PRINTF = dprintf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(PRINTF):
	$(MAKE) -C dprintf

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C dprintf clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C dprintf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
