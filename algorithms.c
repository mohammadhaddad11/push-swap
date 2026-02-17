/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:38:37 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/18 01:27:27 by mhaddad          ###   ########.fr       */
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

static void	push_biggest_back(t_stack *a, t_stack *b, t_bench *op, int max_index)
{
	while (b->top && b->top->index != max_index)
	{
		if (node_counter(b->top, max_index) <= (b->size + 1) / 2)
			rb(b, op);
		else
			rrb(b, op);
	}
	pa(b, a, op);
}

void	tiny_sort(t_stack *stack, t_bench *op)
{
	int	x;
	int	y;
	int	z;

	x = stack->top->index;
	y = stack->top->next->index;
	z = stack->top->next->next->index;
	if (x < y && x < z && y > z)
	{
		sa(stack, op);
		ra(stack, op);
	}
	else if (x > y && x < z && y < z)
		sa(stack, op);
	else if (x < y && x > z && y > z)
		rra(stack, op);
	else if (x > y && x > z && y < z)
		ra(stack, op);
	else if (x > y && x > z && y > z)
	{
		ra(stack, op);
		sa(stack, op);
	}
}

void	low_disorder_sort(t_stack *a, t_stack *b, t_bench *op)
{
	size_t	pass;

	pass = a->size;
	while (pass-- && !is_sorted(a))
	{
		if (a->top->next && a->top->index > a->top->next->index)
			sa(a, op);
		ra(a, op);
	}
	while (a->top && a->top->index != 0)
	{
		if (node_counter(a->top, 0) <= (a->size + 1) / 2)
			ra(a, op);
		else
			rra(a, op);
	}
	if (!is_sorted(a))
		chunk_sort(a, b, op);
}

void	selection_sort(t_stack *a, t_stack *b, t_bench *op)
{
	int	i;

	i = 0;
	while (a->size != 3)
	{
		while (a->top->index != i)
		{
			if (node_counter(a->top, i) <= (a->size + 1) / 2)
				ra(a, op);
			else
				rra(a, op);
		}
		pb(a, b, op);
		i++;
	}
	tiny_sort(a, op);
	while (b->size != 0)
		pa(b, a, op);
}

void	chunk_sort(t_stack *a, t_stack *b, t_bench *op)
{
	int	total;
	int	chunk_count;
	int	chunk_size;
	int	next_index;
	int	current_max;

	total = (int)a->size;
	chunk_count = int_sqrt(total);
	chunk_size = (total / chunk_count) + 1;
	next_index = 0;
	while (a->size > 0)
	{
		if (a->top->index <= next_index)
		{
			pb(a, b, op);
			rb(b, op);
			next_index++;
		}
		else if (a->top->index <= next_index + chunk_size)
		{
			pb(a, b, op);
			next_index++;
		}
		else
			ra(a, op);
	}
	current_max = total - 1;
	while (b->size > 0)
		push_biggest_back(a, b, op, current_max--);
}

void	radix_sort(t_stack *a, t_stack *b, t_bench *op)
{
	int		max_bits;
	int		max_index;
	int		bit;
	size_t	i;
	size_t	round_size;

	max_bits = 0;
	max_index = (int)a->size - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
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
