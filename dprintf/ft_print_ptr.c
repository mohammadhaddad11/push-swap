/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:59:31 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 01:28:49 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ft_putptr(int fd, unsigned long num)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = 0;
	if (num >= 16)
	{
		len += ft_putptr(fd, num / 16);
	}
	len += write(fd, &base[num % 16], 1);
	return (len);
}

int	ft_print_ptr(int fd, unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		return (write(fd, "(nil)", 5));
	}
	len += write(fd, "0x", 2);
	len += ft_putptr(fd, ptr);
	return (len);
}
