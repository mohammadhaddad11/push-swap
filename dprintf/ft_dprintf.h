/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:47:43 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/17 14:51:51 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_dprintf(int fd, const char *str, ...);

int	ft_print_char(int fd, char c);
int	ft_print_str(int fd, char *str);
int	ft_print_nbr(int fd, int n);
int	ft_print_unsigned(int fd, unsigned int n);

int	ft_print_hex(int fd, unsigned int n, const char format);
int	ft_print_ptr(int fd, unsigned long n);
#endif
