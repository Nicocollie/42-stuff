/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:43:55 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/02 16:38:24 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h> //
#include <signal.h>

int	real_function(char **argv)
{
	pid_t pid;
	int status;
	char	*path;

	pid = fork();
	if (pid < 0)
	{
		b_printf("fork failed!");
		exit(0);// exit correct? //terminates entire process
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		execve(argv[0], argv, g_environ);
		if (!(path = look_function_location(argv[0])))
		{
			b_printf("zsh: command not found: %s\n", argv[0]);
			exit(0);
			return (1);
		}
		if (execve(path, argv, g_environ) == -1)
		{
			b_printf("execve has failed");
			exit(1);	//terminates just the child process
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (1);
}

































//int lsh_launch(char **args)
//{
//
//	pid_t pid, wpid;
//	int status;
//
//	pid = fork();
//	if (pid == 0) {
//
//		//Child process
//		if (execvp(args[0], args) == -1) {
//
//			perror("lsh");
//		}
//		exit(EXIT_FAILURE);
//	} else if (pid < 0) {
//
//		// Error forking
//		perror("lsh");
//	} else {
//
//		// Parent process
//		do {
//
//			wpid = waitpid(pid, &status, WUNTRACED);
//		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
//	}
//
//	return 1;
//}
//





