/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:08:38 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/30 17:43:08 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	*ft_bzero(void *str, size_t co);
int		ft_isalnum(int a);
int		ft_isalpha(int a);
int		ft_isascii(int a);
int		ft_isdigit(int a);
int		ft_isprint(int a);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t byt);
void	*ft_memset(void *str, int ch, size_t co);
char	*ft_strchr(const char *str, int chr);
int		ft_strlcat(char *dest, const char *src, size_t s);
int		ft_strlcpy(char *dest, const char *src, size_t s);
size_t	ft_strlen(char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t nr);
char	*ft_strnstr(const char *str1, const char *str2, size_t n);
char	*ft_strrchr(const char *str, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
