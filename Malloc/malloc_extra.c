/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:03:34 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/06 21:10:08 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <sys/mman.h>
#include "libft.h"

extern struct s_container container;

void	check_page(void *ptr)
{
	if (ptr == MAP_FAILED)
		b_printf("Mmap failed");
}

void	*get_global_block(size_t size)
{
	if (size < SMALL_SIZE)
		return (container.tiny);
	else if (size < SMALL_LIMIT)
		return (container.small);
	else
		return (container.large);
}

void	*init_global(size_t size, void *ptr)
{
	if (size < SMALL_SIZE)
		return (container.tiny = ptr);
	else if (size < SMALL_LIMIT)
		return (container.small = ptr);
	else
		return (container.large = ptr);
}

int		get_size_of_chunks(size_t size)
{
	if (size < SMALL_SIZE)
		return (TINY_SIZE);
	else if (size < SMALL_LIMIT)
		return (SMALL_SIZE);
	else
		return (size);
}

void	*create_block(int pages, size_t size)
{
	struct s_block *tmp;

	tmp = get_global_block(size);
	while (tmp && tmp->header.next)
		tmp = tmp->header.next;
	if (!tmp)
		tmp = init_global(size, MMAP);
	else
	{
		tmp->header.next = MMAP;
		tmp = tmp->header.next;
	}
	check_page(tmp);
	tmp->header.size_of_chunks = get_size_of_chunks(size);
	tmp->header.pages = pages;
	return (tmp);
}
