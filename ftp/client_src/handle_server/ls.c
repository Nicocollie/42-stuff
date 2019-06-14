/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:50 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 20:40:35 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"

void	handle_ls(int socket_fd, int length)
{
	printf("%s%s--%sFile\t%sDIR%s--\n", GO_UP, MOVE_RIGHT(16),
	GREEN, BLUE, RESET);
	simple_print(socket_fd, length);
}
