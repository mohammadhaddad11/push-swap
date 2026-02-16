/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:45:18 by mhaddad           #+#    #+#             */
/*   Updated: 2025/12/27 09:07:23 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	s += slen;
	if ((char) c == '\0')
		return ((char *) s);
	while (slen != 0)
	{
		if (*s == (char) c)
			return ((char *) s);
		s--;
		slen--;
	}
	if (*s == (char) c)
		return ((char *)s);
	return (NULL);
}
