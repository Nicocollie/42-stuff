/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:00:41 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/06 21:26:33 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern struct s_container container;

void	print_mem(int a)
{
	struct s_header	*header;
	int				size;
	int				n;
	void			*deleteme;

	n = 0;
	header = (a == 1) ? &container.tiny->header :
	&container.small->header;
	size = header->pages * PAGESIZE;
	print_header(header);
	n += HEADER_SIZE;
	while (n < size)
	{
		print_line((void *)header, n, size);
		n += 16;
	}
}

void	show_alloc_mem(void)
{
	struct s_block *tmp;

	tmp = container.tiny;
	while (tmp)
	{
		print_header(tmp);
		tmp = tmp->header.next;
	}
	tmp = container.small;
	while (tmp)
	{
		print_header(tmp);
		tmp = tmp->header.next;
	}
	tmp = container.large;
	while (tmp)
	{
		print_header_large(tmp);
		tmp = tmp->header.next;
	}
}
