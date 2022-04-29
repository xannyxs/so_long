/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 15:09:25 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 18:55:35 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *str);

void				ft_bzero(void *str, size_t n);

void				*ft_calloc(size_t nitems, size_t n);

int					ft_isalnum(int argc);

int					ft_isalpha(int argc);

int					ft_isascii(int argc);

int					ft_isdigit(int argc);

int					ft_isprint(int argc);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memchr(const void *str, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t len);

void				*ft_memset(void *str, int c, size_t len);

char				*ft_strchr(const char *str, int c);

char				*ft_strrchr(const char *str, int c);

char				*ft_strdup(const char *s1);

size_t				ft_strlcpy(char *dest, const char *src, size_t n);

size_t				ft_strlen(char const *str);

int					ft_strncmp(const char *str1, const char *str2, size_t n);

int					ft_strcmp(const char *str1, const char *str2);

int					ft_tolower(int argc);

int					ft_toupper(int argc);

char				*ft_strjoin_free(char *str1, char *str2);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

size_t				ft_strlcat(char *dest, const char *src, size_t n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

char				**ft_split(char const *s, char c);

char				*ft_substr(char const *str, unsigned int start, size_t len);

size_t				ft_countwords(const char *str, int c);

char				*ft_itoa(int n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t				ft_strlcat(char *dest, const char *src, size_t n);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

void				ft_free_array(char **str);

#endif
