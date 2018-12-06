/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 22:22:45 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/30 18:43:14 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <dirent.h>

/*
**	cycle each directory in path -- error checking for PATH?
*/

char	*look_function_location(char *name)
{
	char	**list;
	int		n;
	int		num;

	num = 0;
	n = -1;
	list = ft_strsplit(ft_getenv_value("PATH"), ':');
	while (list[++n])
	{
		num = check_dir(list[n], name);
		if (num)
			return (final_exec_path(list[n], name));
	}
	ft_free(list, NULL);
	return (NULL);
}

/*
**	cycle each file in the curent directory for the  exe
*/

int		check_dir(char *dir_name, char *name)
{
	DIR				*dir;
	struct dirent	*current;

	if (!(dir = opendir(dir_name)))
	{
		b_printf("bad bad");
		return (0);
	}
	while ((current = readdir(dir)))
	{
		if (!ft_strcmp(current->d_name, name))
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

/*
** returns the path that exe was found in, Plus the exe
** 		path/exe
*/

char	*final_exec_path(char *path, char *name)
{
	char *temp;
	
	if (!path || !name)
		return (NULL);
	temp = ft_strjoin(ft_addchar(path, '/'), name);
	return (temp);
}
