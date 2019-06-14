/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:54 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 01:01:56 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/common_header.h"
#include "../headers/c_header.h"

void	handle_quit(int socket_fd, int download_fd)
{
	close(socket_fd);
	close(download_fd);
	printf("Connection closed...\n");
	exit(1);
}
