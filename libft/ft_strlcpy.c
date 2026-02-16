/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:53:38 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/24 12:29:59 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size == 0)
	{
		return (srclen);
	}
	while (size - 1 && *src)
	{
		*dst = *src;
		src++;
		dst++;
		size--;
	}
	*dst = '\0';
	return (srclen);
}
