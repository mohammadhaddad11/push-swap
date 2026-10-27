/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 03:31:00 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 16:05:12 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_calc(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_node	*current;
	t_node	*compare;

	current = a->top;
	mistakes = 0;
	total_pairs = 0;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs += 1;
			if (current->value > compare->value)
				mistakes += 1;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / total_pairs);
}

void	disorder_check(t_stack *a, t_stack *b, t_bench *mode)
{
	if (mode->adaptive_mode == 1)
		selection_sort(a, b, mode);
	else if (mode->adaptive_mode == 2)
		chunk_sort(a, b, mode);
	else
		radix_sort(a, b, mode);
}
