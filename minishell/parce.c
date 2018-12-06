/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:30:20 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/04 20:24:20 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h> //printf

char    *move_to_next_word(char *str)
{
	while (*str == 9 || *str == 11 || *str == 32)
		str++;
	return (str);
}

char    *move_to_char_after_end_of_word(char *str)
{
	//add case for " " or ' '
	if (*str == '"')
	{
		str++;
		while (*str && *str != '"') 
			str++;
		str++;
	}
	else
	{
		while (*str && *str != 9 && *str != 11 && *str != 32)
			str++;
	}
	return (str);
}

int        word_length(char *str)
{
	int n;

	n = 0;
	if (*str == '"')
	{
		n++;
		str++;
		while (*str && *str != '"' ) 
		{
			n++;
			str++;
		}
		str++;
		return (++n);
	}
	else
	{
		while (*str && *str != 9 && *str != 11 && *str != 32)
		{
			n++;
			str++;
		}
	 }
	return (n);
}

int        count_words(char *str)
{
	int n;

	n = 0;
	str = move_to_next_word(str);
	while (*str)
	{
		n++;
		str = move_to_char_after_end_of_word(str);
		str = move_to_next_word(str);
	}
	return (n);
}

int		regular(char *str)
{
	int n;

	n = 0;
	while (*str && *str != 9 && *str != 11 && *str != 32)
		n++;
	return (n);
}

char    **parse_words(char *str)
{
	char    **words;
	int        words_nb;
	int        i;
	int        j;
	int        word_len;

	if (!str)
		return (NULL);
	words_nb = count_words(str);
	words = (char**)malloc(sizeof(char*) * (words_nb + 1));
	words[words_nb] = NULL;
	str = move_to_next_word(str);
	i = -1;
	while (++i < words_nb)
	{
		word_len = word_length(str);
		words[i] = (char*)malloc(sizeof(char) * (word_len + 1));
		j = -1;
		while (++j < word_len)			//ft_strncpy(words[i], str, word_len)
			words[i][j] = str[j];
		words[i][word_len] = 0;
		str = move_to_char_after_end_of_word(str);
		str = move_to_next_word(str);
	}
	//for_each_element_char_ss(words, &replace_string);
	return (words);
}
