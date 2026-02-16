/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:54:27 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/16 16:54:30 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = val;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);

}

void	stack_add_back(t_stack *stack, t_node *node_to_add)
{
	if (!stack || !node_to_add)
		return ;
	if (!stack->top)
	{
		stack->top = node_to_add;
		stack->tail = node_to_add;
	}
	else
	{
		stack->tail->next = node_to_add;
		node_to_add->prev = stack->tail;
		stack->tail = stack->tail->next;
	}
	stack->size++;
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	init_stack(t_stack *a, t_stack *b)
{
	a->size = 0;
	a->top = NULL;
	a->tail = NULL;
	b->size = 0;
	b->top = NULL;
	b->tail = NULL;
}

void	free_stack(t_stack *a, t_stack *b)
{
	int		i;
	t_node	*current;

	i = 0;
	current = a->top;
	while (i < a->size)
	{
		current = a->top;
		a->top = a->next;
		free(current);
	}
	free(a);
	free(b);
}
