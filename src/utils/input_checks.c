/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:55:00 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 09:55:00 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num_checker(t_stack *a, t_stack *b, char **numbers, int j)
{
	int	i;

	i = 0;
	if (!numbers[j] || numbers[j][0] == '\0')
		error_exit(a, b, numbers);
	if (numbers[j][i] == '-' || numbers[j][i] == '+')
		i++;
	if (numbers[j][i] == '\0')
		error_exit(a, b, numbers);
	while (numbers[j][i])
	{
		if (!ft_isdigit(numbers[j][i]))
			error_exit(a, b, numbers);
		i++;
	}
}

void	dup_checker(t_stack *a, t_stack *b, char **numbers, int value)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->value == value)
			error_exit(a, b, numbers);
		current = current->next;
	}
}
