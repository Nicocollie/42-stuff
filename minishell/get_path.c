/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:46:35 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/30 18:50:57 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * returns a pointer to the start of the given environ variable
 * if it doesn't exsist it returns NULL
 */
char    *ft_getenv_value(char *name)
{
    extern  char    **g_environ;
    int n;
    int num;

    n = -1;
    num = 0;
    while (g_environ[++n])
        if ((num = first_word(g_environ[n],name)))
            return ((g_environ[n] + num));
    return (g_environ[n]);
}
//question this one now/......
char    **ft_getenv_start(char *name)
{
    extern  char    **g_environ;
    int n;
    int num;

    n = -1;
    num = 0;
    while (g_environ[++n])
        if ((num = first_word(g_environ[n],name)))
            return ((&g_environ[n]));
    return (NULL);
}
/*
 *  will find if word exist at the
 *  start of the given word, if yes return how far in it was
 */
int     first_word(char *s1, char *s2)
{
    int n;

    n = 0;
	if (!s1 || !s2)
		return (0);
    while (s1[n] == s2[n] && s2[n] && s1[n])
        n++;
    if (!(s2[n]) && s1[n] == '=')
        return (n + 1);
    return (0);
}
