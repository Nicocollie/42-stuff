/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_header.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:06:02 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 17:39:24 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HEADER_H
# define C_HEADER_H
# include "structs.h"

enum	e_command_client{invalid, server_command, local_command};
void	handle_conneection(struct s_header header);
void	handle_server(int header_fd, int download_fd, char **user_input);
void	lower_string(char **argv);
void	free_usr_input(char **argv);
void	put_to_server(int header_fd, int download_fd, char *name);
void	handle_local_ls(void);
void	handle_local(char **argv);
void	tutorial(void);
void	handle_local_help(void);
void	communicate_w_server(int header_fd, int download_fd);
void	handle_get(int download_fd, struct s_header header);
void	handle_ls(int download_fd, int length);
void	handle_quit(int socket_fd, int download_fd);
void	handle_local_pwd(void);
void	handle_local_cd(char *location);
#endif
