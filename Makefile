CC=cc
CFLAGS=-Werror -Wextra -Wall -I libft/includes -I minilibx_macos -I includes
LFLAGS=-L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
NAME=fdf
SRC=fdf.c file_reader.c rotate.c convert.c
OBJ=$(SRC:%.c=%.o)

.PHONY: clean fclean all re norm norme debug

VPATH = src obj libft/includes includes

$(NAME): $(OBJ)
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) -o $(NAME) obj/* $(LFLAGS)
	@echo done

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	$(CC) -g $(CFLAGS) -o obj/$@ -c $<

clean:
	@rm -rf obj/
	@make -C libft clean
	@make -C minilibx_macos clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

norm:
	norminette src/. includes/*

norme: norm
