CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./include/ -I ./libft/

NAME = push_swap
BONUS = checker

SRCS =	main.c \
		src/push_swap.c \
		src/utils.c \
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
		src/sorting_algorithms/algorithms_utils.c \
		src/sorting_algorithms/adaptive_algorithm.c


SRCS_BONUS =	./bonus/checker_main.c \
				./bonus/checker_rules.c \
				./bonus/checker_utils.c \
				./bonus/clear_operations.c \
				./bonus/disorder_metric.c \
				./bonus/flattern_args.c \
				./bonus/input_check.c \
				./bonus/list_operations.c \
				./bonus/ps_rules.c \
				./bonus/stack_creation.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft 
	$(CC) $(CFLAGS) $^ -o $@ ./libft/libft.a

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS)
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

bonus-clean:
	make clean -C ./libft
	rm -f $(OBJS_BONUS)

bonus-fclean:
	make fclean -C ./libft
	rm -f $(OBJS_BONUS) $(BONUS)

bonus-re: bonus-fclean bonus

.PHONY: all clean fclean re bonus bonus-clean bonus-fclean bonus-re
