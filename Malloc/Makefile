ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME = libft_malloc_$(HOSTTYPE).so
LINK = libft_malloc.so
TESTING = a.out
EXTRA = a.out.dSYM ft_ls.dSYM
FILES = realloc.c realloc_extra.c print_mem.c print_mem_extra.c free.c free_extra.c malloc.c malloc_extra.c
FLAGS = -Wall -Werror -Wextra
OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJECTS) 
	gcc -shared -o $(NAME) $(OBJECTS) -I libft/includes -L libft/ -lft
	ln -sf $(NAME) $(LINK)
test:
	gcc -I ./libft/includes/ -L. -L./libft/ -lft -lft_malloc test.c -g
%.o: %.c
	gcc -c $< -o $@ -fPIC -I libft/includes
clean:
	rm -f $(NAME)
	rm -f $(OBJECTS)
	rm -f $(TESTING)
	rm -fr $(EXTRA)
	rm -fr $(LINK)
fclean: clean
	make -C libft/ fclean
re: fclean all
lib:
	make -C libft/