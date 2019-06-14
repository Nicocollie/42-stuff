/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:47 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 21:14:30 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/common_header.h"
#include "../headers/c_header.h"

void	handle_get(int socket_fd, struct s_header header)
{
	int		fd;
	char	*location;

	if (header.length == 0)
	{
		printf("file doesn't exist or it's a dir\n");
		return ;
	}
	if ((fd = open(header.name, O_RDWR | O_CREAT, 0666)) == -1)
	{
		printf("You alread have a file of this name\n");
		return ;
	}
	read_n_put_in_file(fd, socket_fd, header.length);
	close(fd);
	location = getcwd(NULL, 0);
	printf("file downloaded:\n%s\n", location);
	free(location);
}
