NAME = libftprintf.a
CC = cc -Wall -Wextra -Werror
SOURCE = printf/ft_printf.c printf/print_str.c printf/print_dec.c printf/print_hex.c\
		 printf/ft_itoa.c printf/ft_utoa.c

OBJ = $(SOURCE:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c printf/ft_printf.h
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean