/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:43:35 by betsabe           #+#    #+#             */
/*   Updated: 2024/01/27 12:51:29 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n < 0)
	{
		n = -n;
	}
	if (n > 9)
		len += ft_putunsigned (n / 10);
	c = (n % 10) + 48;
	len += ft_putchar (c);
	return (len);
}
