/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 21:12:17 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/06 21:26:12 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "structs.h"
# include <stdio.h>
# define NO_COLOR "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLACK "\033[0;90m"
# define HEADER_SIZE 120
# define PAGESIZE 4096
# define TINY_SIZE 80
# define SMALL_SIZE 400
# define SMALL_LIMIT 2000
# define NUMBER_OF_CHUNKS 100
# define PRIV MAP_PRIVATE | MAP_ANONYMOUS
# define PROT PROT_READ | PROT_WRITE
# define MMAP	mmap(NULL, pages * PAGESIZE, PROT, PRIV, -1, 0)
# define INDEX(x) ptr->header.list[(x)]
# define UNITS_ALLOC header->list[n].units
# define IS_FREE header->list[n].free

struct s_container container;
enum						e_size{tiny = 2, small = 10, large};
enum						e_bool{freed, allocated};

void						print_line(unsigned char *tab, int beg, int max);
void						print_header_large(void *ptr);
void						print_header(void *ptr);
void						print_mem(int a);

void						free(void *ptr);
int							get_index_position(struct s_block *ptr,
void *removing);

void						*realloc(void *ptr, size_t size);

void						*create_block(int pages, size_t size);
void						*malloc(size_t size);

void						set_allocated(struct s_block *ptr, int n,
int blocks);
int							check_if_can_expand(struct s_block *ptr,
int index, int new_chunks, int old_chunks);
void						make_allocated_smaller(struct s_block *ptr,
int n, int new_chunks, int old_chunks);
struct s_two_ptr_returns	locate_ptr_in_gobal(void *ptr);

void						show_alloc_mem(void);
#endif
