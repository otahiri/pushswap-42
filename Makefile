
CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

BONUS = checker

BONUS_HEADER = ft_checker_bonus.h

HEADER = push_swap.h

SRCS = custom_atoi.c custom_split.c custom_split_utils.c doubly_linked_list_funcs1.c doubly_linked_list_funcs2.c\
			 push_swap.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c push_swap_utils.c\
			 push_swap_utils6.c push_swap_utils7.c

BONUS_SRCS = custom_atoi_bonus.c custom_split_bonus.c doubly_linked_list_funcs1_bonus.c doubly_linked_list_funcs2_bonus.c\
						 ft_checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c push_swap_utils2_bonus.c push_swap_utils3_bonus.c\
						 push_swap_utils4_bonus.c push_swap_utils_bonus.c

FT_PRINTF = libftprintf.a


all: $(NAME)

$(FT_PRINTF):
	make -C ./ft_printf all
	cp ./ft_printf/$(FT_PRINTF) .


$(NAME): $(HEADER) $(FT_PRINTF) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(FT_PRINTF) -o $(NAME)

bonus: $(BONUS_HEADER) $(FT_PRINTF) $(BONUS_SRCS)
	$(CC) $(CFLAGS) $(BONUS_SRCS) $(FT_PRINTF) -o $(BONUS)

clean:
	make -C ./ft_printf clean
	rm -f $(NAME)
	rm -f $(BONUS)

fclean: clean
	make -C ./ft_printf fclean
	rm -f $(NAME) $(FT_PRINTF)
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re
