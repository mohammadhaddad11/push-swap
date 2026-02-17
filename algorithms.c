/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:38:37 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/17 18:01:09 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	(void)a;
	(void)b;
	(void)op;
}

void	radix_sort(t_stack *a, t_stack *b, t_bench *op)
{
	(void)a;
	(void)b;
	(void)op;
}
