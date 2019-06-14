/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:22:45 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/07 23:59:09 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define BLOCK struct s_block *

extern struct s_container container;

void						*is_ptr_within_this_block(BLOCK current, void *ptr)
{
	int block_size;
	int pages;
	int difference;

	difference = (unsigned char *)ptr - (unsigned char *)current;
	pages = current->header.pages;
	block_size = pages * PAGESIZE;
	if (block_size && (difference >= 0 && difference <= block_size))
		return (current);
	return (NULL);
}

struct s_two_ptr_returns	search_chain_of_blocks(BLOCK current, void *ptr)
{
	struct s_two_ptr_returns return_val;

	return_val = (struct s_two_ptr_returns){NULL, NULL};
	while (current)
	{
		if ((return_val.location = is_ptr_within_this_block(current, ptr)))
			return (return_val);
		return_val.last = current;
		current = current->header.next;
	}
	return (return_val);
}

struct s_two_ptr_returns	locate_ptr_in_gobal(void *ptr)
{
	struct s_block				*current;
	struct s_two_ptr_returns	return_val;

	return_val = (struct s_two_ptr_returns){NULL, NULL};
	return_val = search_chain_of_blocks(container.tiny, ptr);
	if (return_val.location)
		return (return_val);
	return_val = search_chain_of_blocks(container.small, ptr);
	if (return_val.location)
		return (return_val);
	return_val = search_chain_of_blocks(container.large, ptr);
	if (return_val.location)
		return (return_val);
	return (return_val);
}

int							get_index_position(struct s_block *ptr,
													void *removing)
{
	int difference;

	difference = (unsigned char *)removing - (unsigned char *)ptr;
	difference -= HEADER_SIZE;
	return ((difference / ptr->header.size_of_chunks));
}
