/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 04:06:14 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 09:19:40 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_stack *a)
{
	int		i;
	size_t	max_index;

	i = 0;
	if (a->size <= 1)
		return (0);
	max_index = a->size - 1;
	while (max_index != 0)
	{
		max_index /= 2;
		i++;
	}
	return (i);
}

void	radix_sort(t_stack *a, t_stack *b, t_bench *op)
{
	int	bits;
	int	i;
	int	j;

	i = 0;
	bits = max_bits(a);
	while (i < bits)
	{
		j = a->size;
		while (j)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b, op);
			else
				ra(a, op);
			j--;
		}
		while (b->size != 0)
			pa(b, a, op);
		if (is_sorted(a))
			break ;
		i++;
	}
}
