/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:15:41 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 09:15:49 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	root_of(int x)
{
	int	i;

	i = 1;
	while (i * i < x)
		i++;
	return (i);
}

void	push_to_b(t_stack *a, t_stack *b, t_bench *op, int chunk_range)
{
	int	i;
	int	current;

	current = chunk_range - 1;
	while (a->size != 0)
	{
		i = 0;
		while (i <= current && a->size != 0)
		{
			if (a->top->index <= current)
				pb(a, b, op);
			else
				ra(a, op);
			i++;
		}
		current += chunk_range;
	}
}

void	push_to_a(t_stack *b, t_stack *a, t_bench *op)
{
	int	i;

	i = b->size - 1;
	while (b->size != 0)
	{
		while (b->top->index != i)
		{
			if (node_counter(b->top, i) <= (b->size + 1) / 2)
				rb(b, op);
			else
				rrb(b, op);
		}
		pa(b, a, op);
		i--;
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_bench *op)
{
	int	chunk_range;

	chunk_range = root_of(a->size);
	push_to_b(a, b, op, chunk_range);
	push_to_a(b, a, op);
}
