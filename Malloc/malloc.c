/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:55:16 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/06 21:10:08 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

extern struct s_container container;

void	*search_block(struct s_block *ptr, int blocks)
{
	int				n;
	int				count;
	unsigned char	*return_val;

	count = 0;
	n = -1;
	return_val = NULL;
	while (++n < NUMBER_OF_CHUNKS)
	{
		if (INDEX(n).free == 0)
		{
			count++;
			if (count == blocks)
			{
				n = n - count + 1;
				set_allocated(ptr, n, blocks);
				return_val = (unsigned char *)ptr;
				return (return_val + HEADER_SIZE +
				(n * ptr->header.size_of_chunks));
			}
		}
		else
			count = 0;
	}
	return (NULL);
}

void	*tiny_or_small_malloc(size_t size)
{
	int				blocks;
	struct s_block	*tmp;
	void			*addr;
	int				type;

	type = (size < SMALL_SIZE) ? tiny : small;
	addr = NULL;
	blocks = ((size - 1) / ((type == tiny) ? TINY_SIZE : SMALL_SIZE)) + 1;
	(type == tiny) ? (!(container.tiny)) && create_block(tiny, size) :
	(!(container.small)) && create_block(small, size);
	tmp = (type == tiny) ? container.tiny : container.small;
	while (tmp)
	{
		if ((addr = search_block(tmp, blocks)))
			return (addr);
		tmp = tmp->header.next;
	}
	if (!addr)
		addr = search_block(create_block((type == tiny) ? tiny :
		small, size), blocks);
	return (addr);
}

void	*large_malloc(size_t size)
{
	int				pages;
	struct s_block	*tmp;
	unsigned char	*return_val;

	pages = (size - 1) / PAGESIZE + 1;
	tmp = create_block(pages, size);
	return_val = (unsigned char *)tmp;
	return (return_val + HEADER_SIZE);
}

void	*malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	if (size <= SMALL_LIMIT)
		return (tiny_or_small_malloc(size));
	else
		return (large_malloc(size));
	return (NULL);
}
