/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:23:56 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 18:10:38 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/s_header.h"

extern struct s_home home;

int		set_socket(int port)
{
	int					optval;
	struct sockaddr_in	server_addr;
	int					socket_fd;
	unsigned int		tmp_sock;

	if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_n_die("socket error.\n");
	optval = 1;
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(socket_fd, (SA *)&server_addr, sizeof(server_addr))) < 0)
		err_n_die("bind error.\n");
	if ((listen(socket_fd, 10)) < 0)
		err_n_die("listen error.\n");
	tmp_sock = sizeof(server_addr);
	getsockname(socket_fd, (SA *)&server_addr, &tmp_sock);
	printf("%sPort:%s%d\n", GREEN, RESET, ntohs(server_addr.sin_port));
	return (socket_fd);
}

int		start_server(int main_port, int back_port)
{
	int		socket;

	printf("%sServer is now listening...%s\n", GREEN, RESET);
	socket = set_socket(main_port);
	return (socket);
}

void	environment(void)
{
	mkdir("FTP", 0777);
	if (chdir("FTP") == -1)
		err_n_die("chdir at start");
	home.home = getcwd(NULL, 0);
	home.size = ft_strlen(home.home) - 3;
}

int		check_arguments(int argc, char **argv, int *port1, int *port2)
{
	if (argc != 2)
		err_n_die("Usage: %s <port 1> <port 2>\n", argv[0]);
	*port1 = ft_atoi(argv[1]);
	if (!(*port1 > 0 && *port1 <= 65535))
		err_n_die("invalid port\n");
	return (0);
}

int		main(int argc, char **argv)
{
	int					command_port;
	int					data_port;

	check_arguments(argc, argv, &command_port, &data_port);
	environment();
	wait_for_connections(start_server(command_port, 0));
}
