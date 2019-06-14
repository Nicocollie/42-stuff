/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 00:27:11 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 00:39:13 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/common_header.h"
#include "../../headers/s_header.h"

static int		get_file_type(char *name)
{
	struct stat sb;

	if (stat(name, &sb) == -1)
		err_n_die("fstat in get_file_type()");
	if (S_ISDIR(sb.st_mode))
		return (dir);
	else if (S_ISREG(sb.st_mode))
		return (file);
	return (other);
}

static char		*add_color(char *tmp, char *color, int length)
{
	int n;

	n = -1;
	while (++n < length)
		tmp[n] = color[n];
	tmp += n;
	return (tmp);
}

static char		*add_word(char *tmp, char *d_name, int length)
{
	int n;

	n = -1;
	while (++n < length)
		tmp[n] = d_name[n];
	tmp[n++] = '\t';
	tmp += n;
	return (tmp);
}

char			*update_string_for_ls(char *name, int len, char *tmp)
{
	int type;

	type = get_file_type(name);
	if (type == dir)
		tmp = add_color(tmp, BLUE, strlen(BLUE));
	else if (type == file)
		tmp = add_color(tmp, GREEN, strlen(GREEN));
	else
		tmp = add_color(tmp, RESET, strlen(RESET));
	tmp = add_word(tmp, name, len);
	return (tmp);
}

void			handle_ls(int conn_fd, int download_fd)
{
	struct dirent	*de;
	DIR				*d;
	char			buff[4096];
	char			*tmp;

	d = opendir(".");
	memset(buff, 0, 4096);
	tmp = buff;
	while ((de = readdir(d)))
	{
		if (de->d_name[0] == '.')
			continue;
		tmp = update_string_for_ls(de->d_name, de->d_namlen, tmp);
	}
	tmp = add_color(tmp, RESET, strlen(RESET));
	closedir(d);
	send_header(conn_fd, ls, strlen(buff), NULL);
	send_message(download_fd, buff, strlen(buff));
}
