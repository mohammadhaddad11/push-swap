/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:24:41 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/14 10:37:15 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	disorder_calc(t_stack **a)
{
	float	disorder;
	int		variance;
	int		size;
	int		i;

	disorder = 0.0;
	size = stack_size(a);
	variance = 0;
	i = 0;
	while (i < size)
	{
		if (a > a++)
			variance++;			
		i++;
	}
	disorder = variance / size;
	return (disorder);
}

void	disorder_check(t_stack **a, t_stack **b)
{
	float	disorder;
	
	disorder = disorder_calc(a);
	if (disorder < 0.2)
		simple_sort(a, b);
	else if (disorder >= 0.5)
		radix_sort(a, b);
	else
		chunk_sort(a, b);
}

int	build(int argc, char **argv, t_stack **a)
{
	char	**numbers;
	
	if (argc == 2)
	{
		
	}
}

void	sort_controller(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		tiny_sort(a);	
	else if (size == 4 || size == 5)
		selection_sort(a);
	else
		disorder_check(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (build(argc, argv, &a) == 1)
		return (1);
	if (!is_sorted(a))
		sort_controller(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
