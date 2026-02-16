/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:27:13 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/27 14:58:52 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ps;
	unsigned char		*pd;

	if (!dest && !src)
		return (NULL);
	ps = (const unsigned char *) src;
	pd = (unsigned char *) dest;
	while (n > 0)
	{
		*pd = *ps;
		pd++;
		ps++;
		n--;
	}
	return (dest);
}
