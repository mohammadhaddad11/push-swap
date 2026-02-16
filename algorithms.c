/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:38:37 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/16 09:54:23 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack *stack)
{
	int	x;
	int	y;
	int	z;

	x = stack->top->index;
	y = stack->top->next->index;
	z = stack->top->next->next->index;
	if (x < y && x < z && y > z)
	{
		sa(stack);
		ra(stack);
	}
	else if (x > y && x < z && y < z)
		sa(stack);
	else if (x < y && x > z && y > z)
		rra(stack);
	else if (x > y && x > z && y < z)
		ra(stack);
	else if (x > y && x > z && y > z)
	{
		ra(stack);
		sa(stack);
	}
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a->size != 3)
	{
		while (a->top->index != i)
		{
			if (node_counter(a->top, i) <= (a->size + 1) / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		i++;
	}
	tiny_sort(a);
	while (b->size != 0)
		pa(b, a);
}

void	chunk_sort()
{

}
void	radix_sort()
{

}
