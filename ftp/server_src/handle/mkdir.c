/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:37:22 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 18:15:19 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/common_header.h"
#include "../../headers/s_header.h"

void	handle_mkdir(int conn_fd, char *name)
{
	mkdir(name, 0777);
	send_header(conn_fd, mkdirs, 0, 0);
}
