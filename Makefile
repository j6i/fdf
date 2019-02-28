CC = cc
FLAGS = -I /minilibx_macos/ -o ft_fdf
SRC = fdf.c file_reader.c
LIB = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -lft -I libft -L libft
OBJECTS = fdf.o file_reader.o

all:
	@make -C libft/
	@$(CC) $(FLAGS) $(SRC) $(LIB)

clean:
	@make -C libft/ clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C libft/ fclean

re: fclean all
