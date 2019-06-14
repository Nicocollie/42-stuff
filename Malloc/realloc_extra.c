/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:52:17 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/06 21:10:08 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

int		check_if_can_expand(struct s_block *ptr, int index,
								int new_chunks, int old_chunks)
{
	int diference;

	diference = (old_chunks - new_chunks) * -1;
	while (--diference >= 0)
	{
		if (INDEX(index + (old_chunks) + diference).free == allocated)
		{
			b_printf("THIS WONT WORK\n");
			return (0);
		}
	}
	return (1);
}

void	set_allocated(struct s_block *ptr, int n, int chunks)
{
	INDEX(n).units = chunks;
	while (--chunks >= 0)
		INDEX(n + chunks).free = allocated;
}

void	make_allocated_smaller(struct s_block *ptr, int n,
							int new_chunks, int old_chunks)
{
	int chunks;

	INDEX(n).units = new_chunks;
	chunks = old_chunks - new_chunks;
	while (--chunks >= 0)
		INDEX(n + (old_chunks - chunks - 1)).free = 0;
}
