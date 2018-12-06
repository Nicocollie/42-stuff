/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:09:33 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/02 19:58:38 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCTS_H
#define STRUCTS_H

typedef struct	t_built_in
{
	char	*name;
	void	(*function)(char **argv);
}				s_built_in;

typedef struct t_color
{
	char *name;
	char *color;
}				s_color;

#endif
