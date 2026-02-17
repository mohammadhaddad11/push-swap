/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:53:15 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/17 14:50:17 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ft_formats(int fd, va_list args, const char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_print_char(fd, va_arg(args, int));
	else if (f == 's')
		len += ft_print_str(fd, va_arg(args, char *));
	else if (f == 'p')
		len += ft_print_ptr(fd, va_arg(args, unsigned long));
	else if (f == 'd' || f == 'i')
		len += ft_print_nbr(fd, va_arg(args, int));
	else if (f == 'u')
		len += ft_print_unsigned(fd, va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		len += ft_print_hex(fd, va_arg(args, unsigned int), f);
	else if (f == '%')
		len += ft_print_char(fd, '%');
	return (len);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
			if (str[i] == '%')
			{
				len += ft_formats(fd, args, str[i + 1]);
				i++;
			}
			else
			{
				len += ft_print_char(fd, str[i]);
			}
		i++;
	}
	va_end(args);
	return (len);
}

