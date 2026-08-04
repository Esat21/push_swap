CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./include/ -I ./libft/

NAME = push_swap

SRCS =	main.c \
		src/push_swap.c \
		src/utils.c \
		src/additional_functions.c \
		src/bench.c \
		src/clear_operations.c \
		src/disorder_metric.c \
		src/list_operations.c \
		src/normalisation.c \
		src/ps_rules_handling.c \
		src/ps_rules.c \
		src/stack_creation.c \
		src/flags_check.c \
		src/input_check.c \
		src/flattern_args.c \
		src/sorting_algorithms/simple_algorithm.c \
		src/sorting_algorithms/medium_algorithm.c \
		src/sorting_algorithms/complex_algorithm.c \
		src/sorting_algorithms/complex_algorithm_utils.c \
		src/sorting_algorithms/adaptive_algorithm.c \
		bonus/checker_main.c \
		bonus/checker_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $^ -o $@ ./libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean:
	make fclean -C ./libft
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
