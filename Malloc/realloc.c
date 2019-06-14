/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:31:50 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/08 00:06:38 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "header.h"
#include "libft.h"

void	*realloc_bigger_space(struct s_block *ptr, int n, void *updating,
								size_t size)
{
	int old_chunks;
	int new_chunks;

	old_chunks = INDEX(n).units;
	new_chunks = (size - 1) / ptr->header.size_of_chunks + 1;
	if (check_if_can_expand(ptr, n, new_chunks, old_chunks))
	{
		set_allocated(ptr, n, new_chunks);
		return (updating);
	}
	else
	{
		free(updating);
		return (ft_memmove(malloc(size), updating,
		old_chunks * ptr->header.size_of_chunks));
	}
}

void	*realloc_tiny_small(struct s_block *ptr, void *updating, size_t size)
{
	int		n;
	int		new_chunks;
	int		old_chunks;
	void	*check;

	n = get_index_position(ptr, updating);
	new_chunks = (size - 1) / ptr->header.size_of_chunks + 1;
	if (INDEX(n).free == allocated && INDEX(n).units != 0)
	{
		old_chunks = INDEX(n).units;
		if (new_chunks < old_chunks)
		{
			make_allocated_smaller(ptr, n, new_chunks, old_chunks);
			return (updating);
		}
		else
			return (realloc_bigger_space(ptr, n, updating, size));
	}
	else
		b_printf("%sPointer being realloc was not allocated%s\n",
		RED, NO_COLOR);
	return (NULL);
}

void	*large_realloc(struct s_block *ptr, size_t size)
{
	int		pages;
	void	*tmp;
	char	*start;

	pages = (size - 1) / PAGESIZE + 1;
	if (pages == ptr->header.pages)
		return (ptr);
	else if (pages > ptr->header.pages)
	{
		tmp = malloc(size);
		ft_memmove(tmp, start + HEADER_SIZE, ptr->header.size_of_chunks);
		free(ptr);
		return (tmp);
	}
	else
		return (ptr);
	return (NULL);
}

void	*update_allocated_space(void *ptr, size_t size)
{
	struct s_two_ptr_returns locations;

	locations = locate_ptr_in_gobal(ptr);
	if (locations.location)
	{
		if (locations.location->header.size_of_chunks > SMALL_LIMIT)
			return (large_realloc(locations.location, size));
		else
			return (realloc_tiny_small(locations.location, ptr, size));
	}
	else
		b_printf("That pointer isn't even mine bro\n");
	return (NULL);
}

void	*realloc(void *ptr, size_t size)
{
	if (!ptr)
		return (malloc(size));
	else if (!size)
	{
		free(ptr);
		return (malloc(80));
	}
	else
		return (update_allocated_space(ptr, size));
	return (NULL);
}
