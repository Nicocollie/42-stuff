/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_header.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:08:07 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 18:18:30 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_HEADER_H
# define S_HEADER_H

struct s_home	home;
void			handle_mkdir(int conn_fd, char *name);
int				set_socket(int port);
enum			e_file_type{other, file, dir};
void			wait_for_connections(int socket);
void			handle_put(int header_fd, int download_fd,
struct s_header header);
void			handle_cd(int conn_fd, int download_fd, char *name);
void			handle_get(int conn_fd, int download_fd, char *name);
void			handle_quit(int conn_fd, int download_fd);
void			handle_pwd(int conn_fd, int download_fd);
void			handle_ls(int conn_fd, int download_fd);
void			temp_responce_function(int conn_fd, unsigned int length);

#endif
