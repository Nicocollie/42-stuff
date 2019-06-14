/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:18:25 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/13 22:04:24 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "header.h"
#include <sys/mman.h>
#include "libft.h"

extern struct s_container container;

void	free_tiny_small(struct s_block *ptr, void *removing)
{
	int		n;
	int		tmp;

	n = get_index_position(ptr, removing);
	if (INDEX(n).free == allocated && INDEX(n).units != 0)
	{
		tmp = INDEX(n).units;
		INDEX(n).units = 0;
		while (--tmp >= 0)
			INDEX(n + tmp).free = freed;
	}
	else
		b_printf("%sPointer being freed was not allocated%s\n", RED, NO_COLOR);
}

void	free_large(struct s_two_ptr_returns *locations)
{
	struct s_block	*removing;
	struct s_block	*last;

	removing = locations->location;
	last = locations->last;
	if (last)
		last->header.next = removing->header.next;
	else
		container.large = removing->header.next;
	if ((munmap(removing, removing->header.pages) == -1))
		b_printf("Error with munmap\n");
}

void	free(void *ptr)
{
	struct s_two_ptr_returns locations;

	if (ptr == NULL)
		return ;
	locations = locate_ptr_in_gobal(ptr);
	if (locations.location)
	{
		if (locations.location->header.size_of_chunks > SMALL_LIMIT)
			free_large(&locations);
		else
			free_tiny_small(locations.location, ptr);
	}
	else
		b_printf("%sThat pointer isn't even mine bro\n%s", RED, NO_COLOR);
}
