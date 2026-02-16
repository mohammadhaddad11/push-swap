/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:14:35 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/24 12:28:01 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	j;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	j = 0;
	if (size <= dstlen)
	{
		return (size + srclen);
	}
	dst += dstlen;
	while (j < size - dstlen - 1 && *src)
	{
		*dst = *src;
		src++;
		dst++;
		j++;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
