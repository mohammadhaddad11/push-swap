/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 03:31:00 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 03:31:00 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_adaptive_mode(float disorder, t_bench *mode)
{
	if (disorder < 0.2f)
		mode->adaptive_mode = 1;
	else if (disorder < 0.5f)
		mode->adaptive_mode = 2;
	else
		mode->adaptive_mode = 3;
}

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
	float	disorder;

	disorder = disorder_calc(a);
	set_adaptive_mode(disorder, mode);
	if (mode->adaptive_mode == 1)
		low_disorder_sort(a, b, mode);
	else if (mode->adaptive_mode == 2)
		chunk_sort(a, b, mode);
	else
		radix_sort(a, b, mode);
}
