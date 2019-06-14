/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:33:26 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 18:03:25 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/s_header.h"

void	handle(int conn_fd, int download_fd, struct s_header header)
{
	int command;

	printf("command: %d\nlength: %d\nname: %s\n", header.command,
	header.length, header.name);
	command = header.command;
	if (command == ls)
		handle_ls(conn_fd, download_fd);
	else if (command == pwd)
		handle_pwd(conn_fd, download_fd);
	else if (command == cd)
		handle_cd(conn_fd, download_fd, header.name);
	else if (command == quit)
		handle_quit(conn_fd, download_fd);
	else if (command == get)
		handle_get(conn_fd, download_fd, header.name);
	else if (command == put)
		handle_put(conn_fd, download_fd, header);
	else if (command == mkdirs)
		handle_mkdir(conn_fd, header.name);
	else
		err_n_die("what happended!\n");
}
