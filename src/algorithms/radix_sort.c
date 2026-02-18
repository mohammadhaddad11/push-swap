/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 04:06:14 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 04:06:14 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(size_t size)
{
	int	max_bits;
	int	max_index;

	max_bits = 0;
	max_index = (int)size - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b, t_bench *op)
{
	int		bit;
	int		max_bits;
	size_t	i;
	size_t	round_size;

	max_bits = get_max_bits(a->size);
	bit = 0;
	while (bit < max_bits)
	{
		round_size = a->size;
		i = 0;
		while (i++ < round_size)
		{
			if (((a->top->index >> bit) & 1) == 1)
				ra(a, op);
			else
				pb(a, b, op);
		}
		while (b->size > 0)
			pa(b, a, op);
		bit++;
	}
}
