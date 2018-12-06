/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:54:09 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/02 20:43:10 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "structs.h"

void	prompt()
{
	static int index;
	s_color *list;

	list = set_color();
	b_printf("%s>>>\033[0m", list[index++].color);
	if (index > 3)
		index = 0;
}