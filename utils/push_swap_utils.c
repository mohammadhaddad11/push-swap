/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:31:19 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/17 17:59:12 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_numbers(char **numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

static void	stack_build(t_stack *a, t_stack *b, char **numbers)
{
	int		j;
	long	value;
	t_node	*new;

	if (!numbers)
		error_exit(a, b, numbers);
	j = 0;
	while (numbers[j])
	{
		num_checker(a, b, numbers, j);
		value = ft_atoi(numbers[j]);
		if (value > INT_MAX || value < INT_MIN)
			error_exit(a, b, numbers);
		new = new_node(value);
		if (!new)
			error_exit(a, b, numbers);
		dup_checker(a, b, numbers, value);
		stack_add_back(a, new);
		j++;
	}
	free_numbers(numbers);
}

void	build(int argc, char **argv, t_stack *a, t_stack *b, t_bench *mode)
{
	int		i;
	char	**numbers;

	i = 1;
	i += ft_offset(argv, mode);
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		stack_build(a, b, numbers);
		i++;
	}
}

void	num_checker(t_stack *a, t_stack *b, char **numbers, int j)
{
	int	i;

	i = 0;
	if (numbers[j][i] == '-' || numbers[j][i] == '+')
		i++;
	while (numbers[j][i])
	{
		if (!ft_isdigit(numbers[j][i]) && numbers[j][i] != ' ')
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



