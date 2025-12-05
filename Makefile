
CC = cc

CFLAG = -Wall -Werror -Wextra

NAME = push_swap

HEADER = push_swap.h

SRCS = push_swap.c

FT_PRINTF = libftprintf.a


all: $(NAME)

$(FT_PRINTF):
	make -C ./ft_printf all
	cp ./ft_printf/$(FT_PRINTF) .


$(NAME): $(HEADER) $(FT_PRINTF) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(FT_PRINTF) -o $(NAME)
