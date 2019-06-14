/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:10:06 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 18:17:49 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HEADER_H
# define COMMON_HEADER_H
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <strings.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <dirent.h>
# include "libft.h"
# include "structs.h"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define BLACK "\033[0;90m"
# define RESET   "\x1b[0m"
# define GO_UP   "\033[F"
# define MOVE_RIGHT(x)   "\033["#x"C"
# define MAXLINE 4096
# define SA struct sockaddr

enum	e_command{ls, cd, get, put, pwd, quit, mkdirs, connection, test};

struct s_header get_header(int socket_fd);
void			read_n_put_in_file(int file, int data_fd, int length);
void			send_message(int socket_fd, char *message, int size);
void			err_n_die(const char *fmt, ...);
void			process_incoming(int header_fd, int download_fd);
void			send_header(int socket_fd, unsigned int command,
unsigned int size, char *name);
void			handle(int header_fd, int download_fd, struct s_header header);
void			debug(const char *fmt, ...);
void			simple_print(int socket_fd, unsigned int length);

#endif
