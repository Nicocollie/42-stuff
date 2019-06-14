/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:43 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 20:35:40 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"
#include <sys/wait.h>

void	handle_local_ls(void)
{
	int pid;

	if ((pid = fork()) == 0)
		execl("/bin/ls", "hey", "-lG", NULL);
	else if (pid < 0)
		printf("error with the fork/ls\n");
	wait4(pid, 0, 0, 0);
}
