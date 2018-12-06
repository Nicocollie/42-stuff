NAME = wolf3d
FILES = main.c drawLine.c
OBJECTS = $(FILES:.c=.o)

$(NAME): all

all:
	gcc -Wall -Werror -Wextra -L minilibx/all_files -lmlx -I minilibx/all_files -framework OpenGL -framework AppKit $(FILES)
clean:

fclean: clean

re: fclean all
