/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselfrie <asem.elfrieh1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:30:15 by aselfrie          #+#    #+#             */
/*   Updated: 2026/02/14 10:42:43 by aselfrie         ###   ########.fr       */
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
