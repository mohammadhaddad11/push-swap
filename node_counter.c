/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:16:50 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/16 09:15:25 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	node_counter(t_node *current, int i)
{
	size_t	counter;

	counter = 0;
	while (current->index != i)
	{
		counter++;
		current = current->next;
	}
	return (++counter);
}
