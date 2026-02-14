/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:20:24 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/14 15:48:04 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (!from || !from->top)
		return ;
	tmp = from->top;
	from->top = from->top->next;
	if (from->top)
		from->top->prev = NULL;
	tmp->next = to->top;
	tmp->prev = NULL;
	if (to->top)
		to->top->prev = tmp;
	to->top = tmp;
}

void	pa(t_stack *b, t_stack *a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
