/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:27:28 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/03 17:03:42 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include "get_next_line.h"

void	ft_strdel(char **as);
size_t	ft_strlen(const char *s);
void	*ft_memset(void	*ptr, int value, int size);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strcat(char *dest, char *src);
char	*ft_strnew(size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize);
char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memccpy(void *restrict dst, const void *restrict src, \
	int c, size_t n);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);
char	**ft_strsplit(char const *s, char c);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_replace_word(char *stirng, char *old, char *new_w);

char	*ft_addchar(char	*string, char c);
int		b_printf(const char *restrict fmt, ...);
int		double_char_ptr_size(char **list);
#endif
