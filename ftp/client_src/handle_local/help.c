/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:41 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 20:36:23 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/common_header.h"
#include "../headers/c_header.h"

void	tutorial(void)
{
	printf("%s*---------------------------------------*%s\n", RED, RESET);
	printf("%s*%s\tComands available:\t\t%s*\n", RED, YELLOW, RED);
	printf("*%s  ls\tpwd\tquit\tcd\t\t%s*\n", YELLOW, RED);
	printf("*%s  get\tput\tlls\thelp\t\t%s*\n%s", YELLOW, RED, RESET);
	printf("%s*---------------------------------------*%s\n", RED, RESET);
}

void	handle_local_help(void)
{
	printf("-----------------------------------------------\n");
	printf("ls:\tls server's dir\n");
	printf("lls:\tls your dir\n");
	printf("pwd:\tpwd server's dir\n");
	printf("quit:\tquit connection\n");
	printf("cd:\tcd to a different location on the server\n");
	printf("get:\tdownload file from server\n");
	printf("put:\tupload file to server\n");
	printf("help:\tlol\n");
	printf("-----------------------------------------------\n");
}
