/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:01:26 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/18 01:28:22 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char ) *s1 - (unsigned char ) *s2);
}

static int	mode_flag(char *arg)
{
	if (!ft_strcmp(arg, "--adaptive"))
		return (1);
	if (!ft_strcmp(arg, "--simple"))
		return (2);
	if (!ft_strcmp(arg, "--medium"))
		return (3);
	if (!ft_strcmp(arg, "--complex"))
		return (4);
	return (0);
}

void	parse_flags(char **argv, t_bench *stage)
{
	int	i;
	int	parsed_mode;

	stage->mode = 0;
	stage->bench_mode = 0;
	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "--bench"))
			stage->bench_mode = 1;
		parsed_mode = mode_flag(argv[i]);
		if (parsed_mode != 0)
			stage->mode = parsed_mode;
		i++;
	}
}

void	error_exit(t_stack *a, t_stack *b, char **numbers)
{
	free_stack(a, b);
	free_numbers(numbers);
	write(2, "Error\n", 6);
	exit(1);
}
