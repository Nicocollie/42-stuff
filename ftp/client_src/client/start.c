/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:34 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 18:31:00 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"

static int		make_n_connect_socket(char *server_ip, char *port)
{
	struct sockaddr_in	server_addr;
	int					socket_fd;

	if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_n_die("Socket\n");
	ft_bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(ft_atoi(port));
	server_addr.sin_addr.s_addr = inet_addr(server_ip);
	if (connect(socket_fd, (SA *)&server_addr, sizeof(server_addr)) < 0)
		err_n_die("Connect failed\n");
	return (socket_fd);
}

static void		check_arguments(int argc, char **argv, int *port1, int *port2)
{
	if (argc != 3)
		err_n_die("Usage: %s <server ip> <port 1>\n", argv[0]);
	if (!ft_strcmp(argv[1], "localhost"))
	{
		argv[1] = malloc(sizeof(char) * ft_strlen("127.0.0.1"));
		ft_strcpy(argv[1], "127.0.0.1");
	}
	*port1 = ft_atoi(argv[2]);
	if (!(*port1 > 0 && *port1 <= 65535))
		err_n_die("invalid port\n");
}

int				main(int argc, char **argv)
{
	int					header_fd;
	int					download_fd;
	int					main_port;
	int					back_port;
	struct s_header		header;

	check_arguments(argc, argv, &main_port, &back_port);
	tutorial();
	header_fd = make_n_connect_socket(argv[1], argv[2]);
	header = get_header(header_fd);
	download_fd = make_n_connect_socket(argv[1], ft_itoa(header.command));
	communicate_w_server(header_fd, download_fd);
}
