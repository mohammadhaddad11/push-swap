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

void	parse_flags(char **argv, t_bench *Stage)
{
	char	*arg1;
	char	*arg2;

	arg1 = argv[1];
	arg2 = argv[2];
	Stage->mode = 0;
	Stage->bench_mode = 0;
	if (arg1 && !ft_strcmp(arg1, "--bench"))
		Stage->bench_mode = 1;
	if ((arg1 && !ft_strcmp(arg1, "--adaptive"))
		|| (arg2 && !ft_strcmp(arg2, "--adaptive")))
		Stage->mode = 1;
	else if ((arg1 && !ft_strcmp(arg1, "--simple"))
		|| (arg2 && !ft_strcmp(arg2, "--simple")))
		Stage->mode = 2;
	else if ((arg1 && !ft_strcmp(arg1, "--medium"))
		|| (arg2 && !ft_strcmp(arg2, "--medium")))
		Stage->mode = 3;
	else if ((arg1 && !ft_strcmp(arg1, "--complex"))
		|| (arg2 && !ft_strcmp(arg2, "--complex")))
		Stage->mode = 4;
}

void	error_exit(t_stack *a, t_stack *b, char **numbers)
{
	free_stack(a, b);
	free_numbers(numbers);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_offset(t_bench *Stage)
{
	int	offset;

	offset = 0;
	if (Stage->bench_mode == 1)
		offset++;
	if (Stage->mode > 0)
		offset++;
	return (offset);
}
