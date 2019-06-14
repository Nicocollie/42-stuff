/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:30:04 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/23 23:39:21 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/common_header.h"
#include "../../headers/s_header.h"

void	handle_pwd(int command_fd, int data_fd)
{
	int		n;
	char	*responce;
	int		size;

	n = 0;
	responce = getcwd(NULL, 0);
	printf("%s\n", responce);
	printf("%s\n", responce + home.size);
	size = ((strlen(responce)) - home.size);
	send_header(command_fd, pwd, size, NULL);
	send_message(data_fd, (responce + home.size), size);
	free(responce);
}
