/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:15:38 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/17 17:46:25 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top->next;
	stack->top->next = first->next;
	if (first->next)
		first->next->prev = stack->top;
	first->next = stack->top;
	stack->top->prev = first;
	first->prev = NULL;
	stack->top = first;
}

void	sa(t_stack *a, t_bench *op)
{
	swap(a);
	op->sa++;
	op->total++;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b, t_bench *op)
{
	swap(b);
	op->sb++;
	op->total++;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, t_bench *op)

{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	op->ss++;
	op->total++;
}
