NAME = libftprintf.a
CC = cc -Wall -Wextra -Werror
SOURCE = ma/ft_printf.c ma/print_str.c ma/print_dec.c ma/print_hex.c\
		 ma/ft_itoa.c ma/ft_utoa.c

#BSOURCE = 

OBJ = $(SOURCE:.c=.o)

#BOBJ = $(BSOURCE:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ma/ft_printf.h
	$(CC) -c $< -o $@

#bonus: $(BOBJ)
#	ar rcs $(NAME) $(BOBJ)

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean