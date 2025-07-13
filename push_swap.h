/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:03:18 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/13 19:57:52 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# ifndef BIT_SIZE
#  define BIT_SIZE 31
# endif

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_move
{
	int	a_idx;
	int	b_idx;
	int	total_ops;
}	t_move;

int		p_err(void);

int		is_valid(int ac, char **av);
int		is_signed_digit(char *s);
long	ft_atol(char *s);
int		is_new_digit(int *tab, int num, int sz);

t_stack	*in_stack(int ac, char **av);
t_node	*new_node(int value);
void	push_back(t_stack *stack, t_node *node);

void	free_stack(t_stack *stack);

int		is_sorted(t_stack *stack);

void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack *a);
int		get_max(t_stack *a);

void	sort_five(t_stack **a, t_stack **b);
int		find_min_index(t_stack *a);
void	rotate_top(t_stack *s, int idx, int f);

void	sort_large(t_stack **a, t_stack **b);
void	set_idx(t_stack *a);
int		find_max_index(t_stack *b);

void	op_sa(t_stack *a, int f);
void	op_ra(t_stack *a, int f);
void	op_rra(t_stack *a, int f);
void	op_pa(t_stack **a, t_stack **b);

void	op_sb(t_stack *b, int f);
void	op_rb(t_stack *b, int f);
void	op_rrb(t_stack *b, int f);
void	op_pb(t_stack **a, t_stack **b);

#endif
