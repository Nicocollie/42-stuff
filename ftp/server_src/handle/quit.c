/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:28:42 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/23 23:38:41 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"

void	handle_quit(int command_fd, int data_fd)
{
	int					n;
	struct sockaddr_in	client_addr;
	unsigned int		len;

	n = 0;
	len = sizeof(client_addr);
	bzero(&client_addr, sizeof(client_addr));
	getpeername(command_fd, (SA *)&client_addr, &len);
	printf("%sCONNECTION%s %s %sTERMINATED%s\n", YELLOW, RESET,
	inet_ntoa(client_addr.sin_addr), YELLOW, RESET);
	send_header(command_fd, quit, 0, NULL);
	close(command_fd);
	close(data_fd);
	exit(1);
}
