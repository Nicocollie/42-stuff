/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:36 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 17:55:31 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"

void	handle_server(int header_fd, int download_fd, char **user_input)
{
	if (!ft_strcmp(user_input[0], "ls"))
		send_header(header_fd, ls, 0, NULL);
	else if (!ft_strcmp(user_input[0], "pwd"))
		send_header(header_fd, pwd, 0, NULL);
	else if (!ft_strcmp(user_input[0], "quit"))
		send_header(header_fd, quit, 0, NULL);
	else if (!ft_strcmp(user_input[0], "cd"))
		send_header(header_fd, cd, 0, user_input[1]);
	else if (!ft_strcmp(user_input[0], "put"))
		put_to_server(header_fd, download_fd, user_input[1]);
	else if (!ft_strcmp(user_input[0], "get"))
		send_header(header_fd, get, 0, user_input[1]);
	else if (!ft_strcmp(user_input[0], "mkdir"))
		send_header(header_fd, mkdirs, 0, user_input[1]);
	else
		send_header(header_fd, test, 0, NULL);
	free_usr_input(user_input);
}
