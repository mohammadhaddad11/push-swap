/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:30:15 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/16 17:12:48 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_index(t_stack *stack)
{
	t_node	*current;
	t_node	*node_to_compare;
	int		i;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		i = 0;
		node_to_compare = stack->top;
		while (node_to_compare)
		{
			if (current->value > node_to_compare->value)
				i++;
			node_to_compare = node_to_compare->next;
		}
		current->index = i;
		current = current->next;
	}
}

size_t	node_counter(t_node *current, int i)
{
	size_t	counter;

	counter = 0;
	while (current->index != i)
	{
		counter++;
		current = current->next;
	}
	return (++counter);
}
