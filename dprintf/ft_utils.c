/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:32:29 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/17 14:51:35 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"


int	ft_print_char(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	ft_print_str(int fd, char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
	{
		write(fd, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_print_nbr(int fd, int n)
{
	int		len;
	long	num;

	num = n;
	len = 0;
	if (num < 0)
	{
		len += ft_print_char(fd, '-');
		num = -num;
	}
	if (num >= 10)
		len += ft_print_nbr(fd, num / 10);
	len += ft_print_char(fd, (num % 10) + '0');
	return (len);
}

int	ft_print_unsigned(int fd, unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(fd, n / 10);
	len += ft_print_char(fd, (n % 10) + '0');
	return (len);
}
