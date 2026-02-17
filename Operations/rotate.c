/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:36:46 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/17 17:46:50 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*old_top;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	old_top = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	last->next = old_top;
	old_top->prev = last;
	old_top->next = NULL;
}

void	ra(t_stack *a, t_bench *op)
{
	rotate(a);
	op->ra++;
	op->total++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b, t_bench *op)
{
	rotate(b);
	op->rb++;
	op->total++;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, t_bench *op)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	op->rr++;
	op->total++;
}
