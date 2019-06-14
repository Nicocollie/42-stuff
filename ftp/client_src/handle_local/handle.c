/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:39 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 17:40:06 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"

void	handle_local(char **argv)
{
	if (!ft_strcmp(argv[0], "lls"))
		handle_local_ls();
	else if (!ft_strcmp(argv[0], "help"))
		handle_local_help();
	else if (!ft_strcmp(argv[0], "lpwd"))
		handle_local_pwd();
	else if (!ft_strcmp(argv[0], "lcd"))
		handle_local_cd(argv[1]);
}
