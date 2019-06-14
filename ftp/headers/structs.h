/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:11:24 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/24 21:15:10 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define FILE_NAME_SIZE 100

struct	s_header
{
	unsigned int	command;
	unsigned int	length;
	char			name[FILE_NAME_SIZE];
};

struct	s_home
{
	char	*home;
	int		size;
};

#endif
