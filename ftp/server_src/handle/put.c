/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:37:22 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 21:28:49 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/common_header.h"
#include "../../headers/s_header.h"

char	*getname(char *name_in_header)
{
	char	*name;

	name = ft_strrchr(name_in_header, '/');
	if (name)
		return (name + 1);
	return (name_in_header);
}

void	handle_put(int command_fd, int data_fd, struct s_header header)
{
	int		fd;

	if (header.length == 0)
	{
		printf("file doesn't exist or it's a dir\n");
		return ;
	}
	if ((fd = open(getname(header.name), O_RDWR | O_CREAT, 0666)) == -1)
	{
		printf("You alread have a file of this name or permition == bad\n");
		send_header(command_fd, put, 0, NULL);
		return ;
	}
	read_n_put_in_file(fd, data_fd, header.length);
	close(fd);
	send_header(command_fd, put, 18, NULL);
	send_message(data_fd, "successfully sent", 18);
}
