/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:31:19 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 02:02:38 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		dup_checker(a, b, numbers, value);
		new = new_node(value);
		if (!new)
			error_exit(a, b, numbers);
		stack_add_back(a, new);
		j++;
	}
	free_numbers(numbers);
}

static int	is_flag(char *arg)
{
	if (!ft_strcmp(arg, "--bench") || !ft_strcmp(arg, "--adaptive")
		|| !ft_strcmp(arg, "--simple") || !ft_strcmp(arg, "--medium")
		|| !ft_strcmp(arg, "--complex"))
		return (1);
	return (0);
}

static void	parse_numbers(char **argv, t_stack *a, t_stack *b, int *has_numbers)
{
	int		i;
	char	**numbers;

	i = 1;
	while (argv[i])
	{
		if (is_flag(argv[i]))
		{
			i++;
			continue ;
		}
		numbers = ft_split(argv[i], ' ');
		stack_build(a, b, numbers);
		*has_numbers = 1;
		i++;
	}
}

void	build(char **argv, t_stack *a, t_stack *b, t_bench *mode)
{
	float	initial_disorder;
	int		has_numbers;

	has_numbers = 0;
	parse_numbers(argv, a, b, &has_numbers);
	if (!has_numbers)
		error_exit(a, b, NULL);
	initial_disorder = disorder_calc(a);
	if ((mode->mode == 0 || mode->mode == 1) && initial_disorder < 0.2f)
		mode->adaptive_mode = 1;
	else if ((mode->mode == 0 || mode->mode == 1) && initial_disorder < 0.5f)
		mode->adaptive_mode = 2;
	else if (mode->mode == 0 || mode->mode == 1)
		mode->adaptive_mode = 3;
	node_index(a);
	if (!is_sorted(a))
		sort_controller(a, b, mode);
	if (mode->bench_mode == 1)
		bench(initial_disorder, mode);
}
