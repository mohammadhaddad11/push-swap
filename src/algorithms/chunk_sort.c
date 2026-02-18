/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 04:02:38 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 04:02:38 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	r;

	r = 1;
	while (r * r < n)
		r++;
	return (r);
}

static void	push_biggest_back(t_stack *a, t_stack *b, t_bench *op, int max_idx)
{
	while (b->top && b->top->index != max_idx)
	{
		if (node_counter(b->top, max_idx) <= (b->size + 1) / 2)
			rb(b, op);
		else
			rrb(b, op);
	}
	pa(b, a, op);
}

static int	push_in_chunk(t_stack *a, t_stack *b, t_bench *op, int *limits)
{
	if (a->top->index <= limits[0])
	{
		pb(a, b, op);
		rb(b, op);
		return (1);
	}
	if (a->top->index <= limits[0] + limits[1])
	{
		pb(a, b, op);
		return (1);
	}
	ra(a, op);
	return (0);
}

void	chunk_sort(t_stack *a, t_stack *b, t_bench *op)
{
	int	total;
	int	chunk_size;
	int	next_idx;
	int	current_max;
	int	limits[2];

	total = (int)a->size;
	chunk_size = (total / int_sqrt(total)) + 1;
	next_idx = 0;
	limits[1] = chunk_size;
	while (a->size > 0)
	{
		limits[0] = next_idx;
		if (push_in_chunk(a, b, op, limits))
			next_idx++;
	}
	current_max = total - 1;
	while (b->size > 0)
		push_biggest_back(a, b, op, current_max--);
}
