NAME = push_swap

SRCS = src/main.c \
       src/parsing/parse.c src/parsing/validate.c \
       src/operations/push.c src/operations/swap.c \
       src/operations/rotate.c src/operations/reverse_rotate.c \
       src/algorithm/sort_small.c src/algorithm/indexing.c \
       src/algorithm/chunk_push_utils.c src/algorithm/chunk_push_to_b.c \
       src/algorithm/chunk_return.c src/algorithm/chunk_sort.c \
       src/utils/stack_utils.c src/utils/stack_utils_2.c


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I libft -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
