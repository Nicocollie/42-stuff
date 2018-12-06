/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:32:48 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/02 20:12:00 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include "libft.h"
#include <stdlib.h>
#include "structs.h"

char	**g_environ;

void	main_loop(void);
char	*read_input(void);
void	set_environ();
void	handler(int num);

void	ft_echo(char **argv);
void	ft_exit(char **argv);
void	env(char **argv);
void	run(char **argv);

int		real_function(char **argv);

char	*look_function_location(char *name);
int		check_dir(char *dir_name, char *name);
char	*final_exec_path(char *path, char *name);

s_built_in	*set_list(void);
s_color		*set_color(void);

char	*ft_getenv_value(char *name);
char    **ft_getenv_start(char *name);
int		first_word(char *s1, char *s2);

void	ft_free(char **argv, char *line);

void	for_each_element_char_ss(char **list, char *(*f)(char *line));
void	ft_remove_nul(char **argv);
void	replace_argvs(char **argv);
char	*replace_string(char *line);
char	*get_name(char *ptr);
char	*manage_til(char *ptr);		//bad ^

void	ft_setenv(char **argv);
void	ft_unsetenv(char **argv);
void	ft_cd(char **argv);

char	*move_to_next_word(char *str);
char	*move_to_char_after_end_of_word(char *str);
int		word_length(char *str);
int		count_words(char *str);
char	**parse_words(char *str);


char	*set_string(char *name, char *value);
void	replace_envrion_value(char *name, char *value);
void	add_envrion_value(char *name, char *value);
void	shift(char **argv);
void	set_nul(char **argv);

void	prompt(void);
// char	*get_path(char *newa);
// void	ft_ft_getenv(char **argv);

#endif
