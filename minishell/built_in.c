/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:07:28 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/01 18:51:02 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_setenv(char **argv)
{
	char *temp;
	int size;

	size = double_char_ptr_size(argv);
	if (argv[1] && (size < 4))
	{
		if (!(temp = ft_getenv_value(argv[1])))
			add_envrion_value(argv[1], argv[2]);
		else if (argv[2])
			replace_envrion_value(argv[1], argv[2]);
		else
			temp[first_word(temp, argv[1])] = '\0';
	}
	if (size >= 4)
		b_printf("setenv: Too many arguments.\n");
	if (size == 1)
		env(argv);
}

void ft_unsetenv(char **argv)
{
	int n;

	set_nul(argv);
	n = 0;
	while (g_environ[++n])
		if (!(ft_strcmp(g_environ[n], "")))
			shift(g_environ + n--);
}

void ft_cd(char **argv)
{
	char **temp;
	char *pwd;
	pwd = getcwd(NULL, 0);
	if (!argv[1])
	{
		if (chdir(ft_getenv_value("HOME")) < 0)
			b_printf("you broke cd");
		temp = (char*[]){"cd", "OLDPWD", pwd, NULL};
		ft_strdel(&pwd);
		ft_setenv(temp);
		temp = (char*[]){"cd", "PWD", ft_getenv_value("HOME"), NULL};
		ft_setenv(temp);
	}
	else if (chdir(argv[1]) < 0)
	{
		b_printf("cd: no such file or directory: %s\n", argv[1]);
		ft_strdel(&pwd);
	}
	else
	{
		temp = (char*[]){"cd", "OLDPWD", pwd, NULL};
		ft_strdel(&pwd);
		ft_setenv(temp);
		pwd = getcwd(NULL, 0);
		temp = (char*[]){"cd", "PWD", pwd, NULL};
		ft_setenv(temp);
		ft_strdel(&pwd);
	}
}