/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:25:10 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/18 01:27:56 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	reverse_rotate(t_stack *stack)
{
	t_node	*old_last;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	old_last = last;
	last = last->prev;
	last->next = NULL;
	stack->top->prev = old_last;
	old_last->next = stack->top;
	old_last->prev = NULL;
	stack->top = old_last;
}

void	rra(t_stack *a, t_bench *op)
{
	reverse_rotate(a);
	op->rra++;
	op->total++;
	if (op->bench_mode == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, t_bench *op)
{
	reverse_rotate(b);
	op->rrb++;
	op->total++;
	if (op->bench_mode == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, t_bench *op)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (op->bench_mode == 0)
		write(1, "rrr\n", 4);
	op->rrr++;
	op->total++;
}
