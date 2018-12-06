/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:54:18 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/04 17:17:24 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "structs.h"

s_built_in	*set_list(void)
{
	s_built_in	*list;	//malloc then return??

	list = (s_built_in[])
	{
		{"echo", ft_echo},
		{"exit", ft_exit},
		{"env", env},
		{"cd", ft_cd},
		{"setenv", ft_setenv},
		{"unsetenv", ft_unsetenv},
		{NULL, NULL},
	};
	return (list);
}

s_color		*set_color(void)
{
	s_color *list;

	list = (s_color[])
	{
		{"red", "\033[31m"},
		{"green", "\033[32m"},
		{"yellow", "\033[33m"},
		{"blue", "\033[34m"},
		{NULL, NULL},
	};
	return (list);
}
