/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:45:01 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/06 21:09:37 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "header.h"
#include "libft.h"
#define SPACE_LEFT pages * PAGESIZE - size

char	*g_base = "0123456789abcdef";

void	pc(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	pc(g_base[c / 16]);
	pc(g_base[c % 16]);
}

void	print_line(unsigned char *tab, int beg, int max)
{
	int		i;
	int		end;

	end = beg + 16;
	i = beg;
	while (i < end && i < max)
	{
		print_hex(tab[i]);
		if (i % 2)
			pc(' ');
		i++;
	}
	while (i < end)
	{
		pc(' ');
		pc(' ');
		if (i % 2)
			pc(' ');
		i++;
	}
	pc('\n');
	if (!((i - HEADER_SIZE) % 80))
		pc('\n');
}

void	print_header_large(void *ptr)
{
	struct s_header	*header;
	int				n;
	int				pages;
	int				size;

	header = ptr;
	size = header->size_of_chunks;
	pages = header->pages;
	n = -1;
	b_printf("-----------------------------------------------------------\n");
	b_printf("                     %s***  Header  ***%s\n", YELLOW, NO_COLOR);
	b_printf("%sNext:%s %s\n", YELLOW, NO_COLOR, (header->next) ? "Yes" : "No");
	b_printf("%sSize:%s %d\n", YELLOW, NO_COLOR, size);
	b_printf("\n%sPages:%s %d", YELLOW, NO_COLOR, pages);
	b_printf("\t\t%sSpace left:%s %d\n", YELLOW, NO_COLOR, SPACE_LEFT);
	b_printf("------------------------------------------------------------\n");
}

void	print_header(void *ptr)
{
	struct s_header	*header;
	int				n;

	n = -1;
	header = ptr;
	b_printf("------------------------------------------------------------\n");
	b_printf("                     %s***  Header  ***%s\n", YELLOW, NO_COLOR);
	b_printf("%sNext:%s %s\n", YELLOW, NO_COLOR, (header->next) ? "Yes" : "No");
	b_printf("%sSize:%s %d\t%sPages:%s %d\n\n",
	YELLOW, NO_COLOR, header->size_of_chunks, YELLOW, NO_COLOR, header->pages);
	while (++n < NUMBER_OF_CHUNKS)
	{
		b_printf("%s%d: %d%s", (IS_FREE) ? RED : GREEN, (n + 1),
		IS_FREE, NO_COLOR);
		b_printf("%s|%s%d%s|%s", YELLOW, (IS_FREE) ? NO_COLOR : BLACK,
		UNITS_ALLOC, YELLOW, NO_COLOR);
		b_printf(" ");
		if (!((n + 1) % 10))
			b_printf("\n");
	}
	b_printf("------------------------------------------------------------\n");
}
