/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 00:14:28 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 21:41:32 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/common_header.h"
#include "../../headers/s_header.h"

static void		check_location(void)
{
	char	*current;

	current = getcwd(NULL, 0);
	if (ft_strncmp(current, home.home, home.size))
	{
		if (chdir(home.home) == -1)
			printf("NOT A DIR");
		printf("gone too far");
	}
	free(current);
}

static void		special_free(int num, ...)
{
	void	*value;
	va_list	args;

	va_start(args, num);
	while (num--)
	{
		value = (void *)(va_arg(args, long));
		free(value);
	}
	va_end(args);
}

char			*check_slash(int *special, char *name)
{
	char	*good_name;

	*special = 0;
	if (name[0] == '/')
		good_name = name;
	else
	{
		good_name = ft_strjoin("/", name);
		*special = 1;
	}
	return (good_name);
}

static int		change_dir(int conn_fd, int download_fd, char *name)
{
	char	*pwd;
	char	*good_name;
	int		special;
	char	*current;

	good_name = check_slash(&special, name);
	current = getcwd(NULL, 0);
	pwd = ft_strjoin(current, good_name);
	printf("%s\n", pwd);
	if (chdir(pwd) == -1)
	{
		printf("NOT A DIR\n");
		send_header(conn_fd, cd, 26, NULL);
		send_message(download_fd, "No such file or directory", 26);
		if (special)
			special_free(3, good_name, current, pwd);
		else
			special_free(2, current, pwd);
		return (1);
	}
	if (special)
		special_free(3, good_name, current, pwd);
	else
		special_free(2, current, pwd);
	return (0);
}

void			handle_cd(int conn_fd, int download_fd, char *name)
{
	if (!strlen(name))
	{
		if (chdir(home.home) == -1)
			err_n_die("chdir at cd - can't go back home\n");
	}
	else
	{
		if (change_dir(conn_fd, download_fd, name))
			return ;
		check_location();
	}
	send_header(conn_fd, cd, 0, NULL);
}
