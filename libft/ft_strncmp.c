/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:28:22 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/24 12:39:41 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n != 0 && *s1 == *s2)
	{
		n--;
		s1++;
		s2++;
	}
	if (n == 0)
	{
		return (0);
	}
	return ((unsigned char ) *s1 - (unsigned char ) *s2);
}
