/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_char_ptr_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:50:33 by ncollie           #+#    #+#             */
/*   Updated: 2019/02/21 23:04:06 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** for  NULL terminated char **
** get the number of elemtns
*/

int		double_char_ptr_size(char **list)
{
	int n;

	n = -1;
	while (list && list[++n])
		;
	return (n);
}
