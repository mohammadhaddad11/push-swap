/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:54:27 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/12 17:00:13 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_new(){}
void	stack_size(){}
int	is_sorted(t_stack **a)
{
	if(disorder_calc(a) == 0.0)
	{
		return (1);
	}
	return (0);
}
void	free_stack(){}