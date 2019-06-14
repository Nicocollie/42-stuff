/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:21:59 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 18:13:18 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/s_header.h"

int		get_port(int socket)
{
	struct sockaddr_in	server_addr;
	unsigned int		temp;

	temp = sizeof(server_addr);
	ft_bzero(&server_addr, sizeof(server_addr));
	getsockname(socket, (struct sockaddr *)&server_addr, &temp);
	return (ntohs(server_addr.sin_port));
}

int		listen_for_second_socket(int back_fd)
{
	int download_fd;

	while ((download_fd = accept(back_fd, (SA *)NULL, NULL)))
		return (download_fd);
	return (0);
}

void	handle_new_connection(int conn_fd)
{
	int download_fd;
	int	data_fd;

	data_fd = set_socket(0);
	send_header(conn_fd, get_port(data_fd), 0, 0);
	if (!(download_fd = listen_for_second_socket(data_fd)))
	{
		close(conn_fd);
		close(data_fd);
		err_n_die("didn't get second connection\n");
	}
	while (1)
		process_incoming(conn_fd, download_fd);
}

void	wait_for_connections(int socket)
{
	int					conn_fd;
	int					pid;
	struct sockaddr_in	client_addr;
	unsigned int		len;

	len = sizeof(client_addr);
	while ((conn_fd = accept(socket, (SA *)NULL, NULL)))
	{
		bzero(&client_addr, sizeof(client_addr));
		getpeername(conn_fd, (SA *)&client_addr, &len);
		printf("%sNEW CONNECTION: %s%s\n", YELLOW, RESET,
		inet_ntoa(client_addr.sin_addr));
		printf("%sport: %s%d\n", YELLOW, RESET, client_addr.sin_port);
		if ((pid = fork()) == 0)
			handle_new_connection(conn_fd);
		else if (pid < 0)
			printf("Forking failed\n");
	}
}
