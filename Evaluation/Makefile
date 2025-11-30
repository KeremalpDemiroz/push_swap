NAME= push_swap
CC= cc
CFLAGS= -Wall -Werror -Wextra

SRCS=	push_swap.c\
		char_to_int.c\
		radix_sort.c\
		sort_int.c\
		sorting_moves_a.c\
		sorting_moves_b.c\
		stack_utils.c\
		under_nine.c\
		utils.c\

LIBFT= ./sources
LIBFT_A= $(LIBFT)/libft.a

OBJS= $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all:$(NAME)
$(NAME):$(OBJS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_A) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)

fclean:clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re


