/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:52 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 20:39:03 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"

void	put_to_server(int header_fd, int download_fd, char *name)
{
	int			n;
	int			fd;
	char		*returning;
	struct stat	sb;

	n = 0;
	if ((fd = open(name, O_RDWR)) == -1)
	{
		printf("cant open that\n");
		send_header(header_fd, get, 0, NULL);
		return ;
	}
	if (fstat(fd, &sb) == -1)
		err_n_die("file_size");
	printf("sending: %lld bytes\n", sb.st_size);
	returning = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE,
	MAP_PRIVATE, fd, 0);
	send_header(header_fd, put, sb.st_size, name);
	send_message(download_fd, returning, sb.st_size);
	munmap(returning, sb.st_size);
	close(fd);
}
