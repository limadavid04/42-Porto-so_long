# # -*- Makefile -*-                                                            
CC = cc
CFLAGS =-Wall -Wextra -Werror -g #-fsanitize=address
LIBFT = ./libft/libft.a
NAME = so_long
FILES = check_map_size check_map_path utils game_main event_handler
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
all: $(NAME)

$(NAME): $(FILES:=.o)
	$(MAKE)  -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(FILES:=.o) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(FILES:=.o)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean $(NAME)

