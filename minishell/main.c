#include <unistd.h>
#include <stdio.h>
#include "header.h"
#include <signal.h>
#include <unistd.h>
/*
**	Main idea:
**
**	loda up data	//init
**	run loop
**	shutdown / clean -- up
*/


void	handler(int num)
{
	(void)num;
	b_printf("\033[4G  \n\033[32m>>>\033[0m");
}	

int		main(void)
{
	signal(SIGINT, handler);
	set_environ();
	main_loop();
	//clean-up
}

/*
** Read: stdin
** Parce: program / args
** Execute: run command
*/

void	main_loop(void)
{
	char	*line;
	char	**argv;
	int		status;
	
	status = 1;
	while (1)
	{
		prompt();
		line = read_input();
		argv = parse_words(line);	//add to take care of quotes
		replace_argvs(argv);		//eddit argvs
		run(argv);	
		ft_free(argv, line);
	}
}

char	*read_input(void)
{
	char *line;

	get_next_line(0, &line);
	return (line);
}

void	set_environ()
{
	extern char **environ;
	int size;
	int n;

	n = -1;
	size = double_char_ptr_size(environ);
	g_environ = malloc(sizeof(char *) * (size + 1));
	while(environ[++n])
		g_environ[n] = ft_strdup(environ[n]);
	g_environ[n] = NULL;
}