/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:58:01 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/16 16:46:10 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	ssize_t			index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t		size;
	t_node		*top;
	t_node		*tail;
}	t_stack;

typedef struct operation
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_operation;

/*main*/
/* int		disorder_calc(t_stack *a); */
void	disorder_check(t_stack *a, t_stack *b);
void	sort_controller(t_stack	*a, t_stack *b);
int		main(int argc, char **argv);

/*parse*/
/* int		parse_bench(char **argv);
int		parse_flags(char **argv); */

/*stack*/
t_node	*new_node(int val);
void	stack_add_back(t_stack *stack, t_node *node_to_add);
int		is_sorted(t_stack *a);
void	init_stack(t_stack *a, t_stack *b);
/*utils*/
size_t	node_counter(t_node *current, int i);

/* algo */
void	tiny_sort(t_stack *stack);
void	node_index(t_stack *stack);
void	selection_sort(t_stack *a, t_stack *b);

/* operations */
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);


#endif
