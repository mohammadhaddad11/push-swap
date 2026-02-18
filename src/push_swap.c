/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:24:41 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 01:33:11 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small(t_stack *a, t_stack *b, t_bench *mode)
{
	if (a->size < 2 || is_sorted(a))
		return ;
	if (a->size == 2)
		sa(a, mode);
	else if (a->size == 3)
		tiny_sort(a, mode);
	else
		selection_sort(a, b, mode);
}

void	sort_controller(t_stack	*a, t_stack *b, t_bench *mode)
{
	if (mode->mode == 2)
	{
		if (a->size <= 5)
			sort_small(a, b, mode);
		else
			selection_sort(a, b, mode);
	}
	else if (mode->mode == 3)
		chunk_sort(a, b, mode);
	else if (mode->mode == 4)
		radix_sort(a, b, mode);
	else
	{
		if (a->size <= 5)
			sort_small(a, b, mode);
		else
			disorder_check(a, b, mode);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	mode;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (1);
	ft_bzero(&mode, sizeof(t_bench));
	init_stack(a, b);
	if (argc < 2)
	{
		free(a);
		free(b);
		return (0);
	}
	parse_flags(argv, &mode);
	build(argv, a, b, &mode);
	free_stack(a, b);
	return (0);
}
