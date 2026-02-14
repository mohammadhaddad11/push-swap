/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:38:37 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/14 17:30:20 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack *stack)
{
	if (stack->top->index == 0 && stack->top->next->index == 2)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->top->index == 1 && stack->top->next->index == 0)
		sa(stack);
	else if (stack->top->index == 1 && stack->top->next->index == 2)
		rra(stack);
	else if (stack->top->index == 2 && stack->top->next->index == 0)
		ra(stack);
	else if (stack->top->index == 2 && stack->top->next->index == 1)
	{
		ra(stack);
		sa(stack);
	}
}

void	short_sort()
{
	if
}
void	simple_sort(){}
void	chunk_sort(){}
void	radix_sort(){}
