/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:04:21 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/24 17:29:15 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_rev(unsigned char *dest, const unsigned char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		dest[n] = src[n];
	}
}

static void	ft_fwd(unsigned char *dest, const unsigned char *src, size_t n)
{
	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (!dest && !src)
		return (NULL);
	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	if (pd > ps)
		ft_rev(pd, ps, n);
	else
		ft_fwd(pd, ps, n);
	return (dest);
}
