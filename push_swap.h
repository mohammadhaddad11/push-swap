/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:58:01 by mhaddad           #+#    #+#             */
/*   Updated: 2026/02/17 18:02:38 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "dprintf/ft_dprintf.h"

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

typedef struct bench
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
	int	mode;
	int	adaptive_mode;
	int	bench_mode;
	int	total;
}	t_bench;

/*main*/
float	disorder_calc(t_stack *a);
void	disorder_check(t_stack *a, t_stack *b, t_bench *mode);
void	sort_controller(t_stack	*a, t_stack *b, t_bench *mode);
int		main(int argc, char **argv);

/*parse*/
void	parse_flags(char **argv, t_bench *Stage);
int		ft_offset(char **argv, t_bench *mode);
/*stack*/
t_node	*new_node(int val);
void	stack_add_back(t_stack *stack, t_node *node_to_add);
int		is_sorted(t_stack *a);
void	init_stack(t_stack *a, t_stack *b);
void	free_stack(t_stack *a, t_stack *b);
/*utils*/
size_t	node_counter(t_node *current, int i);
void	build(int argc, char **argv, t_stack *a, t_stack *b, t_bench *mode);
int		ft_strcmp(const char *s1, const char *s2);
void	num_checker(t_stack *a, t_stack *b, char **numbers, int j);
void	dup_checker(t_stack *a, t_stack *b, char **numbers, int value);
void	free_numbers(char **numbers);
void	error_exit(t_stack *a, t_stack *b, char **numbers);



/* algo */
void	tiny_sort(t_stack *stack, t_bench *op);
void	node_index(t_stack *stack);
void	low_disorder_sort(t_stack *a, t_stack *b, t_bench *op);
void	selection_sort(t_stack *a, t_stack *b, t_bench *op);
void	chunk_sort(t_stack *a, t_stack *b, t_bench *op);
void	radix_sort(t_stack *a, t_stack *b, t_bench *op);

/* operations */
void	pa(t_stack *b, t_stack *a, t_bench *op);
void	pb(t_stack *a, t_stack *b, t_bench *op);
void	rra(t_stack *a, t_bench *op);
void	rrb(t_stack *b, t_bench *op);
void	rrr(t_stack *a, t_stack *b, t_bench *op);
void	ra(t_stack *a, t_bench *op);
void	rb(t_stack *b, t_bench *op);
void	rr(t_stack *a, t_stack *b, t_bench *op);
void	sa(t_stack *a, t_bench *op);
void	sb(t_stack *b, t_bench *op);
void	ss(t_stack *a, t_stack *b, t_bench *op);

/*bench*/
void	bench(float disorder, t_bench *mode);

#endif
