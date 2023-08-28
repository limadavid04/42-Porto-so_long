# # -*- Makefile -*-
# NAME = ft_printf
NAME= libftprintf.a
CC= cc
CFLAGS = -g -Wall -Wextra -Werror
FILES = ft_printf ft_char_format ft_string_format\
ft_pointer_format ft_decimal_format ft_printf_utils\
ft_unsigned_format ft_hexadecimal_format main
all: $(NAME)

# $(NAME): $(FILES:=.o)
# 	ar -rc $(NAME) $(FILES:=.o)
$(NAME) : $(FILES:=.o)
	$(CC) $(CFLAGS) $(FILES:=.o)
clean:
	rm -f $(FILES:=.o)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
