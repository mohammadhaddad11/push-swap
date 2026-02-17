/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:27:18 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/17 18:00:35 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*mode_name(t_bench *bench)
{
	int	mode;

	mode = bench->mode;
	if (mode == 2)
		return ("simple / O(n2)");
	else if (mode == 3)
		return ("medium / O(n√n)");
	else if (mode == 4)
		return ("complex / O(n log n)");
	else
	{
		if (bench->adaptive_mode == 1)
			return ("Adaptive / O(n2)");
		else if (bench->adaptive_mode == 2)
			return ("Adaptive / O(n√n)");
		else if (bench->adaptive_mode == 3)
			return ("Adaptive / O(n log n)");
	}
	return ("unknown");

}

void	bench(float disorder, t_bench *mode)
{
	int	whole;
	int	frac;
	int	transform;

	transform = (int)(disorder * 10000);
	whole = transform / 100;
	frac = transform % 100;
	ft_dprintf(2, "[bench] disorder: %d.%02d%%\n", whole, frac);
	ft_dprintf(2, "[bench] strategy: %s\n", mode_name(mode));
	ft_dprintf(2, "[bench] total_ops: %d\n", mode->total);
	ft_dprintf(2, "[bench] sa: %d sb:%d ss:%d", mode->sa, mode->sb, mode->ss);
	ft_dprintf(2, "[bench] pa: %d pb:%d\n", mode->pa, mode->pb);
	ft_dprintf(2, "[bench] ra: %d rb: %d rr:", mode->ra, mode->rb, mode->rr);
	ft_dprintf(2, "[bench] rra: %d rrb: %d", mode->rra, mode->rrb, mode->rrr);
	ft_dprintf(2, "[bench] rrr: %d\n", mode->rrr);
}
