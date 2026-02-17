/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:24:41 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/17 18:01:33 by mhaddad          ###   ########.fr       */
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

/* void	disorder_check(t_stack *a, t_stack *b, t_bench *mode)
{
	float	disorder;

	disorder = disorder_calc(a);
	if (disorder < 0.2)
		mode->adaptive_mode = 1;
		simple_sort(a, b);
	else if (disorder >= 0.5)
		mode->adaptive_mode = 3;
		radix_sort(a, b);
	else
		mode->adaptive_mode = 2;
		chunk_sort(a, b);
} */


void	sort_controller(t_stack	*a, t_stack *b, t_bench *mode)
{
	if (mode->mode == 2)
		selection_sort(a, b, mode);
	else if (mode->mode == 3)
		chunk_sort(a, b, mode);
	else if (mode->mode == 4)
		radix_sort(a, b, mode);
	else
	{
		if (a->size == 2)
			sa(a, mode);
		else if (a->size == 3)
			tiny_sort(a, mode);
		else if (a->size > 3)
			selection_sort(a, b, mode);
		/*else if (a->size > 5)
			disorder_check(a, b);
		else
		{
			error_exit();
		} */
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	*mode;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	mode = calloc(1, sizeof(t_bench));
	if (!a || !b || !mode)
		return (1);
	init_stack(a, b);
	if (argc < 2)
	{
		free(a);
		free(b);
		free(mode);
		return (0);
	}
	parse_flags(argv, mode);
	build(argc, argv, a, b, mode);
	node_index(a);
	if (!is_sorted(a))
		sort_controller(a, b, mode);
	free_stack(a,b);
	free(mode);
	return (0);
}
