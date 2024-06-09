/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:48:33 by beiglesi          #+#    #+#             */
/*   Updated: 2024/03/12 08:52:44 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_puthex(unsigned long n, char format);
int		ft_putaddress(unsigned long ptr);
int		ft_format(va_list args, char format);
int		ft_putunsigned(unsigned int n);
int		ft_printf(char *str, ...);
int		ft_strlen( char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_strchr(char *s, int c);
char	*ft_gnljoin(char *s1, char *s2);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_strlcat(char *dst, char *src, int dstsize);
char	*get_next_line(int fd);

#endif 