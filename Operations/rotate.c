/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:36:46 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/15 13:52:45 by mhaddad          ###   ########.fr       */
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

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
