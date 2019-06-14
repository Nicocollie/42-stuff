/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:48 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 18:32:57 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"

void	handle(int socket_fd, int download_fd, struct s_header header)
{
	int command;

	command = header.command;
	if (command == test || command == pwd || command == cd ||
	command == put || command == mkdirs)
		simple_print(download_fd, header.length);
	else if (command == ls)
		handle_ls(download_fd, header.length);
	else if (command == quit)
		handle_quit(socket_fd, download_fd);
	else if (command == get)
		handle_get(download_fd, header);
}
