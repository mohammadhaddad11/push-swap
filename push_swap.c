/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:24:41 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/16 17:19:40 by mhaddad          ###   ########.fr       */
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
	return ((float)mistakes / total_pairs);
}

/* void	disorder_check(t_stack *a, t_stack *b)
{
	float	disorder;

	disorder = disorder_calc(a);
	if (disorder < 0.2)
		simple_sort(a, b);
	else if (disorder >= 0.5)
		radix_sort(a, b);
	else
		chunk_sort(a, b);
} */


void	sort_controller(t_stack	*a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		tiny_sort(a);
	else if (a->size > 3)
		selection_sort(a, b);
	/*else if (a->size > 5)
		disorder_check(a, b);
	else
	{
		error_exit();
	} */
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (1);
	init_stack(a, b);
	if (argc < 2)
		return (0);
	build(argc, argv, a, b);
	node_index(a);
	if (!is_sorted(a))
		sort_controller(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
