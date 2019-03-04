CC = cc
FLAGS = -g -I /minilibx_macos/ -o ft_fdf
SRC = fdf.c file_reader.c rotate.c convert.c
LIB = -lft -I libft -L libft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
OBJECTS = fdf.o file_reader.o rotate.o convert.o

all:
	@make -C minilibx_macos/
	@make -C libft/
	@$(CC) $(FLAGS) $(SRC) $(LIB)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	@make -C libft/ fclean

re: fclean all
