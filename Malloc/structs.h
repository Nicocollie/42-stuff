/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 21:04:51 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/06 21:11:28 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct	s_two_ptr_returns
{
	struct s_block	*location;
	struct s_block	*last;
};

struct	s_free_chunck_info
{
	unsigned char free:1;
	unsigned char units:7;
};

struct	s_container
{
	struct s_block *tiny;
	struct s_block *small;
	struct s_block *large;
};

struct	s_header
{
	struct s_block				*next;
	long						size_of_chunks;
	int							pages;
	struct s_free_chunck_info	list[100];
};

struct	s_block
{
	struct s_header header;
};

#endif
