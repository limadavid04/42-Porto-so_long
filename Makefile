# # -*- Makefile -*-                                                            
CC = cc
CFLAGS =-Wall -Wextra -Werror
LIBFT = ./libft/libft.a
NAME = so_long
FILES = parser

all: $(NAME)

$(NAME): $(FILES:=.o)
	$(MAKE)  -C ./libft
	$(CC) $(CFLAGS) $(FILES:=.o) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(FILES:=.o)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean $(NAME)

