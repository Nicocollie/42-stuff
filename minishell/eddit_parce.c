/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eddit_parce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:54:48 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/01 19:58:35 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	for_each_element_char_ss(char **list, char *(*f)(char *line))
// {
// 	int num;
// 	int n;

// 	n = -1;
// 	num = double_char_ptr_size(list);
// 	while (++n < num)
// 		f(list[n]);
// }

void	ft_remove_nul(char **argv)
{
	int n;

	n = -1;
	while(argv[++n])
		if (!(ft_strcmp(argv[n], "")))
			shift(argv + n--);
}

void	replace_argvs(char **argv)
{
	int n;

	n = -1;
	if (argv)
	{
		while (argv[++n])
			argv[n] = replace_string(argv[n]);
		ft_remove_nul(argv);
	}
}

char	*replace_string(char *line)
{
	char *ptr;
	char *name;
	char *data;

	if ((ptr = ft_strchr(line, '$')))
	{
		name = get_name(ptr);
		if (!(data = ft_getenv_value(name)))
			data = "";
		ptr = name;
		name = ft_strjoin("$", name);
		ft_strdel(&ptr);
		ptr = line;
		line = ft_replace_word(line, name, data);
		ft_strdel(&ptr);
		ft_strdel(&name);
		if (ft_strchr(line, '$'))
			line = replace_string(line);
	}
	if (*line == '~' && (*(line + 1) == '/' || *(line + 1) == '\0'))
	{
		ptr = line;
		line = ft_replace_word(line, "~", ft_getenv_value("HOME"));
		ft_strdel(&ptr);
	}
	return (line);
}


/*
 * get's the name af of the thing, then returns the thing to be used for replace
 * if it's a good one it returns data else ""
 * */

char	*get_name(char *ptr)
{
	int n;
	char *temp;

	n = 1;
	while (ptr[n] && (ft_isalnum(ptr[n]) || (ptr[n] == '_')))
		n++;
	temp = ft_strndup(ptr + 1, --n);
	return (temp);
}

char	*manage_til(char *ptr)
{
	return (ptr);	
}
