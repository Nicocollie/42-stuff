/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:38:59 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/30 18:48:48 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*set_string(char *name, char *value)
{
	int		name_size;
	int		value_size;
	char	*new_str;

	name_size = ft_strlen(name);
	value_size = (value) ? ft_strlen(value) : 0;
	new_str = ft_strnew(name_size + value_size + 1); 
	ft_strcpy(new_str, name);
	new_str[name_size] = '=';
	if (value)
		ft_strcpy((new_str + name_size + 1), value);
	return (new_str);
}

void			replace_envrion_value(char *name, char *value)
{

	char	*new_string;
	char	**line;

	new_string = set_string(name, value);	
	line = ft_getenv_start(name);
	ft_strdel(line);
	*line = new_string;
}

void		add_envrion_value(char *name, char *value)
{
	int		size;
	char	**temp;
	int		n;
	char	*new_string;

	size = double_char_ptr_size(g_environ);
	temp = malloc(sizeof(char *) * (size + 2));
	new_string = set_string(name, value);
	n = -1;
	while (g_environ[++n])
		temp[n] = g_environ[n];
	temp[n] = new_string;
	temp[n + 1] = NULL;
	free(g_environ);
	g_environ = NULL;
	g_environ = temp;
}

void		shift(char **argv)
{
	int n = -1;
	while (argv[++n])
		argv[n] =  argv[n + 1];
}

void		set_nul(char **argv)
{
	int		n;
	char	**temp;

	n = 0;
	while (argv[++n])
	{
		if ((temp = ft_getenv_start(argv[n])))
		{
			free(*temp);
			*temp = NULL;
			*temp = "";
		}
	}
}
