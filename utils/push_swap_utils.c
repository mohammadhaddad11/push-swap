/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:31:19 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 01:27:30 by mhaddad          ###   ########.fr       */
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

	if (!numbers || !numbers[0])
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
	float	initial_disorder;

	i = 1;
	i += ft_offset(argv, mode);
	if (i >= argc)
		error_exit(a, b, NULL);
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		stack_build(a, b, numbers);
		i++;
	}
	initial_disorder = disorder_calc(a);
	if (mode->mode == 0 || mode->mode == 1)
	{
		if (initial_disorder < 0.2f)
			mode->adaptive_mode = 1;
		else if (initial_disorder < 0.5f)
			mode->adaptive_mode = 2;
		else
			mode->adaptive_mode = 3;
	}
	node_index(a);
	if (!is_sorted(a))
		sort_controller(a, b, mode);
	if (mode->bench_mode == 1)
		bench(initial_disorder, mode);
}

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


