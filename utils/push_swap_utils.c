/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:31:19 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/16 17:20:07 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_build(t_stack *a, t_stack *b, char **numbers)
{
	int		j;
	long	value;
	t_node	*new;

	j = 0;
	while (numbers[j])
	{
		num_checker(a, b, numbers[j]);
		value = ft_atoi(numbers[j]);
		if (value > INT_MAX || value < INT_MIN)
			error_exit(a, b, numbers);
		new = new_node(value);
		if (!new)
			error_exit(a, b, numbers);
		dup_checker(a, b, numbers, value);
		stack_add_back(a, new);
		j++;
		free(numbers);
	}
}

void	build(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;
	char	**numbers;

	i = 1;
	i += parse_offset(argv);
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		stack_build(a, b, numbers);
		i++;
	}
}

void	num_checker(t_stack *a, t_stack *b, char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (!ft_isdigit(numbers[i]) && numbers[i] != ' ')
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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char ) *s1 - (unsigned char ) *s2);
}


