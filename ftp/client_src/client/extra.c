/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:32 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 20:08:07 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"

void	free_usr_input(char **argv)
{
	int n;

	n = -1;
	while (argv[++n])
		ft_strdel(&argv[n]);
}

void	lower_string(char **argv)
{
	int n;

	n = -1;
	while (argv[0] && argv[0][++n])
		argv[0][n] = ft_tolower(argv[0][n]);
}
