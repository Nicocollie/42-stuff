/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 01:01:30 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/26 18:30:16 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/common_header.h"
#include "../../headers/c_header.h"
#define PROMPT printf("%sFTP%s:", YELLOW, RESET); fflush(stdout)
#define EQUAL(x) !ft_strcmp(argv[0], (x))

int		validate_input(char **argv)
{
	int argc;

	argc = double_char_ptr_size(argv);
	lower_string(argv);
	if (argc == 0)
		return (invalid);
	if ((EQUAL("ls") || EQUAL("pwd") || EQUAL("quit")) && argc == 1)
		return (server_command);
	if (EQUAL("cd") && (argc == 2 || argc == 1))
		return (server_command);
	if ((EQUAL("put") || EQUAL("get") || EQUAL("mkdir")) && argc == 2)
		return (server_command);
	if ((EQUAL("lls") || EQUAL("lpwd")) && argc == 1)
		return (local_command);
	if (EQUAL("lcd") && (argc == 2 || argc == 1))
		return (local_command);
	if (EQUAL("help") && argc == 1)
		return (local_command);
	printf("wrong comand or number of arguments\n");
	return (invalid);
}

char	**get_user_input(void)
{
	char	*line;
	char	**argv;
	int		value;

	while (1)
	{
		PROMPT;
		get_next_line(0, &line);
		if (!line)
			continue ;
		argv = ft_strsplit(line, ' ');
		free(line);
		if ((value = validate_input(argv)) == server_command)
			return (argv);
		else if (value == local_command)
			handle_local(argv);
		free_usr_input(argv);
	}
	return (NULL);
}

void	communicate_w_server(int header_fd, int download_fd)
{
	char	**user_input;

	while (1)
	{
		user_input = get_user_input();
		handle_server(header_fd, download_fd, user_input);
		process_incoming(header_fd, download_fd);
	}
}
