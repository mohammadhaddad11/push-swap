/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:15:08 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/17 12:54:40 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_print_hex(int fd, unsigned int num, const char format)
{
	char	*base;
	int		len;

	len = 0;
	if (format == 'X')
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	if (num >= 16)
	{
		len += ft_print_hex(fd, num / 16, format);
	}
	len += write(fd, &base[num % 16], 1);
	return (len);
}
