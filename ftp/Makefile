CLIENT = client 
SERVER = server 
TESTING = a.out
EXTRA = a.out.dSYM ft_ls.dSYM
C_C = client_src/client/
C_H = client_src/handle_server/
C_H_L = client_src/handle_local/
FILES_C = $(C_C)start.c $(C_C)input.c $(C_C)extra.c $(C_H)get.c $(C_H)handle.c $(C_H)ls.c $(C_H)quit.c $(C_H)put.c $(C_H_L)handle.c $(C_H_L)help.c $(C_H_L)ls.c $(C_H_L)server.c $(C_H_L)pwd.c $(C_H_L)cd.c
S_H = server_src/handle/
S_S = server_src/server/
FILES_S = $(S_S)start.c $(S_S)connection.c $(S_H)handle.c $(S_H)quit.c $(S_H)pwd.c $(S_H)put.c $(S_H)get.c $(S_H)ls.c $(S_H)cd.c $(S_H)mkdir.c
COMMON = common_src/common.c common_src/common_2.c
OBJECTS = $(FILES:.c=.o)
FLAGS = -Wall -Werror -Wextra
BIN = $(CLIENT) $(SERVER)
LIB_HEADER = -I ./libft/includes
FTP_HEADERS = -I ./headers
HEADERS = $(LIB_HEADER) $(FTP_HEADERS)
LIBS = -L ./libft -lft 
FLAGS = -Wall -Werror -Wextra -fsanitize=address

all: $(BIN)

$(CLIENT): lib $(FILES_C)
	gcc  $(HEADERS) $(FILES_C) $(COMMON) $(LIBS) -o $(CLIENT) 
$(SERVER): lib $(FILES_S)
	gcc  $(HEADERS) $(FILES_S)  $(COMMON) $(LIBS) -o $(SERVER) 
g:
	gcc  -I libft/includes -L libft/ $(FILES) -g -lft -o $(NAME)
gg:
	gcc  -I libft/includes -L libft/ $(FILES) -g -fsanitize=address -lft -o $(NAME)
val: g
	valgrind --leak-check=full -v ./minishell
clean:
	rm -f $(BIN)
	rm -f $(TESTING)
	rm -fr $(EXTRA)
fclean: clean
	make -C libft/ fclean
re: fclean all
lib:
	make -C libft/ 
