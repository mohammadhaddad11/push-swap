/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:27:18 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 01:27:25 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*mode_name(t_bench *bench)
{
	int	mode;

	mode = bench->mode;
	if (mode == 2)
		return ("simple / O(n^2)");
	else if (mode == 3)
		return ("medium / O(n*sqrt(n))");
	else if (mode == 4)
		return ("complex / O(n log n)");
	if (bench->adaptive_mode == 1)
		return ("adaptive / O(n)");
	else if (bench->adaptive_mode == 2)
		return ("adaptive / O(n*sqrt(n))");
	else if (bench->adaptive_mode == 3)
		return ("adaptive / O(n log n)");
	return ("adaptive / O(n)");
}

void	bench(float disorder, t_bench *mode)
{
	int	whole;
	int	frac;
	int	transform;

	transform = (int)(disorder * 10000);
	whole = transform / 100;
	frac = transform % 100;
	ft_dprintf(2, "[bench] disorder: %d.", whole);
	if (frac < 10)
		ft_dprintf(2, "0");
	ft_dprintf(2, "%d%%\n", frac);
	ft_dprintf(2, "[bench] strategy: %s\n", mode_name(mode));
	ft_dprintf(2, "[bench] total_ops: %d\n", mode->total);
	ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d ",
		mode->sa, mode->sb, mode->ss);
	ft_dprintf(2, "pa: %d pb: %d\n", mode->pa, mode->pb);
	ft_dprintf(2, "[bench] ra: %d rb: %d rr: %d ",
		mode->ra, mode->rb, mode->rr);
	ft_dprintf(2, "rra: %d rrb: %d rrr: %d\n", mode->rra, mode->rrb, mode->rrr);
}
