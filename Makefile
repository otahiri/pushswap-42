
CC = cc

CFLAG = -Wall -Werror -Wextra

NAME = push_swap

HEADER = push_swap.h

SRCS = custom_atoi.c doubly_linked_list_funcs1.c doubly_linked_list_funcs2.c push_swap.c push_swap_utils2.c push_swap_utils3.c push_swap_utils.c

FT_PRINTF = libftprintf.a


all: $(NAME)

$(FT_PRINTF):
	make -C ./ft_printf all
	cp ./ft_printf/$(FT_PRINTF) .


$(NAME): $(HEADER) $(FT_PRINTF) $(SRCS)
	$(CC) -g $(CFLAGS) $(SRCS) $(FT_PRINTF) -o $(NAME)

clean:
	make -C ./ft_printf clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
