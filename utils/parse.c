/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:01:26 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/16 17:17:47 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	parse_flags(char **argv)
{
	int	mode;
	int	bench_mode;

	bench_mode = 0;
	if (argv[1] == "--bench")
		bench_mode = 1;
	mode = 1;
	if (!ft_strcmp(argv[1], "--adaptive")
		|| !ft_strcmp(argv[2], "--adaptive" ))
		mode = 2;
	else if (!ft_strcmp(argv[1], "--simple")
		|| !ft_strcmp(argv[2], "--simple" ))
		mode = 3;
	else if (!ft_strcmp(argv[1], "--medium")
		|| !ft_strcmp(argv[2], "--medium" ))
		mode = 4;
	else if (!ft_strcmp(argv[1],"--complex")
		|| !ft_strcmp(argv[2], "--complex" ))
		mode = 5;

	if (bench_mode)
		mode = -mode;
	return (mode);
}

void	error_exit(t_stack *a, t_stack *b, char **numbers)
{
	free_stack(a);
	free_stack(b);
	free(numbers);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_offset(char **argv)
{
	int	mode;
	int	offset;

	mode = parse_flags(argv);
	offset = 0;
	if (mode < -1)
		offset = 2;
	else if (mode > 1 || mode == -1)
		offset = 1;
	return (offset);
}