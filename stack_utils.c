/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:54:27 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/14 16:57:32 by mhaddad          ###   ########.fr       */
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

/* size_t	stack_size(t_stack *stack)
{
	t_node	*current;
	size_t	size;

	if (!stack)
		return (0);
	size = 0;
	current = stack->top;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
} */

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
